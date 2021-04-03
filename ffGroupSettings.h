#ifndef FFGROUPSETTINGS_H
#define FFGROUPSETTINGS_H

//#include <QtWidgets>
#include <QListWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>


//========================================================================


/*!
 * \brief The GroupSetting class
Базовый класс логической группы элементов управления по настройке приложения
*/

class GroupSetting : public QGroupBox{
    Q_OBJECT
private:
public:
    GroupSetting(QWidget* pwgt = 0);
};


/*!
 * \brief The grpGeneralSettings class
Класс от логической группы настроек "Основные (общие) настройки приложения". В этой группе объединены элементы управления для изменения основных настроек приложения
*/

class grpGeneralSettings : public GroupSetting {
    Q_OBJECT
private:
public:
    grpGeneralSettings(QWidget* pwgt=0);
};

/*!
 * \brief The grpUsersSettings class
Класс от логической группы настроек "Пользователи". В этой группе объединены элементы управления для изменения основных настроек приложения
*/

class grpUsersSettings : public GroupSetting {
    Q_OBJECT
private:
    //список пользователей
    QListWidget* m_lwgtUsers;

    //Имя пользователя

    //Логин пользователя

    //пароль пользователя


    //галочка сохранять пароль или нет



    //testing widget
    QLabel*  m_lblUser;

public:
    grpUsersSettings(QWidget* pwgt=0);
};

/*!
 * \brief The grpConnectionsSettings class
Класс от логической группы настроек "Связи с БД". В этой группе объединены элементы управления для изменения основных настроек приложения
*/

class grpConnectionsSettings : public GroupSetting {
    Q_OBJECT
private:

    //список соединений к серверам
    QListWidget* m_lwgConnections;

    //кнопка добавить соединение
    QPushButton* m_pbAdd;
    //кнопка удалить соединение
    QPushButton* m_pbRemove;

    //адрес сервера
    QLineEdit* m_leIP;

    //порт сервера
    QLineEdit* m_lePort;

    //активное соединение
    QCheckBox* m_chkActive;

    //кнопка изменить соединение
    QPushButton* m_pbEdit;
    //кнопка сохранить изменения
    QPushButton* m_pbSave;

public:
    grpConnectionsSettings(QWidget* pwgt=0);
};

#endif // FFGROUPSETTINGS_H
