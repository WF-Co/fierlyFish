/*!
\file
\brief Классы сгруппированных настроек для окна Настроек приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Март 2021 года

*/

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
    //! конструктор класса
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
    //! конструктор класса
    grpGeneralSettings(QWidget* pwgt=0);
};

/*!
 * \brief The grpConnectionsSettings class
Класс от логической группы настроек "Связи с БД". В этой группе объединены элементы управления для изменения основных настроек приложения
*/

class grpConnectionsSettings : public GroupSetting {
    Q_OBJECT
private:

    //список соединений к серверам
    //! указатель на список сохраненных соединений с сервером СУБД
    QListWidget* m_lwgConnections;

    //кнопка добавить соединение
    //! указатель на кнопку добавить соединение
    QPushButton* m_pbAdd;

    //кнопка удалить соединение
    //! указатель на кнопку удалить соединение
    QPushButton* m_pbRemove;

    //адрес сервера
    //! указатель на текстовое поле с IP адресом сервера СУБД
    QLineEdit* m_leIP;

    //порт сервера
    //! указатель на текстовое поле с портом сервера СУБД
    QLineEdit* m_lePort;

    //активное соединение
    //! указатель на чекбокс (отметка) о активном (по умолчанию) соединения
    QCheckBox* m_chkActive;

    //кнопка изменить соединение
    //! указатель на кнопку изменить выбранное соединение
    QPushButton* m_pbEdit;
    //кнопка сохранить изменения
    //! указатель на кнопку сохранить измененное соединение
    QPushButton* m_pbSave;

public:
    //! конструктор класса
    grpConnectionsSettings(QWidget* pwgt=0);
};

#endif // FFGROUPSETTINGS_H
