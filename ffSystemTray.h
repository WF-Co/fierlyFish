/*!
\file
\brief Системный трей приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Март 2021 года

*/

#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include "ffMDIWindow.h"

/*!
 * \brief Класс иконки в системном трее
 */
class ffSystemTray : public ffMDIWindow {
    Q_OBJECT

private:
    //! указатель на иконку в системном трее
    QSystemTrayIcon*    m_ptrayIcon;
    //! указатель на контекстное меню иконки системного трея
    QMenu*              m_ptrayIconMenu;

protected:
    //! метод ????????
    void closeEvent(QCloseEvent*);

public:
    //! конструктор класса
    ffSystemTray(QWidget* pwgt = nullptr);
    ~ffSystemTray();

public slots:
    //! слот показа/скрытия главного окна приложения
    void slotShowHide    ();
    //! слот реакции на действие активации иконки в системном трее
    void onTrayIconActivated( QSystemTrayIcon::ActivationReason reason);

};

#endif // SYSTEMTRAY_H
