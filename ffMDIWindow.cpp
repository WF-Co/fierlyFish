#include <QDebugStateSaver>
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

    //создаем меню "Настройки"
    QMenu* pmnuSettings = new QMenu(QObject::tr("MNUSETTINGS"));

    //создаем действие для меню "Настройки" в виде пункта меню "Настройки"
    QAction* pactSettings = new QAction(QObject::tr("APPSETTINGS"), this);
    //соединяем действие со слотом вызова окна настроек приложения
    connect(pactSettings, &QAction::triggered, ffCoreApp::theApp(), &ffCoreApp::slotSettingsApp);

    //добавляем подменю "Локализация" в меню "Настройки"
    pmnuSettings->addMenu(ffCoreApp::theApp()->ffTrans()->getMnuLang());
    //добавляем разделитель в списке пунктов меню в меню "Настройки"
    pmnuSettings->addSeparator();
    //добавляем пункт меню "Настройки" в меню "Настройки"
    pmnuSettings->addAction(pactSettings);

    //создаем меню Помощь
    QMenu* pmnuHelp = new QMenu(QObject::tr("MNUHELP"));

    //создаем действие для меню "Помощь" в виде пункта меню "О приложении"
    QAction* pactAbout = new QAction(QObject::tr("SUBMNUABOUT"), this);
    //соединяем действие со слотом вызова окна "О приложении"
    connect(pactAbout, &QAction::triggered, ffCoreApp::theApp(), &ffCoreApp::slotAbout);

    //Добавляем пункт меню "О приложении" в меню "Помощь"
    pmnuHelp->addAction(pactAbout);

    //добавляем созданние меню в строку меню главного окна
    //Добавлем меню "Файл" в строку меню окна приложения
    menuBar()->addMenu(pmnuFile);
    //Добавляем меню "Настройки" в строку меню окна приложения
    menuBar()->addMenu(pmnuSettings);
    //Добавляем меню "Помощь" в строку меню окна приложения
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

void ffMDIWindow::createStatusBar()
{
    m_pstatDateLabel = new QLabel(this);
    m_pstatDateLabel->setText(QDate::currentDate().toString());

    statusBar()->addPermanentWidget(m_pstatDateLabel);
}
