#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "mainpartywidget.h"

#include <QObject>
#include <QString>
#include <QNetworkReply>

struct SinglePartyInfo {
    QString name;
    QString location;
};

class RequestHandler :  public QObject {
    Q_OBJECT
public:
    RequestHandler(MainPartyWidget* main_party_widget);
    ~RequestHandler();
    void MakeRequest();
private:
    MainPartyWidget* main_party_widget_;
public slots:
  void OnResult(QNetworkReply* reply);
};

#endif // REQUESTHANDLER_H
