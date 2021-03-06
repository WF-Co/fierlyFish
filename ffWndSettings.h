/*!
\file
\brief Класс окна настроек приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Июль 2020 года

\todo задача 1
\todo задача 2
\todo задача 3
*/

#ifndef FFWNDSETTINGS_H
#define FFWNDSETTINGS_H

//#include <QtWidgets>
#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>

// включаем заголовочный файл класса coreApp
#include "ffCoreApp.h"
// включаем заголовочный файл класса MainWnd
//#include "ffMDIWindow.h"
#include "ffTranslator.h"
//включаем классы логических групп настроек
#include "ffGroupSettings.h"

//===============================================================================================================

//определяем класс окна настроек приложения. Класс MainWnd унаследован от класса QMainWindow
class ffWndSetting : public QDialog
{
    //специфичный макрос для распознания класса в МОС (метаобъектный компилятор), который нуждается в подробной переработке.
    Q_OBJECT

private:
    //указатель на визуальный список выбора логической группы настроек
    QListWidget* lwgSettings;
    //стек виджетов на слои компоноки визуальных логических групп настроек
    QStackedWidget* stackWgtSettings;

protected:


public:
    /*конструктор класса с параметром по умолчанию.
            Если при создании объкта на основе этого класса не будет передан адрес родительского класса,
            то созданный объект будет являтся объектом верхнего уровня */
    ffWndSetting(QWidget* parent = nullptr);

    // деструктор класса без параметра
    ~ffWndSetting(){};

private slots:
    void selectChangeGrpSettings();
};


#endif // FFWNDSETTINGS_H
