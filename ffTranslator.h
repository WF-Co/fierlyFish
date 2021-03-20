#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QTranslator>
#include <QMap>
#include <QString>
#include <QMenu>
#include <QAction>

class ffTranslator : public QTranslator
{
  Q_OBJECT

private:
    QString m_curLang;
    QMap<QString, QString> m_language;
    QMenu* m_mnuLang;

    void readLang();
    void writeLang();
    void loadLocale();
    void mnuLanguage();
    void changeLang(QString);
public:
    ffTranslator(QObject* parent = nullptr);
    ~ffTranslator();

    QMenu* getMnuLang();

private slots:
    void slotChangeLangRu();
    void slotChangeLangEng();

signals:
    void sigChangeLang();
};

#endif // TRANSLATOR_H
