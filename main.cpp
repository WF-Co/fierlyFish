//Включаем пользовательские заголовочные файлы
#include "ffCoreApp.h"

//основная функция приложения (точка входа)
int main(int argc, char *argv[])
{
    /*создаем объект cApp на основе пользовательского класса coreApp.
            Это основной класс приложения, который осуществляет контроль и управление всем приложением. */

    ffCoreApp cApp(argc, argv, "WFCo", "FieryFish");

    ffCoreApp::setQuitOnLastWindowClosed(false);

    //запускаем приложение вызовом .exec(). Таким образом приводиться в действие цикл обработки событий, определенный в классе QCoreApplication.
    return cApp.exec();
}
