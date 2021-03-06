#ifndef UKCCSESSIONSERVER_H
#define UKCCSESSIONSERVER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QVariantMap>
#include <QCoreApplication>
#include <QDBusContext>
#include <QScopedPointer>

#include "json.h"

using QtJson::JsonObject;
using QtJson::JsonArray;

class ukccSessionServer : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.ukui.ukcc.session.interface")
public:
    explicit ukccSessionServer();

private:
    QMap<QString, QVariant> getJsonInfo(const  QString &confFile);


Q_SIGNALS:
    void configChanged();

public slots:
    void exitService();
    void        ReloadSecurityConfig();
    QVariantMap getModuleHideStatus();
    QString     GetSecurityConfigPath();

};

#endif // UKCCSESSIONSERVER_H
