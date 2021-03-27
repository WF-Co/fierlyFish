//#include <QtWidgets>

#include "ffCoreApp.h"
#include "ffWndSettings.h"

//==============================================================================

ffWndSetting::ffWndSetting(QWidget *parent):QDialog(parent)
{
    //список наименований логических групп настроек приложения
    QStringList lst;

    //Widgets
    QListWidgetItem* pitem = 0;

    stackWgtSettings = new QStackedWidget(this);

    //создаем список групп настроек приложения
    lwgSettings = new QListWidget(this);
    //задаем размер иконок(пиктограмм) в списке виджетов
    lwgSettings->setIconSize(QSize(48,48));

    //подготавливаем список групп настроек
    lst << QObject::tr("GENERAL_SETTINGS") << QObject::tr("USERS") << QObject::tr("CONNECTIONS_DATABASES");

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
              //создаем виджет пользователей(аккаунтов)
              grpUsersSettings*  pgrpUS = new grpUsersSettings;
              //размещаем в конец контейнера виджетов указатель созданного виджета логической группы настроек
              stackWgtSettings->addWidget(pgrpUS);
              break;
            }
          case 2:
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

   //Layout
    QHBoxLayout* phbxLayout = new QHBoxLayout;

    //устанавливаем толщину рамки в 10 пикселов со всех четырех сторон
    phbxLayout->setContentsMargins(10,10,10,10);

    //задаем расстояние между виджетами. 20 пикселей
    phbxLayout->setSpacing(20);

    //добавляем виджеты на создаваемый слой компановки
    phbxLayout->addWidget(lwgSettings);
    phbxLayout->addWidget(stackWgtSettings);

    //устанавливаем созданный слой компановки
    setLayout(phbxLayout);
}

void ffWndSetting::selectChangeGrpSettings()
{
    stackWgtSettings->setCurrentIndex(lwgSettings->row(lwgSettings->currentItem()));
}
