#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QWizard>

class Translator;

namespace Ui
{
    class MainDialogClass;
}

class MainDialog : public QDialog
{
    Q_OBJECT

signals:
    // Сигнал, оповещающий о старте процесса перевода
    void Translate();

    // Задает директорию установки Lightroom по умолчанию
    void SetDefaultLightroomPath();

    // Сигнал, оповещающий о изменении пользователем директории установки Lightroom
    void ChangeLightroomDirPath(const QString&);

    // Сигнал, оповещающий о необходимости формирования текста письма с неизвестными фразами
    void CollectUnknownPhrases();

    // Сигнал, оповещающий о необходимости показа readme-файла
    void OpenReadmeFile();

    // Сигнал, оповещающий о необходимости переключения языка в Lightroom на выбранный пользователем
    void ToggleLanguageToSelected();

    // Сигнал запуска Lightroom
    void ExecLightroom();

    // Сигнал определения необходимости отображения страницы с непереведенными фразама
    void IsPageNotTranslatedNeeded(bool&);

    // Сигнал копирования text в буфер обмена
    void CopyToClipboard(const QString& text);

public:
    enum WizardPages
    {
        page_start = 0,
        page_parameters,
        page_translation,
        page_not_translated,
        page_last
    };

    MainDialog(QWidget *parent = 0);
    ~MainDialog();

    // Задает директорию установки Lightroom
    void SetLightroomPath(const QString& path);
    void SetIsValidLightroomPath(bool is_valid);
    QString GetLightroomPath();
    QString GetSelectedLanguageName();
    bool IsNeedBackup();
    bool IsNeedCopyEnglishHelpFiles();
    void SetLanguagesNames(const QStringList& list);
    void SetMailText(const QStringList& text);
    void SetProgress(int value);
    void SetTranslatingFilename(const QString& file_name);


    void OnLogMessage(const QString& text);
    void OnInfoMessage(const QString& text);
    void OnErrorMessage(const QString& text);

protected:
    void closeEvent(QCloseEvent *event);

private Q_SLOTS:
    void ToNextPage(); // Переходит на следующую страницу
    void ToPrevPage(); // Переходит на предыдущую страницу
    void BrowseFolder(); // Открывает диалог выбора файла
    void OnPageActivated(int page_index);
    void CopyMailTextToClipboard();

private:
    Ui::MainDialogClass *ui;

    void PageStartActivated();
    void PageParametersActivated();
    void PageTranslationActivated();
    void PageNotTranslatedActivated();
    void PageLastActivated();

    void ChangeCurrentPage(int increment);
    void TranslateAll();
    QString ConvertToHtml(const QString& text, QColor color);
    void AddToLog(const QString& text, QColor color);
    void FinishWork();
};

#endif // MAINDIALOG_H
