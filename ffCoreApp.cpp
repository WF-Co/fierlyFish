#include <QDebug>
#include "ffCoreApp.h"

ffCoreApp::ffCoreApp(int& argc, char** argv, const QString& strOrg, const QString& strAppName) : QApplication(argc, argv) , m_pSettings(nullptr)
{
    //устанавилавем наименование организации
    setOrganizationName(strOrg);
    //устанавливаем наименование приложения
    setApplicationName(strAppName);

    //создаем объект по работе с настройками и сохраняем указатель на него
    m_pSettings = new QSettings(strOrg, strAppName, this);

    //создаем объект по переводу приложения
    m_pTranslator = new ffTranslator(this);

    //создаем объект для размещения в системном трее
    m_psysTray = new ffSystemTray;

    connect(this, &QApplication::lastWindowClosed, this, &ffCoreApp::writeSettings);

    //создаем окно настроек приложеиня
    m_pWndSettingsApp = nullptr;
}

ffCoreApp::~ffCoreApp(){}

ffCoreApp* ffCoreApp::theApp()
{
    //возвращаем указатель на запущенное приложение.
    return qobject_cast<ffCoreApp*> qApp;
}

void ffCoreApp::writeSettings()
{
    m_psysTray->writeSettings();
}

QSettings* ffCoreApp::settings()
{
    //возвращаем указатель на объект настроек
    return m_pSettings;
}

ffTranslator* ffCoreApp::ffTrans()
{
    return m_pTranslator;
}

ffWndSetting* ffCoreApp::pWndSettings()
{
    return m_pWndSettingsApp;
}

//**************************** СЛОТЫ ******************************************
//реализация слота "О приложении"
void ffCoreApp::slotAbout()
{
    //вывод сообщения в окне соощения
    QMessageBox::about(m_psysTray, QObject::tr("ABOUTAPPLICATION"), ffCoreApp::theApp()->applicationName());
}

void ffCoreApp::slotSettingsApp()
{
    //проверяем существует окно или нет
    if(!m_pWndSettingsApp)
    {
       //создаем окно настроек (загружаем)
       m_pWndSettingsApp = new ffWndSetting;
       //соединяем сигнал окна настроек окончание работы со слотом выгрузки (slotCloseSettingsApp) из памяти окна
       connect(m_pWndSettingsApp, &ffWndSetting::finished, this, &ffCoreApp::slotCloseSettingsApp);
    };

    if(m_pWndSettingsApp)
    {
        //проверяем окно показывается пользователю или нет. В случае если окно показывается мы его делаем активным иначе показываем окно
        if(!m_pWndSettingsApp->isVisible())
        {
            //если окно не видимо пользователю, то показываем его
            m_pWndSettingsApp->show();
        }
        else
        {
            //если окно видимо пользователю, но оно не активно - делаем активным актом (фокус)
            m_pWndSettingsApp->activateWindow();
        };

        //проверяем окно свернуто или нет. если окно свернуто, то разворачивеам его и делаем активным
        if(m_pWndSettingsApp->isMinimized())
            m_pWndSettingsApp->showNormal();
     };

}

void ffCoreApp::slotCloseSettingsApp()
{
    //выгружаем из памяти окно настроек
    delete m_pWndSettingsApp;
    //устанавливаем нулевой указатель
    m_pWndSettingsApp = nullptr;
}



