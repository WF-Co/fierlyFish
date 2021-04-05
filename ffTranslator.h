/*!
\file
\brief Модуль локализации приложения fieryFish
\author Ершов Виктор
\version 0.0.001
\date Февраль 2021 года

*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QTranslator>
#include <QMap>
#include <QString>
#include <QMenu>
#include <QAction>


/*!
 * \brief Класс локализации приложения
 */
class ffTranslator : public QTranslator
{
  Q_OBJECT

private:
    //! переменная содержащая значение текущей выбранной локализации
    QString m_curLang;
    //! указатель на QMap содержащий доступные ключ-значение по локализации приложения
    QMap<QString, QString> m_language;
    //! укаазатель на меню локализации
    QMenu* m_mnuLang;

    //! метод чтения настроек и файлов локализации приложения
    void readLang();

    //! метод записи настроек и файлов локализации приложения
    void writeLang();

    //! метод загрузки выбранной локализации
    void loadLocale();
    //! метод вызова меню локализации
    void mnuLanguage();
    //! метод смены локализации выбранной пользователем
    void changeLang(QString);
public:
    //! конструктор класса
    ffTranslator(QObject* parent = nullptr);
    ~ffTranslator();

    //! указатель на меню локализации
    QMenu* getMnuLang();

private slots:
    //! слот смены локализации на русский язык
    void slotChangeLangRu();
    //! слот смены локализации на английский язык
    void slotChangeLangEng();

signals:
    //! сигнал о смене локализации
    void sigChangeLang();
};

#endif // TRANSLATOR_H
