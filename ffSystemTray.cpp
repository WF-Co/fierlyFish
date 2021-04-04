#include <QPixmap>

#include "ffSystemTray.h"
#include "ffMDIWindow.h"
#include "ffCoreApp.h"

ffSystemTray::ffSystemTray(QWidget* pwgt /*=0*/)
    : ffMDIWindow(pwgt)
{
    //устанавливаем заголовок окна
    setWindowTitle(ffCoreApp::theApp()->applicationName());

    //создаем действие "Показать/скрыть" главное окна приложения для меню приложения в системном трее
    QAction* pactShowHide = new QAction(QObject::tr("SHOWHIDEAPPWINDOW"), this);
    //соединяем действие со слотом показа/скрытия окна
    connect(pactShowHide, &QAction::triggered, this, &ffSystemTray::slotShowHide);

    //создаем действие "О приложении" для меню приложения в системном трее
    QAction* pactAbout = new QAction(QObject::tr("SUBMNUABOUT"), this);
    //соединяем действие со слотом показа диалогового окна "О приложении"
    connect(pactAbout, &QAction::triggered, ffCoreApp::theApp(), &ffCoreApp::slotAbout);

    //создаем действие "выход" из приложения (полная выгрузка приложения, завершение работы)
    QAction* pactQuit = new QAction(QObject::tr("CLOSEWNDAPP"), this);
    //соединяем действие со слотом закрытия приложения, завершение работы
    connect(pactQuit, &QAction::triggered, qApp, &ffCoreApp::quit);

    //создаем действие "Настройки" для меню приложения в системном трее
    QAction* pactSettings = new QAction(QObject::tr("APPSETTINGS"), this);
    //соединяем действие со слотом вызова окна настроек приложения
    connect(pactSettings, &QAction::triggered, ffCoreApp::theApp(), &ffCoreApp::slotSettingsApp);

    //создаем меню для значка в системном трее
    m_ptrayIconMenu = new QMenu(this);
    //создаем пункт меню "Показать/скрыть" добавляя действие "Показать/Скрвть"
    m_ptrayIconMenu->addAction(pactShowHide);
    //добавляем разделитель между пунктами меню
    m_ptrayIconMenu->addSeparator();
    //создаем пункт меню "Настройки" добавляя действие "Настройки"
    m_ptrayIconMenu->addAction(pactSettings);
    //добавляем разделитель пунктов меню
    m_ptrayIconMenu->addSeparator();
    //добавляем пункт меню "О приложении" добавляя действие "О приложении"
    m_ptrayIconMenu->addAction(pactAbout);
    //добавляем пункт меню "Выход" добавляя действие "Выход" завершение работы.
    m_ptrayIconMenu->addAction(pactQuit);

    //создаем виджет иконки в системном трее
    m_ptrayIcon = new QSystemTrayIcon(this);
    //устанавливаем контекстное меню на иконке в системном трее
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    //устанавливаем всплывающую подсказку на значке в системном трее
    m_ptrayIcon->setToolTip(ffCoreApp::theApp()->applicationName());
    //устанавливаем иконку созданного виджета в системном трее
    m_ptrayIcon->setIcon(QPixmap(ffCoreApp::theApp()->applicationDirPath().append("/icons/iconApp.png")));

    connect(m_ptrayIcon, &QSystemTrayIcon::activated, this, &ffSystemTray::onTrayIconActivated);

    //вызываем слот показа/скрытия главного окна приложения
    slotShowHide();
    //показываем иконку в трее
    m_ptrayIcon->show();
}

ffSystemTray::~ffSystemTray(){
}

void ffSystemTray::closeEvent(QCloseEvent*)
{
    if(m_ptrayIcon->isVisible())
        hide();
}

void ffSystemTray::onTrayIconActivated( QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        slotShowHide();
        break;

    default:
        break;
    }
}

//================================ SLOTS =====================================================
void ffSystemTray::slotShowHide()
{
    setVisible(!isVisible());
}
