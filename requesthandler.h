#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QObject>

struct SinglePartyInfo {
    QString name;
    QString location;
};
class MainPartyWidget;
class QNetworkReply;
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
