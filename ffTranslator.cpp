#include "ffCoreApp.h"
#include "ffTranslator.h"

#include <QDebug>

#define ruRU "Russian"
#define enEN "English"

ffTranslator::ffTranslator(QObject* parent /*= nullptr*/) : QTranslator (parent)
{
    m_language[ruRU] = ffCoreApp::theApp()->applicationDirPath().append("/lang/fieryfish_ru.qm");
    m_language[enEN] = ffCoreApp::theApp()->applicationDirPath().append("/lang/fieryfish_en.qm");

    readLang();

    if(m_curLang.isEmpty()){
        m_curLang = m_language.firstKey();
        writeLang();
    }

    loadLocale();

    ffCoreApp::theApp()->installTranslator(this);

    mnuLanguage();
}

ffTranslator::~ffTranslator()
{

}

void ffTranslator::readLang()
{
    if(!ffCoreApp::theApp()->settings()->value("/Language/LANG").toString().isEmpty()){
        m_curLang = ffCoreApp::theApp()->settings()->value("/Language/LANG").toString();
    }
}

void ffTranslator::writeLang()
{
    ffCoreApp::theApp()->settings()->setValue("/Language/LANG",m_curLang);
}

void ffTranslator::loadLocale()
{
    this->load(m_language[m_curLang],".");
}

void ffTranslator::mnuLanguage()
{
    m_mnuLang = new QMenu(QObject::tr("MNULANGUAGE"));

    QAction* pactRu = new QAction(QObject::tr("RUSSIAN"), m_mnuLang);
    pactRu->setText(QObject::tr("RUSSIANTEXT"));
    pactRu->setToolTip(QObject::tr("RUSSIANTOOLTIP"));
    pactRu->setStatusTip(QObject::tr("RUSSIANSTATUSTIP"));
    pactRu->setWhatsThis(QObject::tr("RUSSIANWHATSTHIS"));

    QAction* pactEn = new QAction(QObject::tr("ENGLISH"), m_mnuLang);
    pactEn->setText(QObject::tr("ENGLISHTEXT"));
    pactEn->setToolTip(QObject::tr("ENGLISHTOOLTIP"));
    pactEn->setStatusTip(QObject::tr("ENGLISHSTATUSTIP"));
    pactEn->setWhatsThis(QObject::tr("ENGLISHWHATSTHIS"));

    m_mnuLang->addAction(pactRu);
    m_mnuLang->addAction(pactEn);

    connect(pactEn, &QAction::triggered , this, &ffTranslator::slotChangeLangEng);
    connect(pactRu, &QAction::triggered, this, &ffTranslator::slotChangeLangRu);
}

QMenu* ffTranslator::getMnuLang()
{
    return m_mnuLang;
}

void ffTranslator::changeLang(QString _str)
{
    m_curLang = _str;
    writeLang();
    emit sigChangeLang();
}

void ffTranslator::slotChangeLangEng()
{
    this->changeLang(enEN);
}

void ffTranslator::slotChangeLangRu()
{
    this->changeLang(ruRU);
}
