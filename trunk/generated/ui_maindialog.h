/********************************************************************************
** Form generated from reading ui file 'maindialog.ui'
**
** Created: Mon May 25 21:50:30 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialogClass
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stacked_widget;
    QWidget *page_start;
    QGridLayout *gridLayout;
    QLabel *label_vertical_logo_start;
    QGridLayout *grid_layout_start_page;
    QLabel *label_welcome;
    QWidget *page_parameters;
    QGridLayout *gridLayout_4;
    QLabel *label_top_logo_parameters;
    QVBoxLayout *vertical_layout_parameters_page_1;
    QLabel *label_title_parameters;
    QSpacerItem *vertical_spacer_parameters_1;
    QLabel *label_path;
    QHBoxLayout *horizontal_layout_parameters_1;
    QLineEdit *line_edit_path;
    QPushButton *push_button_browse;
    QSpacerItem *vertical_spacer_parameters_2;
    QHBoxLayout *horizontal_layout_parameters_2;
    QVBoxLayout *vertical_layout_parameters_page_2;
    QLabel *label_choose_languages;
    QComboBox *combo_box_languages;
    QSpacerItem *vertical_spacer_parameters_3;
    QCheckBox *check_box_backup;
    QCheckBox *check_box_copy_english_help;
    QSpacerItem *horizontal_spacer_parameters;
    QWidget *page_translation;
    QGridLayout *gridLayout_5;
    QLabel *label_top_logo_translation;
    QVBoxLayout *vertical_layout_translation;
    QLabel *label_title_translation;
    QSpacerItem *vertical_spacer_translation_1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_current_file_title;
    QLabel *label_current_file;
    QProgressBar *progress_bar_current;
    QTextEdit *text_edit_translating;
    QSpacerItem *vertical_spacer_translation_2;
    QWidget *page_not_translated;
    QGridLayout *gridLayout_6;
    QLabel *label_top_logo_not_translated;
    QVBoxLayout *vertical_layout_not_translated;
    QLabel *label_title_not_translated;
    QSpacerItem *vertical_spacer_not_translated;
    QLabel *label_not_translated;
    QPlainTextEdit *plain_text_edit_mail;
    QPushButton *push_button_copy;
    QWidget *page_last;
    QGridLayout *gridLayout_7;
    QLabel *label_vertical_logo_last;
    QVBoxLayout *vertical_layout_last;
    QLabel *label_final;
    QSpacerItem *vertical_spacer_last_1;
    QCheckBox *check_box_open_readme;
    QCheckBox *check_box_toggle_to_russian;
    QCheckBox *check_box_exec_lightroom;
    QSpacerItem *vertical_spacer_last_2;
    QFrame *line_main;
    QHBoxLayout *horizontal_layout_bottom;
    QLabel *label_author;
    QSpacerItem *horizontal_spacer_bottom_1;
    QPushButton *push_button_prev;
    QPushButton *push_button_next;
    QSpacerItem *horizontal_spacer_bottom_2;
    QPushButton *push_button_cancel;

    void setupUi(QDialog *MainDialogClass)
    {
        if (MainDialogClass->objectName().isEmpty())
            MainDialogClass->setObjectName(QString::fromUtf8("MainDialogClass"));
        MainDialogClass->resize(500, 364);
        MainDialogClass->setMinimumSize(QSize(500, 364));
        MainDialogClass->setMaximumSize(QSize(50000, 364));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/res/images/app.ico")), QIcon::Normal, QIcon::Off);
        MainDialogClass->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(MainDialogClass);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setMargin(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stacked_widget = new QStackedWidget(MainDialogClass);
        stacked_widget->setObjectName(QString::fromUtf8("stacked_widget"));
        stacked_widget->setEnabled(true);
        stacked_widget->setMinimumSize(QSize(0, 312));
        stacked_widget->setMaximumSize(QSize(16777215, 312));
        stacked_widget->setAutoFillBackground(false);
        stacked_widget->setFrameShape(QFrame::NoFrame);
        stacked_widget->setFrameShadow(QFrame::Plain);
        stacked_widget->setLineWidth(0);
        page_start = new QWidget();
        page_start->setObjectName(QString::fromUtf8("page_start"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page_start->sizePolicy().hasHeightForWidth());
        page_start->setSizePolicy(sizePolicy);
        page_start->setMinimumSize(QSize(0, 312));
        page_start->setMaximumSize(QSize(16777215, 312));
        gridLayout = new QGridLayout(page_start);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        label_vertical_logo_start = new QLabel(page_start);
        label_vertical_logo_start->setObjectName(QString::fromUtf8("label_vertical_logo_start"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_vertical_logo_start->sizePolicy().hasHeightForWidth());
        label_vertical_logo_start->setSizePolicy(sizePolicy1);
        label_vertical_logo_start->setLineWidth(0);
        label_vertical_logo_start->setPixmap(QPixmap(QString::fromUtf8(":/res/images/side_logo.png")));
        label_vertical_logo_start->setScaledContents(false);
        label_vertical_logo_start->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_vertical_logo_start, 0, 0, 1, 1);

        grid_layout_start_page = new QGridLayout();
        grid_layout_start_page->setSpacing(6);
        grid_layout_start_page->setMargin(9);
        grid_layout_start_page->setObjectName(QString::fromUtf8("grid_layout_start_page"));
        label_welcome = new QLabel(page_start);
        label_welcome->setObjectName(QString::fromUtf8("label_welcome"));
        sizePolicy.setHeightForWidth(label_welcome->sizePolicy().hasHeightForWidth());
        label_welcome->setSizePolicy(sizePolicy);
        label_welcome->setMinimumSize(QSize(280, 0));
        label_welcome->setMaximumSize(QSize(16777215, 16777215));
        label_welcome->setLineWidth(0);
        label_welcome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_welcome->setWordWrap(true);

        grid_layout_start_page->addWidget(label_welcome, 0, 0, 1, 1);


        gridLayout->addLayout(grid_layout_start_page, 0, 1, 1, 1);

        stacked_widget->addWidget(page_start);
        page_parameters = new QWidget();
        page_parameters->setObjectName(QString::fromUtf8("page_parameters"));
        gridLayout_4 = new QGridLayout(page_parameters);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setMargin(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_top_logo_parameters = new QLabel(page_parameters);
        label_top_logo_parameters->setObjectName(QString::fromUtf8("label_top_logo_parameters"));
        sizePolicy1.setHeightForWidth(label_top_logo_parameters->sizePolicy().hasHeightForWidth());
        label_top_logo_parameters->setSizePolicy(sizePolicy1);
        label_top_logo_parameters->setPixmap(QPixmap(QString::fromUtf8(":/res/images/top_logo.png")));

        gridLayout_4->addWidget(label_top_logo_parameters, 0, 0, 1, 1);

        vertical_layout_parameters_page_1 = new QVBoxLayout();
        vertical_layout_parameters_page_1->setSpacing(6);
        vertical_layout_parameters_page_1->setMargin(9);
        vertical_layout_parameters_page_1->setObjectName(QString::fromUtf8("vertical_layout_parameters_page_1"));
        label_title_parameters = new QLabel(page_parameters);
        label_title_parameters->setObjectName(QString::fromUtf8("label_title_parameters"));
        label_title_parameters->setWordWrap(true);

        vertical_layout_parameters_page_1->addWidget(label_title_parameters);

        vertical_spacer_parameters_1 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Preferred);

        vertical_layout_parameters_page_1->addItem(vertical_spacer_parameters_1);

        label_path = new QLabel(page_parameters);
        label_path->setObjectName(QString::fromUtf8("label_path"));

        vertical_layout_parameters_page_1->addWidget(label_path);

        horizontal_layout_parameters_1 = new QHBoxLayout();
        horizontal_layout_parameters_1->setSpacing(6);
        horizontal_layout_parameters_1->setObjectName(QString::fromUtf8("horizontal_layout_parameters_1"));
        line_edit_path = new QLineEdit(page_parameters);
        line_edit_path->setObjectName(QString::fromUtf8("line_edit_path"));

        horizontal_layout_parameters_1->addWidget(line_edit_path);

        push_button_browse = new QPushButton(page_parameters);
        push_button_browse->setObjectName(QString::fromUtf8("push_button_browse"));

        horizontal_layout_parameters_1->addWidget(push_button_browse);


        vertical_layout_parameters_page_1->addLayout(horizontal_layout_parameters_1);

        vertical_spacer_parameters_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Preferred);

        vertical_layout_parameters_page_1->addItem(vertical_spacer_parameters_2);

        horizontal_layout_parameters_2 = new QHBoxLayout();
        horizontal_layout_parameters_2->setSpacing(12);
        horizontal_layout_parameters_2->setObjectName(QString::fromUtf8("horizontal_layout_parameters_2"));
        vertical_layout_parameters_page_2 = new QVBoxLayout();
        vertical_layout_parameters_page_2->setSpacing(6);
        vertical_layout_parameters_page_2->setObjectName(QString::fromUtf8("vertical_layout_parameters_page_2"));
        label_choose_languages = new QLabel(page_parameters);
        label_choose_languages->setObjectName(QString::fromUtf8("label_choose_languages"));

        vertical_layout_parameters_page_2->addWidget(label_choose_languages);

        combo_box_languages = new QComboBox(page_parameters);
        combo_box_languages->setObjectName(QString::fromUtf8("combo_box_languages"));
        sizePolicy1.setHeightForWidth(combo_box_languages->sizePolicy().hasHeightForWidth());
        combo_box_languages->setSizePolicy(sizePolicy1);
        combo_box_languages->setMinimumSize(QSize(150, 0));
        combo_box_languages->setMaximumSize(QSize(150, 16777215));

        vertical_layout_parameters_page_2->addWidget(combo_box_languages);

        vertical_spacer_parameters_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertical_layout_parameters_page_2->addItem(vertical_spacer_parameters_3);

        check_box_backup = new QCheckBox(page_parameters);
        check_box_backup->setObjectName(QString::fromUtf8("check_box_backup"));
        check_box_backup->setChecked(true);

        vertical_layout_parameters_page_2->addWidget(check_box_backup);

        check_box_copy_english_help = new QCheckBox(page_parameters);
        check_box_copy_english_help->setObjectName(QString::fromUtf8("check_box_copy_english_help"));
        check_box_copy_english_help->setChecked(true);

        vertical_layout_parameters_page_2->addWidget(check_box_copy_english_help);


        horizontal_layout_parameters_2->addLayout(vertical_layout_parameters_page_2);

        horizontal_spacer_parameters = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_parameters_2->addItem(horizontal_spacer_parameters);


        vertical_layout_parameters_page_1->addLayout(horizontal_layout_parameters_2);


        gridLayout_4->addLayout(vertical_layout_parameters_page_1, 1, 0, 1, 1);

        stacked_widget->addWidget(page_parameters);
        page_translation = new QWidget();
        page_translation->setObjectName(QString::fromUtf8("page_translation"));
        gridLayout_5 = new QGridLayout(page_translation);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setMargin(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_top_logo_translation = new QLabel(page_translation);
        label_top_logo_translation->setObjectName(QString::fromUtf8("label_top_logo_translation"));
        sizePolicy1.setHeightForWidth(label_top_logo_translation->sizePolicy().hasHeightForWidth());
        label_top_logo_translation->setSizePolicy(sizePolicy1);
        label_top_logo_translation->setPixmap(QPixmap(QString::fromUtf8(":/res/images/top_logo.png")));

        gridLayout_5->addWidget(label_top_logo_translation, 0, 0, 1, 1);

        vertical_layout_translation = new QVBoxLayout();
        vertical_layout_translation->setSpacing(6);
        vertical_layout_translation->setMargin(9);
        vertical_layout_translation->setObjectName(QString::fromUtf8("vertical_layout_translation"));
        label_title_translation = new QLabel(page_translation);
        label_title_translation->setObjectName(QString::fromUtf8("label_title_translation"));
        label_title_translation->setWordWrap(true);

        vertical_layout_translation->addWidget(label_title_translation);

        vertical_spacer_translation_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertical_layout_translation->addItem(vertical_spacer_translation_1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_current_file_title = new QLabel(page_translation);
        label_current_file_title->setObjectName(QString::fromUtf8("label_current_file_title"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_current_file_title->sizePolicy().hasHeightForWidth());
        label_current_file_title->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_current_file_title);

        label_current_file = new QLabel(page_translation);
        label_current_file->setObjectName(QString::fromUtf8("label_current_file"));
        sizePolicy.setHeightForWidth(label_current_file->sizePolicy().hasHeightForWidth());
        label_current_file->setSizePolicy(sizePolicy);
        label_current_file->setTextFormat(Qt::PlainText);
        label_current_file->setScaledContents(false);
        label_current_file->setWordWrap(false);
        label_current_file->setIndent(-1);
        label_current_file->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(label_current_file);


        vertical_layout_translation->addLayout(horizontalLayout);

        progress_bar_current = new QProgressBar(page_translation);
        progress_bar_current->setObjectName(QString::fromUtf8("progress_bar_current"));
        progress_bar_current->setValue(0);

        vertical_layout_translation->addWidget(progress_bar_current);

        text_edit_translating = new QTextEdit(page_translation);
        text_edit_translating->setObjectName(QString::fromUtf8("text_edit_translating"));
        text_edit_translating->setFrameShape(QFrame::StyledPanel);
        text_edit_translating->setFrameShadow(QFrame::Sunken);
        text_edit_translating->setUndoRedoEnabled(false);
        text_edit_translating->setLineWrapMode(QTextEdit::NoWrap);
        text_edit_translating->setReadOnly(false);
        text_edit_translating->setAcceptRichText(false);

        vertical_layout_translation->addWidget(text_edit_translating);

        vertical_spacer_translation_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertical_layout_translation->addItem(vertical_spacer_translation_2);


        gridLayout_5->addLayout(vertical_layout_translation, 1, 0, 1, 1);

        stacked_widget->addWidget(page_translation);
        page_not_translated = new QWidget();
        page_not_translated->setObjectName(QString::fromUtf8("page_not_translated"));
        gridLayout_6 = new QGridLayout(page_not_translated);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setMargin(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_top_logo_not_translated = new QLabel(page_not_translated);
        label_top_logo_not_translated->setObjectName(QString::fromUtf8("label_top_logo_not_translated"));
        sizePolicy1.setHeightForWidth(label_top_logo_not_translated->sizePolicy().hasHeightForWidth());
        label_top_logo_not_translated->setSizePolicy(sizePolicy1);
        label_top_logo_not_translated->setPixmap(QPixmap(QString::fromUtf8(":/res/images/top_logo.png")));

        gridLayout_6->addWidget(label_top_logo_not_translated, 0, 0, 1, 1);

        vertical_layout_not_translated = new QVBoxLayout();
        vertical_layout_not_translated->setSpacing(6);
        vertical_layout_not_translated->setMargin(9);
        vertical_layout_not_translated->setObjectName(QString::fromUtf8("vertical_layout_not_translated"));
        label_title_not_translated = new QLabel(page_not_translated);
        label_title_not_translated->setObjectName(QString::fromUtf8("label_title_not_translated"));
        sizePolicy.setHeightForWidth(label_title_not_translated->sizePolicy().hasHeightForWidth());
        label_title_not_translated->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_title_not_translated->setFont(font);
        label_title_not_translated->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_title_not_translated->setWordWrap(true);
        label_title_not_translated->setOpenExternalLinks(true);

        vertical_layout_not_translated->addWidget(label_title_not_translated);

        vertical_spacer_not_translated = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Preferred);

        vertical_layout_not_translated->addItem(vertical_spacer_not_translated);

        label_not_translated = new QLabel(page_not_translated);
        label_not_translated->setObjectName(QString::fromUtf8("label_not_translated"));

        vertical_layout_not_translated->addWidget(label_not_translated);

        plain_text_edit_mail = new QPlainTextEdit(page_not_translated);
        plain_text_edit_mail->setObjectName(QString::fromUtf8("plain_text_edit_mail"));
        plain_text_edit_mail->setLineWrapMode(QPlainTextEdit::NoWrap);
        plain_text_edit_mail->setReadOnly(true);

        vertical_layout_not_translated->addWidget(plain_text_edit_mail);

        push_button_copy = new QPushButton(page_not_translated);
        push_button_copy->setObjectName(QString::fromUtf8("push_button_copy"));

        vertical_layout_not_translated->addWidget(push_button_copy);


        gridLayout_6->addLayout(vertical_layout_not_translated, 1, 0, 1, 1);

        stacked_widget->addWidget(page_not_translated);
        page_last = new QWidget();
        page_last->setObjectName(QString::fromUtf8("page_last"));
        gridLayout_7 = new QGridLayout(page_last);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setMargin(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_vertical_logo_last = new QLabel(page_last);
        label_vertical_logo_last->setObjectName(QString::fromUtf8("label_vertical_logo_last"));
        sizePolicy1.setHeightForWidth(label_vertical_logo_last->sizePolicy().hasHeightForWidth());
        label_vertical_logo_last->setSizePolicy(sizePolicy1);
        label_vertical_logo_last->setLineWidth(0);
        label_vertical_logo_last->setPixmap(QPixmap(QString::fromUtf8(":/res/images/side_logo.png")));
        label_vertical_logo_last->setScaledContents(false);
        label_vertical_logo_last->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_7->addWidget(label_vertical_logo_last, 0, 0, 1, 1);

        vertical_layout_last = new QVBoxLayout();
        vertical_layout_last->setSpacing(6);
        vertical_layout_last->setMargin(9);
        vertical_layout_last->setObjectName(QString::fromUtf8("vertical_layout_last"));
        label_final = new QLabel(page_last);
        label_final->setObjectName(QString::fromUtf8("label_final"));
        label_final->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_final->setWordWrap(true);

        vertical_layout_last->addWidget(label_final);

        vertical_spacer_last_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertical_layout_last->addItem(vertical_spacer_last_1);

        check_box_open_readme = new QCheckBox(page_last);
        check_box_open_readme->setObjectName(QString::fromUtf8("check_box_open_readme"));
        check_box_open_readme->setChecked(true);

        vertical_layout_last->addWidget(check_box_open_readme);

        check_box_toggle_to_russian = new QCheckBox(page_last);
        check_box_toggle_to_russian->setObjectName(QString::fromUtf8("check_box_toggle_to_russian"));
        check_box_toggle_to_russian->setChecked(true);

        vertical_layout_last->addWidget(check_box_toggle_to_russian);

        check_box_exec_lightroom = new QCheckBox(page_last);
        check_box_exec_lightroom->setObjectName(QString::fromUtf8("check_box_exec_lightroom"));
        check_box_exec_lightroom->setChecked(true);

        vertical_layout_last->addWidget(check_box_exec_lightroom);

        vertical_spacer_last_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vertical_layout_last->addItem(vertical_spacer_last_2);


        gridLayout_7->addLayout(vertical_layout_last, 0, 1, 1, 1);

        stacked_widget->addWidget(page_last);

        gridLayout_2->addWidget(stacked_widget, 0, 0, 1, 1);

        line_main = new QFrame(MainDialogClass);
        line_main->setObjectName(QString::fromUtf8("line_main"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line_main->sizePolicy().hasHeightForWidth());
        line_main->setSizePolicy(sizePolicy3);
        line_main->setMaximumSize(QSize(16777215, 2));
        line_main->setFrameShadow(QFrame::Sunken);
        line_main->setFrameShape(QFrame::HLine);

        gridLayout_2->addWidget(line_main, 1, 0, 1, 1);

        horizontal_layout_bottom = new QHBoxLayout();
        horizontal_layout_bottom->setSpacing(6);
        horizontal_layout_bottom->setMargin(9);
        horizontal_layout_bottom->setObjectName(QString::fromUtf8("horizontal_layout_bottom"));
        label_author = new QLabel(MainDialogClass);
        label_author->setObjectName(QString::fromUtf8("label_author"));
        label_author->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_author->setIndent(-1);
        label_author->setOpenExternalLinks(true);

        horizontal_layout_bottom->addWidget(label_author);

        horizontal_spacer_bottom_1 = new QSpacerItem(88, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_bottom->addItem(horizontal_spacer_bottom_1);

        push_button_prev = new QPushButton(MainDialogClass);
        push_button_prev->setObjectName(QString::fromUtf8("push_button_prev"));

        horizontal_layout_bottom->addWidget(push_button_prev);

        push_button_next = new QPushButton(MainDialogClass);
        push_button_next->setObjectName(QString::fromUtf8("push_button_next"));

        horizontal_layout_bottom->addWidget(push_button_next);

        horizontal_spacer_bottom_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontal_layout_bottom->addItem(horizontal_spacer_bottom_2);

        push_button_cancel = new QPushButton(MainDialogClass);
        push_button_cancel->setObjectName(QString::fromUtf8("push_button_cancel"));

        horizontal_layout_bottom->addWidget(push_button_cancel);


        gridLayout_2->addLayout(horizontal_layout_bottom, 3, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_path->setBuddy(line_edit_path);
        label_not_translated->setBuddy(plain_text_edit_mail);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainDialogClass);

        stacked_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MainDialogClass)
    {
        MainDialogClass->setWindowTitle(QApplication::translate("MainDialogClass", "\320\240\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 Adobe Lightroom", 0, QApplication::UnicodeUTF8));
        label_vertical_logo_start->setText(QString());
        label_welcome->setText(QApplication::translate("MainDialogClass", "<H2>\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 \321\200\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270 Adobe Photoshop Lightroom 2.x</H2>\n"
"\320\224\320\260\320\275\320\275\320\260\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\277\320\276\320\267\320\262\320\276\320\273\320\270\321\202 \320\267\320\260\320\274\320\265\320\275\320\270\321\202\321\214 \320\276\320\264\320\270\320\275 \320\270\320\267 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \321\217\320\267\321\213\320\272\320\276\320\262 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 Adobe Photoshop Lightroom \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\270\320\271.", 0, QApplication::UnicodeUTF8));
        label_top_logo_parameters->setText(QString());
        label_title_parameters->setText(QApplication::translate("MainDialogClass", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\320\260\320\277\320\272\321\203 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270 Adobe Photoshop Lightroom \320\270 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\320\265 \320\276\321\201\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label_path->setText(QApplication::translate("MainDialogClass", "\320\237\320\260\320\277\320\272\320\260 Lightroom:", 0, QApplication::UnicodeUTF8));
        push_button_browse->setText(QApplication::translate("MainDialogClass", "\320\236\320\261\320\267\320\276\321\200...", 0, QApplication::UnicodeUTF8));
        label_choose_languages->setText(QApplication::translate("MainDialogClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\217\320\267\321\213\320\272 \320\264\320\273\321\217 \320\267\320\260\320\274\320\265\320\275\321\213 \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\270\320\271:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        check_box_backup->setToolTip(QApplication::translate("MainDialogClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\203\321\216 \320\276\320\277\321\206\320\270\321\216 \320\264\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\272\320\276\320\277\320\270\320\271 \321\204\320\260\320\271\320\273\320\276\320\262,\n"
"\320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\261\321\203\320\264\321\203\321\202 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\321\213 \320\262 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\265 \321\200\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        check_box_backup->setText(QApplication::translate("MainDialogClass", "\320\241\320\276\320\267\320\264\320\260\320\262\320\260\321\202\321\214 \320\272\320\276\320\277\320\270\320\270 \320\267\320\260\320\274\320\265\320\275\321\217\320\265\320\274\321\213\321\205 \321\204\320\260\320\271\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        check_box_copy_english_help->setToolTip(QApplication::translate("MainDialogClass", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\203\321\216 \320\276\320\277\321\206\320\270\321\216 \320\264\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\270\321\205 \321\204\320\260\320\271\320\273\320\276\320\262 \320\277\320\276\320\274\320\276\321\211\320\270\n"
"\320\262\320\274\320\265\321\201\321\202\320\276 \321\204\320\260\320\271\320\273\320\276\320\262 \320\277\320\276\320\274\320\276\321\211\320\270 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\217\320\267\321\213\320\272\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        check_box_copy_english_help->setText(QApplication::translate("MainDialogClass", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\270\320\265 \321\204\320\260\320\271\320\273\321\213 \320\277\320\276\320\274\320\276\321\211\320\270", 0, QApplication::UnicodeUTF8));
        label_top_logo_translation->setText(QString());
        label_title_translation->setText(QApplication::translate("MainDialogClass", "\320\222\321\213\320\277\320\276\320\273\320\275\321\217\320\265\321\202\321\201\321\217 \320\277\320\265\321\200\320\265\320\262\320\276\320\264 Adobe Photoshop Lightroom", 0, QApplication::UnicodeUTF8));
        label_current_file_title->setText(QApplication::translate("MainDialogClass", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\204\320\260\320\271\320\273:", 0, QApplication::UnicodeUTF8));
        label_current_file->setText(QString());
        label_top_logo_not_translated->setText(QString());
        label_title_not_translated->setText(QApplication::translate("MainDialogClass", "\320\222 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\265 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\320\260 \320\261\321\213\320\273\320\270 \320\276\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\321\213 \320\275\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\321\213\320\265 \321\204\321\200\320\260\320\267\321\213.<br >\320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270 \321\201\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\277\320\270\321\201\321\214\320\274\320\260 \320\260\320\262\321\202\320\276\321\200\321\203 \320\264\320\260\320\275\320\275\320\276\320\263\320\276 \321\200\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200\320\260 \320"
                        "\275\320\260 \320\260\320\264\321\200\320\265\321\201 <a href=\"mailto:lightroom@list.ru?subject=Unknown%20phrases\"><span style=\" text-decoration: underline; color:#0000ff;\">lightroom@list.ru</span></a> \320\264\320\273\321\217 \320\277\320\276\320\274\320\276\321\211\320\270 \320\262 \320\265\320\263\320\276 \321\201\320\262\320\276\320\265\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\274 \320\276\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\270. <b>\320\241\320\277\320\260\321\201\320\270\320\261\320\276!</b>", 0, QApplication::UnicodeUTF8));
        label_not_translated->setText(QApplication::translate("MainDialogClass", "\320\242\320\265\320\272\321\201\321\202 \320\277\320\270\321\201\321\214\320\274\320\260:", 0, QApplication::UnicodeUTF8));
        push_button_copy->setText(QApplication::translate("MainDialogClass", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 \320\277\320\270\321\201\321\214\320\274\320\260 \320\272 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_vertical_logo_last->setText(QString());
        label_final->setText(QApplication::translate("MainDialogClass", "<H2>\320\240\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217 Adobe Photoshop Lightroom \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\260</H2>\n"
"\320\237\321\200\320\276\321\206\320\265\321\201\321\201 \321\200\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213 Adobe Photoshop Lightroom \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275.<br>\n"
"\320\224\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\276\321\201\320\275\320\276\320\262\320\275\321\213\321\205 \320\277\321\200\320\276\320\261\320\273\320\265\320\274, \321\201\320\262\321\217\320\267\320\260\320\275\320\275\321\213\321\205 \321\201 \321\200\321\203\321\201\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\265\320\271, \320\277\321\200\320\276\321\201\321\214\320\261\320\260 \320\276\320\267"
                        "\320\275\320\260\320\272\320\276\320\274\320\270\321\202\321\214\321\201\321\217 \321\201 readme-\321\204\320\260\320\271\320\273\320\276\320\274, \320\273\320\270\320\261\320\276 \320\276\320\261\321\200\320\260\321\211\320\260\321\202\321\214\321\201\321\217 \320\275\320\260 e-mail \320\260\320\262\321\202\320\276\321\200\320\260 <a href=\"mailto:lightroom@list.ru\"><span style=\"text-decoration: underline; color:#0000ff;\">lightroom@list.ru</span></a>", 0, QApplication::UnicodeUTF8));
        check_box_open_readme->setText(QApplication::translate("MainDialogClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 readme-\321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        check_box_toggle_to_russian->setText(QApplication::translate("MainDialogClass", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\217\320\267\321\213\320\272 \320\262 Lightroom \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8));
        check_box_exec_lightroom->setText(QApplication::translate("MainDialogClass", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 Adobe Photoshop Lightroom", 0, QApplication::UnicodeUTF8));
        label_author->setText(QApplication::translate("MainDialogClass", "\320\241\320\265\321\200\320\263\320\265\320\271 \320\221\320\260\320\273\321\217\320\272\320\270\320\275<br>\n"
"<a href=\"mailto:lightroom@list.ru\"><span style=\"text-decoration: underline; color:#0000ff;\">lightroom@list.ru</span></a>", 0, QApplication::UnicodeUTF8));
        push_button_prev->setText(QApplication::translate("MainDialogClass", "< \320\235\320\260\320\267\320\260\320\264", 0, QApplication::UnicodeUTF8));
        push_button_next->setText(QApplication::translate("MainDialogClass", "\320\224\320\260\320\273\320\265\320\265 >", 0, QApplication::UnicodeUTF8));
        push_button_cancel->setText(QApplication::translate("MainDialogClass", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainDialogClass);
    } // retranslateUi

};

namespace Ui {
    class MainDialogClass: public Ui_MainDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
