/*******************************************************************************

    Project Lightrus
    
    Copyright (C) 2009 Sergey Balyakin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    
*******************************************************************************/

#include <QtGui/QFileDialog>
#include <QMap>
#include <QString>
#include <QVariant>
#include "maindialog.h"
#include "ui_maindialog.h"
#include "infocollector.h"
#include "translator.h"
#include "constants.h"
#include <QDesktopServices>
#include <QUrl>
#include <QClipboard>
#include <QMessageBox>
#include <QPalette>

using namespace consts;

const QString texts_prev_button[] = {
    text_prev,   // page_start
    text_prev,   // page_parameters,
    text_prev,   // page_translation
    text_prev,   // page_not_translated
    text_prev }; // page_last

const QString texts_next_button[] = {
    text_next,     // page_start
    text_exec,     // page_parameters,
    text_next,     // page_translation
    text_next,     // page_not_translated
    text_finish }; // page_last

const bool is_enabled_prev_button[] = {
    false,  // page_start
    true,   // page_parameters,
    false,  // page_translation
    true,   // page_not_translated
    true }; // page_last

const bool is_enabled_next_button[] = {
    true,   // page_start
    false,  // page_parameters,
    false,  // page_translation
    true,   // page_not_translated
    true }; // page_last


MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::MainDialogClass)
{
    ui->setupUi(this);

    setAcceptDrops(true);

    connect(ui->push_button_next,    SIGNAL(clicked()), SLOT(ToNextPage()));
    connect(ui->push_button_prev,    SIGNAL(clicked()), SLOT(ToPrevPage()));
    connect(ui->push_button_browse,  SIGNAL(clicked()), SLOT(BrowseFolder()));
    connect(ui->push_button_copy,    SIGNAL(clicked()), SLOT(CopyMailTextToClipboard()));
    connect(ui->push_button_cancel,  SIGNAL(pressed()), SLOT(close()));

    connect(ui->stacked_widget, SIGNAL(currentChanged(int)), SLOT(OnPageActivated(int)));
    connect(ui->line_edit_path, SIGNAL(textChanged(const QString&)), SIGNAL(ChangeLightroomDirPath(const QString&)));

    if (ui->stacked_widget->currentIndex() != page_start)
        ui->stacked_widget->setCurrentIndex(page_start);
    else
        OnPageActivated(page_start);

    // Задаем платформенно-ориентированные тексты элементы интерфейса
    ui->label_path->setText                 (text_ui_label_path);
    ui->label_title_parameters->setText     (text_ui_label_title_parameters);
    ui->label_choose_languages->setText     (text_ui_label_choose_languages);
    ui->check_box_toggle_to_russian->setText(text_ui_check_box_toggle_to_russian);
    ui->label_welcome->setText              (text_ui_label_welcome_s.arg(application_version));
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::OnPageActivated(int page_index)
{
    ui->push_button_prev->setText(texts_prev_button[page_index]);
    ui->push_button_next->setText(texts_next_button[page_index]);
    ui->push_button_prev->setEnabled(is_enabled_prev_button[page_index]);
    ui->push_button_next->setEnabled(is_enabled_next_button[page_index]);

    //qApp->processEvents();
    switch (page_index)
    {
        case page_start          : PageStartActivated(); break;
        case page_parameters     : PageParametersActivated(); break;
        case page_translation    : PageTranslationActivated(); break;
        case page_not_translated : PageNotTranslatedActivated(); break;
        case page_last           : PageLastActivated(); break;
    }
}

void MainDialog::ChangeCurrentPage(int increment)
{
    int next_page_index = ui->stacked_widget->currentIndex() + increment;

    // Определяем необходимость отображения страницы с непереведенными фразами
    bool show_page_not_translated = true;
    emit IsPageNotTranslatedNeeded(show_page_not_translated);

    if (!show_page_not_translated && next_page_index == page_not_translated )
        ui->stacked_widget->setCurrentIndex(next_page_index + increment);
    else
        ui->stacked_widget->setCurrentIndex(next_page_index);
}

void MainDialog::ToNextPage()
{
    if (ui->stacked_widget->currentIndex() == page_last)
        FinishWork();
    else
        ChangeCurrentPage(+1);
}

void MainDialog::ToPrevPage()
{
    ChangeCurrentPage(-1);
}

void MainDialog::BrowseFolder()
{
#ifdef Q_WS_WIN
    QString path = QFileDialog::getExistingDirectory(this,
                                                     text_browse_dialog_title,
                                                     ui->line_edit_path->text(),
                                                     QFileDialog::ShowDirsOnly |
                                                     QFileDialog::DontResolveSymlinks |
                                                     QFileDialog::ReadOnly);
#endif

#ifdef Q_WS_MAC
    QString path = QFileDialog::getOpenFileName(this,
                                                text_browse_dialog_title,
                                                ui->line_edit_path->text(),
                                                consts::str_app_files_filter);

#endif

    if (!path.isEmpty())
        ui->line_edit_path->setText( QDir::convertSeparators(path) );
}

void MainDialog::PageStartActivated()
{
}

void MainDialog::PageParametersActivated()
{
    if (ui->line_edit_path->text().isEmpty())
        emit SetDefaultLightroomPath();
}

void MainDialog::PageTranslationActivated()
{
    emit Translate();

    ui->push_button_prev->setEnabled(true);
    ui->push_button_next->setEnabled(true);
}

void MainDialog::PageNotTranslatedActivated()
{
    emit CollectUnknownPhrases();
}

void MainDialog::PageLastActivated()
{
}

void MainDialog::TranslateAll()
{
    ui->text_edit_translating->clear();
    emit Translate();
}

void MainDialog::OnLogMessage(const QString& text)
{
    AddToLog(text, color_black);
}

void MainDialog::OnInfoMessage(const QString& text)
{
    AddToLog(text, color_blue);
}

void MainDialog::OnErrorMessage(const QString& text)
{
    AddToLog(text, color_red);
}

inline QString MainDialog::ConvertToHtml(const QString& text, QColor color)
{
    return text_convert_to_html_ss.arg(color.name(), text);
}

void MainDialog::AddToLog(const QString& text, QColor color)
{
    ui->text_edit_translating->moveCursor(QTextCursor::End);
    ui->text_edit_translating->insertHtml( ConvertToHtml(text, color) );
    ui->text_edit_translating->moveCursor(QTextCursor::End);
}

void MainDialog::CopyMailTextToClipboard()
{
    emit CopyToClipboard(ui->plain_text_edit_mail->toPlainText());
}

void MainDialog::closeEvent(QCloseEvent *event)
{
    // Если активна последняя страница то выходим без запросов
    if (ui->stacked_widget->currentIndex() == page_last)
    {
        event->accept();
        return;
    }

    // Выдаем запрос на подтверждение выхода
    QMessageBox message_box;
    message_box.setWindowTitle(text_close_warning_title);
    message_box.setText(text_close_warning_text);
    message_box.setIcon(QMessageBox::Question);
    QPushButton* yes_button = message_box.addButton(text_yes, QMessageBox::YesRole);
    yes_button->setDefault(true);
    message_box.addButton(text_no, QMessageBox::NoRole);
    message_box.exec();

    if (message_box.clickedButton() == yes_button)
        event->accept();
    else
        event->ignore();
}

void MainDialog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        event->accept();
        close();
    }
    else
    {
        event->ignore();
    }
}

