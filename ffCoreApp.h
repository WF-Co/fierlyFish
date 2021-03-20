/*!
\file
\brief Родительский (основной) класс ядра приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Февраль 2020 года

\todo задача 1
456
900
7777

\todo задача 2
\todo задача 3
*/


#ifndef COREAPP_H
#define COREAPP_H

//включаем заголовочные файлы Qt
#include <QApplication>
#include <QSettings>

#include "ffTranslator.h"
#include "ffSystemTray.h"



//определяем основной класс приложения (ядро приложения). Класс coreApp унаследован от класса QApplication
/*!
Данный класс предназначен для запуска ядра приложения.
В классе определяются указатели на файл настроек приложения, переводчик локализации приложения.
После запуска ядра графическим элементом его является значек в системном трее.
В графической части у ядра имеется стартовое контекстное меню включающее в себя следующие пункты:
"О приложении"
"Показать / скрыть главное окно приложения"
"Выход" - закрытие полностью приложения и освобождение ресурсов ОС.
 */

class ffCoreApp : public QApplication {
    Q_OBJECT

private:
    //указатель на объект начальных настроек приложения
    //объект должен хранить настройки только настройки для успешной работы клиента на ПК, где запускается,
    //а также для успешного подключения к БД
    QSettings* m_pSettings;
    //указатель на объект по работе интернационализации приложения
    ffTranslator* m_pTranslator;
    //указатель на объект размещаемого в системном трее рабочих столов ОС
    ffSystemTray* m_psysTray;
// ffTestWgt* m_pwndSettings;

private slots:
    void writeSettings();

public slots:
    //слот показа диалогового окна "о приложении"
    void slotAbout();
  //  void slotWndSettings();

public:
    //констуктор класса
    ffCoreApp(int& argc, char** argv, const QString& strOrg, const QString& strAppName);
    ~ffCoreApp();

    //определяем и реализовываем статический метод взятия указателя приложения
    static ffCoreApp* theApp();

    //определяем и реализовываем метод взятия указателя на объект настроек приложения
    QSettings* settings();

    ffTranslator* ffTrans();
};

#endif // COREAPP_H
