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
    m_pWndSettingsApp = new ffWndSetting;
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
    //m_pWndSettingsApp = new ffWndSetting;
    m_pWndSettingsApp->show();
}