void MainDialog::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if (mimeData->hasUrls())
    {
        QList<QUrl> urls = mimeData->urls();
        if (urls.count() > 0)
        {
            QString url = urls[0].toString(); // take the first url
            if (url.startsWith(text_file_prefix))
            {
                url.remove(0, text_file_prefix.length());
#ifdef Q_WS_WIN
                int index = url.lastIndexOf("/");
                if (index != -1)
                    url.remove(index, url.length() - index);
#endif
            }
            SetLightroomPath(url);
        }
    }
    event->acceptProposedAction();
}

void MainDialog::dragMoveEvent(QDragMoveEvent* event)
{
    if (event->mimeData()->hasUrls())
        event->accept();
}

void MainDialog::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void MainDialog::SetLightroomPath(const QString& path)
{
    ui->line_edit_path->setText(QDir::toNativeSeparators(path));
}

void MainDialog::SetIsValidLightroomPath(bool is_valid)
{
    QPalette palette = ui->line_edit_path->palette();
    if (is_valid)
        palette.setColor(QPalette::Text, color_black);
    else
        palette.setColor(QPalette::Text, color_red);

    ui->line_edit_path->setPalette(palette);
    ui->push_button_next->setEnabled(is_valid);
    ui->label_invalid_path->setText(is_valid ? "" : text_invalid_path);
}

QString MainDialog::GetLightroomPath()
{
    return ui->line_edit_path->text();
}

QString MainDialog::GetSelectedLanguageName()
{
    return ui->combo_box_languages->currentText();
}

bool MainDialog::IsNeedBackup()
{
    return ui->check_box_backup->isChecked();
}

bool MainDialog::IsNeedCopyEnglishHelpFiles()
{
    return ui->check_box_copy_english_help->isChecked();
}

void MainDialog::SetLanguagesNames(const QStringList& list)
{
    ui->combo_box_languages->clear();
    ui->combo_box_languages->insertItems(0, list);
}

void MainDialog::SetMailText(const QStringList& text)
{
    ui->plain_text_edit_mail->clear();
    foreach (QString str, text)
        ui->plain_text_edit_mail->insertPlainText( str + str_return );
}

void MainDialog::SetProgress(int value)
{
    ui->progress_bar_current->setValue(value);
}

void MainDialog::SetTranslatingFilename(const QString& file_name)
{
    ui->label_current_file->setText(file_name);
}

void MainDialog::FinishWork()
{
    if (ui->check_box_toggle_to_russian->isChecked())
        emit ToggleLanguageToSelected();

    if (ui->check_box_open_readme->isChecked())
        emit OpenReadmeFile();

    if (ui->check_box_exec_lightroom->isChecked())
        emit ExecLightroom();

    close();
}
