#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "mainpartywidget.h"

#include <QObject>
#include <QString>
#include <QNetworkReply>

struct SinglePartyInfo {
    QString name;
    QString location;
};

class JsonParser :  public QObject {
    Q_OBJECT
public:
    JsonParser(MainPartyWidget* main_party_widget);
    ~JsonParser();
    void MakeRequest();
private:
    MainPartyWidget* main_party_widget_;
public slots:
  void OnResult(QNetworkReply* reply);
};

#endif // JSONPARSER_H
