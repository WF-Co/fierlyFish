#include <QPixmap>

#include "ffSystemTray.h"
#include "ffMDIWindow.h"
#include "ffCoreApp.h"

ffSystemTray::ffSystemTray(QWidget* pwgt /*=0*/)
    : ffMDIWindow(pwgt)
{
    setWindowTitle(ffCoreApp::theApp()->applicationName());

    QAction* pactShowHide = new QAction(QObject::tr("SHOWHIDEAPPWINDOW"), this);
    connect(pactShowHide, &QAction::triggered, this, &ffSystemTray::slotShowHide);

    QAction* pactAbout = new QAction(QObject::tr("SUBMNUABOUT"), this);
    connect(pactAbout, &QAction::triggered, ffCoreApp::theApp(), &ffCoreApp::slotAbout);

    QAction* pactQuit = new QAction(QObject::tr("CLOSEWNDAPP"), this);
    connect(pactQuit, &QAction::triggered, qApp, &ffCoreApp::quit);

    m_ptrayIconMenu = new QMenu(this);
    m_ptrayIconMenu->addAction(pactShowHide);
    m_ptrayIconMenu->addAction(pactAbout);
    m_ptrayIconMenu->addAction(pactQuit);

    m_ptrayIcon = new QSystemTrayIcon(this);
    m_ptrayIcon->setContextMenu(m_ptrayIconMenu);
    m_ptrayIcon->setToolTip(ffCoreApp::theApp()->applicationName());
    m_ptrayIcon->setIcon(QPixmap(ffCoreApp::theApp()->applicationDirPath().append("/icons/iconApp.png")));

    connect(m_ptrayIcon, &QSystemTrayIcon::activated, this, &ffSystemTray::onTrayIconActivated);

    slotShowHide();
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
