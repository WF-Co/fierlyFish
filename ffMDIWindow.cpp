#include <QDialog>
#include <QGridLayout>
// включаем заголовочный файл класса coreApp
#include "ffCoreApp.h"
// включаем заголовочный файл класса MainWnd
#include "ffMDIWindow.h"
#include "ffTranslator.h"
#include "ffWndSettings.h"

//реализуем конструктор класса. Значение указателя _parent передаем родительскому классу (предку) QMainWindow.
ffMDIWindow::ffMDIWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //вызываем метод чтения настроек приложения
    readSettings();

    //настройка окна
    //устанавливаем значек в вернем левом углу
    setWindowIcon(QPixmap(ffCoreApp::theApp()->applicationDirPath().append("/icons/iconApp.png")));

    //создаем меню Файл
    QMenu* pmnuFile = new QMenu(QObject::tr("MNUFILE"));
    // добавляем действие в меню в виде пункта меню
    pmnuFile->addAction(QObject::tr("SUBMNUCLOSE"), qApp, SLOT(closeAllWindows()),QKeySequence ("CTRL+Q"));

    //создаем Настройки
    QMenu* pmnuSettings = new QMenu(QObject::tr("MNUSETTINGS"));

    pmnuSettings->addMenu(ffCoreApp::theApp()->ffTrans()->getMnuLang());
    pmnuSettings->addSeparator();
    m_actAppSettings = pmnuSettings->addAction(QObject::tr("APPSETTINGS"),this, SLOT(slotSettingsApp()));


    //информационное сообщение
    /*
     * QMessageBox::information(0,"Information","Operation Complete");
     */

    //создаем меню Помощь
    QMenu* pmnuHelp = new QMenu(QObject::tr("MNUHELP"));

    //добавляем действие в меню в виде пункта меню
    pmnuHelp->addAction(QObject::tr("SUBMNUABOUT"), this, SLOT(slotAbout()), Qt::Key_F1);

    //добавляем созданние меню в строку меню главного окна
    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuSettings);
    menuBar()->addMenu(pmnuHelp);

    //создаем MDI область в главном окне приложения
    m_pma = new QMdiArea;

    //устанавливаем поведение вертикального и горизонтального бегунка в области MDI
    m_pma->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pma->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //центрируем область в окне
    setCentralWidget(m_pma);

    //вызываем метод формирования статусной строки главного окна
    createStatusBar();

    //создаем статусную строку
    //m_pstatBar = new QStatusBar(m_pma);
    //устанавливаем виджет даты в строку состояния
    statusBar()->showMessage(tr("READY"),1000);
}

//метод чтения настроек приложения
void ffMDIWindow::readSettings()
{
    //получаем указатель на объект настроек приложения
    QSettings* pst = ffCoreApp::theApp()->settings();

    //устанавливаем префикс для ключей
    pst->beginGroup("/GUIApplication");

    //читаем настроки
    //ширина окна
    int nWidth = pst->value("/width", width()).toInt();
    //высота окна
    int nHeight = pst->value("/height",height()).toInt();
    //изменяем размер окна согласно прочитанных значений настроек
    resize(nWidth, nHeight);
    //перемещаем главное окно в сохраненнную позицию
    move(pst->value("/pos_x",pos().x()).toInt(),pst->value("/pos_y",pos().y()).toInt());

    //снимаем префикс ключей
    pst->endGroup();
}

//метод записи настроек приложения
void ffMDIWindow::writeSettings()
{
    //получаем указатель объекта хранения настроек
    QSettings* pst = ffCoreApp::theApp()->settings();
    //устанавливаем префикс ключей настроек
    pst->beginGroup("/GUIApplication");
    //ширина окна
    pst->setValue("/width",width());
    //высота окна
    pst->setValue("/height",height());
    //позиция окна
    pst->setValue("/pos_x",pos().x());
    pst->setValue("/pos_y",pos().y());
    //снимаем префикс ключей
    pst->endGroup();
}

/* реализация деструктора класса. На данный момент нет необходимости его реализовывать.
    Об освобождении памяти позаботиться класс QObject наследником которого является класс QMainWindow */
ffMDIWindow::~ffMDIWindow()
{

}

//слот показа виджета о приложении.
void ffMDIWindow::slotAbout()
{
    ffCoreApp::theApp()->slotAbout();
}

//слот вывода окна настроек приложения
void ffMDIWindow::slotSettingsApp()
{
   /* if(m_actAppSettings->isEnabled())
    {
        ffWndSetting* wndSettings = new ffWndSetting();
        connect(wndSettings, &ffWndSetting::destroyed, this, &ffMDIWindow::slotSettingsApp);
        //m_pma->addSubWindow(wndSettings);
        wndSettings->show();
        m_actAppSettings->setDisabled(true);
    }
    else
    {
        m_actAppSettings->setEnabled(true);
    }
    */
    if(ffCoreApp::theApp()->pWndSettings())
    {
        ffCoreApp::theApp()->slotSettingsApp();
    }
    else
    {
        ffCoreApp::theApp()->pWndSettings()->show();
    }
}

void ffMDIWindow::createStatusBar()
{
    m_pstatDateLabel = new QLabel(this);
    m_pstatDateLabel->setText(QDate::currentDate().toString());

    statusBar()->addPermanentWidget(m_pstatDateLabel);
}
