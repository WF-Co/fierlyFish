#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include "ffMDIWindow.h"

class ffSystemTray : public ffMDIWindow {
    Q_OBJECT

private:
    QSystemTrayIcon*    m_ptrayIcon;
    QMenu*              m_ptrayIconMenu;

protected:
    void closeEvent(QCloseEvent*);

public:
    ffSystemTray(QWidget* pwgt = nullptr);
    ~ffSystemTray();

public slots:
    void slotShowHide    ();
    void onTrayIconActivated( QSystemTrayIcon::ActivationReason reason);
};

#endif // SYSTEMTRAY_H
