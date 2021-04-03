#include "ffGroupSettings.h"

//==========================================================================

//====================== GroupSettings =====================================
GroupSetting::GroupSetting(QWidget* pwgt) : QGroupBox(pwgt)
{

}

//====================== grpGeneralSettings ================================

grpGeneralSettings::grpGeneralSettings(QWidget* pwgt) : GroupSetting(pwgt)
{
    this->setTitle(QObject::tr("GENERAL_SETTINGS"));
}

//====================== grpUsersSettings ================================

grpUsersSettings::grpUsersSettings(QWidget* pwgt) : GroupSetting(pwgt)
{
    QListWidgetItem* pitem = 0;
    QStringList lst;


    this->setTitle(QObject::tr("USERS"));

    m_lwgtUsers = new QListWidget(this);
    m_lwgtUsers->setIconSize(QSize(48,48));

    //подготавливаем список групп настроек

    lst << QObject::tr("USER_1") << QObject::tr("USER_2") << QObject::tr("USER_3");

    foreach(QString str, lst)
    {
      //создаем элемент списка виждетов
      pitem = new QListWidgetItem(str, m_lwgtUsers);
      //устанавливаем иконку для созданного элемента
      pitem->setIcon(QPixmap(":/" + str + ".png"));
    }

    m_lwgtUsers->resize(125,320);



    m_lblUser = new QLabel(QObject::tr("TESTINGS_TEXT"));


    QHBoxLayout* layoutHBox = new QHBoxLayout;


    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layoutHBox->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layoutHBox->setSpacing(20);

    //добавляем виджеты на создаваемый слой компановки
    layoutHBox->addWidget(m_lwgtUsers);
     layoutHBox->addWidget(m_lblUser);

    //устанавливаем созданный слой компановки
    setLayout(layoutHBox);
}

//====================== grpConnectionsSettings ================================

grpConnectionsSettings::grpConnectionsSettings(QWidget* pwgt) : GroupSetting(pwgt)
{
    this->setTitle(QObject::tr("CONNECTIONS_DATABASES"));

    QListWidgetItem* pitem = 0;
    QStringList lst;

    //создаем элементы управления
    //кнопка добавить
    m_pbAdd = new QPushButton(QObject::tr("PB_ADD"));
    //кнопка удалить
    m_pbRemove = new QPushButton(QObject::tr("PB_REMOVE"));
    //список сохраненных соединений
    m_lwgConnections = new QListWidget(this);
    //изменяем размер иконок (пиктограмм) в списке соединений
    m_lwgConnections->setIconSize(QSize(48,48));

    //подготавливаем список групп настроек
    lst << QObject::tr("CONNECTION_1") << QObject::tr("CONNECTION_2") << QObject::tr("CONNECTION_3");

    foreach(QString str, lst)
    {
      //создаем элемент списка виждетов
      pitem = new QListWidgetItem(str, m_lwgConnections);
      //устанавливаем иконку для созданного элемента
      pitem->setIcon(QPixmap(":/" + str + ".png"));
    }

    //устанавливаем размер списка
    m_lwgConnections->resize(125,320);

    //создаем горизонтальный слой компаноки для кнопок m_pbAdd, m_pbRemove
    QHBoxLayout* layLVBPushB = new QHBoxLayout;
    //настраиваем слой компаноки
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layLVBPushB->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layLVBPushB->setSpacing(20);

    //добавляем виджеты(кнопки) в слой компановки
    layLVBPushB->addWidget(m_pbAdd);
    layLVBPushB->addWidget(m_pbRemove);

    //создаем и инициализируем вертикальный слой компановки для списка сохраненных соединений с сервером
    QVBoxLayout* layLeftVBox = new QVBoxLayout;
    //настраиваем слой компаноки
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layLeftVBox->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layLeftVBox->setSpacing(20);

    //добавляем список соединений
    layLeftVBox->addWidget(m_lwgConnections);
    //добавляем горизонтальный слой компановки с кнопками
    layLeftVBox->addLayout(layLVBPushB);

    //инициализируем объекты с параметрами настроек для редактирования
    //адрес сервера
    m_leIP = new QLineEdit(QObject::tr("IP address"));
    //порт сервера
    m_lePort = new QLineEdit(QObject::tr("Port"));
    //флаг активного соединения
    m_chkActive = new QCheckBox;

    //кнопка редактировать m_pbEdit
    m_pbEdit = new QPushButton(QObject::tr("PB_EDIT"));
    //кнопка сохранить изменения m_pbSave
    m_pbSave = new QPushButton(QObject::tr("PB_SAVE"));

    //создаем и инициализируем слой компановки для кнопок m_pbEdit, m_pbSave
    QHBoxLayout* layRVBPushB = new QHBoxLayout;
    //настраиваем слой компаноки
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layRVBPushB->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layRVBPushB->setSpacing(20);
    //добавляем кнопки на созданный слой компановки
    layRVBPushB->addWidget(m_pbEdit);
    layRVBPushB->addWidget(m_pbSave);

    //создаем и инициализируем вертикальный слой компановки для m_leIP, m_lePort, m_chkActive
    QVBoxLayout* layRightVBox = new QVBoxLayout;

    //настраиваем слой компаноки
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layRightVBox->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layRightVBox->setSpacing(20);

    //добавляем виджеты на слой компаноки
    layRightVBox->addWidget(m_leIP);
    layRightVBox->addWidget(m_lePort);
    layRightVBox->addWidget(m_chkActive);
    layRightVBox->addStretch(1);
    //добавляем слой компановки с кнопками m_pbEdit, m_pbSave
    layRightVBox->addLayout(layRVBPushB);

    //создаем и инициализируем основной слой компановки
    QHBoxLayout* layoutHBox = new QHBoxLayout;

    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    layoutHBox->setContentsMargins(10,10,10,10);
    //задаем расстояние между виджетами. 20 пикселей
    layoutHBox->setSpacing(20);

    //добавляем ранее созданные слои компановки на создаваемый слой компановки
    //слой со списком сохраненных соединений
    layoutHBox->addLayout(layLeftVBox);
    //слой с элементами управления для чтения сохраненных настроек и их изменения
    layoutHBox->addLayout(layRightVBox);

    //устанавливаем созданный основной слой компановки
    setLayout(layoutHBox);
}
