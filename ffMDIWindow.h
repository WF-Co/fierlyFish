/*!
\file
\brief Основное окно приложения приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Февраль 2020 года

*/

#ifndef MAINWND_H
#define MAINWND_H
//включаем заголовочные файлы Qt
#include <QSettings>
#include <QApplication>
#include <QMainWindow>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QDateTimeEdit>
#include <QLabel>

//#include "ffWndSettings.h"


//определяем основной класс приложения (главное окно). Класс MainWnd унаследован от класса QMainWindow
/*!
 * \brief Класс главного окна приложения
 *
 * Класс основного (главного) окна приложения.
 */
class ffMDIWindow : public QMainWindow
{
    //специфичный макрос для распознания класса в МОС (метаобъектный компилятор), который нуждается в подробной переработке.
    Q_OBJECT

public:
    /*конструктор класса с параметром по умолчанию.
            Если при создании объкта на основе этого класса не будет передан адрес родительского класса,
            то созданный объект будет являтся объектом верхнего уровня */
    //! конструктор класса
    ffMDIWindow(QWidget* parent = nullptr);

    // деструктор класса без параметра
    ~ffMDIWindow();

    //! метод записи настроек приложения
    void writeSettings();

    //! метод чтения настроек приложения
    void readSettings();

protected:
    //! метод создания статус-бара для главного окна приложения
    void createStatusBar();

private slots:

signals:
    //! сигнал о сохранении настроек
    void signalSettings();

private:
    //! указатель на MDI поле
    QMdiArea*       m_pma;
    //! указатель на главное меню приложения
    QMenu*          m_pmnuWindows;

    //! указатель на QLabel содержащий дату для статус-бара
    QLabel*         m_pstatDateLabel;

};
#endif // MAINWND_H
