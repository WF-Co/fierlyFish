//#include <QtWidgets>
#include <QObject>
#include "ffCoreApp.h"
#include "ffWndSettings.h"

//==============================================================================

ffWndSetting::ffWndSetting(QWidget *parent):QDialog(parent)
{
    //устанавливаем заголовок диалоговому окну
    this->setWindowTitle(QObject::tr("SETTINGS_APPLICATION_FIERYFISH"));

    //устанавливаем флаги диалогового окна. Убираем знак вопроса из заголовка
    this->setWindowFlags(Qt::WindowTitleHint | Qt::WindowSystemMenuHint);

    //список наименований логических групп настроек приложения
    QStringList lst;

    //Widgets
    QListWidgetItem* pitem = 0;

    //создаем стек виджетов сгруппированных по группам
    stackWgtSettings = new QStackedWidget(this);

    //создаем список групп настроек приложения
    lwgSettings = new QListWidget(this);
    //задаем размер иконок(пиктограмм) в списке виджетов
    lwgSettings->setIconSize(QSize(48,48));

    //подготавливаем список групп настроек
    lst << QObject::tr("GENERAL_SETTINGS") << QObject::tr("CONNECTIONS_DATABASES");

    //заполняем QListWidget созданным списком
    foreach(QString str, lst)
    {
        //создаем элемент списка виждетов
        pitem = new QListWidgetItem(str, lwgSettings);
        //устанавливаем иконку для созданного элемента
        pitem->setIcon(QPixmap(":/" + str + ".png"));

        //добавляем виджет в слой компановки
       switch(lwgSettings->row(pitem))
        {
        case 0:
            {
              //создаем виджет основных (общих) настроек приложения
              grpGeneralSettings* pgrpGS = new grpGeneralSettings;
              //размещаем в конец контейнера виджетов указатель созданного виджета логической группы настроек
              stackWgtSettings->addWidget(pgrpGS);
              break;
            }
          case 1:
           {
              //создаем виджет соединений с БД
              grpConnectionsSettings* pgrpCS = new grpConnectionsSettings;
              //размещаем в конец контейнера виджетов указатель созданного виджета логической группы настроек
              stackWgtSettings->addWidget(pgrpCS);
              break;
           }
        }
    }

    //устанавливаем размер виджета
    lwgSettings->resize(125,320);

    //Connection
   connect(lwgSettings, &QListWidget::clicked, this, &ffWndSetting::selectChangeGrpSettings);

    //Создаем слой компановки 2 уровня, где размещаем список групп настроек и стек виджетов (сгруппированных)
    QHBoxLayout* phbxElemLayout_level2 = new QHBoxLayout;

    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    phbxElemLayout_level2->setContentsMargins(10,10,10,10);

    //задаем расстояние между виджетами. 20 пикселей
    phbxElemLayout_level2->setSpacing(20);

    //добавляем виджеты на создаваемый слой компановки
    phbxElemLayout_level2->addWidget(lwgSettings);
    phbxElemLayout_level2->addWidget(stackWgtSettings);

    //Создаем слой компаноки 1 уровня в нем размещаем сверху слой компаноки 2 уровня и кнопки снизу "ОК", "Применить", "Отмена"
    QVBoxLayout* pvbxLayoutGeneral = new QVBoxLayout;
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    pvbxLayoutGeneral->setContentsMargins(10,10,10,10);

    QPushButton* ptPBOk = new QPushButton(QObject::tr("OK"), this);
    connect(ptPBOk, &QPushButton::clicked, this, &ffWndSetting::accept);

    QPushButton* ptPBAccept = new QPushButton(QObject::tr("ACCEPT"),this);
    connect(ptPBAccept, &QPushButton::clicked, this, &ffWndSetting::accept);

    QPushButton* ptPBCancel = new  QPushButton(QObject::tr("CANCEL"), this);
    connect(ptPBCancel, &QPushButton::clicked, this, &ffWndSetting::close);

    //Создаем слой компановки 2 уровня для QPushButton управления диалоговым окном
    QHBoxLayout* phbxPBLayout_level2 = new QHBoxLayout;
    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    phbxPBLayout_level2->setContentsMargins(10,10,10,10);
    //Вставляем в начало отступ
    phbxPBLayout_level2->addSpacing(50);
    //Добавляем по очереди кнопки "ОК", "Применить", "Отмена"
    phbxPBLayout_level2->addWidget(ptPBOk);
    phbxPBLayout_level2->addWidget(ptPBAccept);
    phbxPBLayout_level2->addWidget(ptPBCancel);


    //Добавляем слой компановки 2 уровня
    pvbxLayoutGeneral->addLayout(phbxElemLayout_level2);
    pvbxLayoutGeneral->addLayout(phbxPBLayout_level2);

    //устанавливаем созданный слой компановки 1 уровня
    setLayout(pvbxLayoutGeneral);
}

void ffWndSetting::selectChangeGrpSettings()
{
    stackWgtSettings->setCurrentIndex(lwgSettings->row(lwgSettings->currentItem()));
}
