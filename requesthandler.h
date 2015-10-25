#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QObject>

struct SinglePartyInfo {
    QString name;
    QString webpage;
};
class MainPartyWidget;
class QNetworkReply;
class QNetworkAccessManager;
class RequestHandler :  public QObject {
    Q_OBJECT
public:
    RequestHandler(MainPartyWidget* main_party_widget);
    ~RequestHandler();
    void MakeRequest(const QString& date);
private:
    void PrepareAndSendResult(const QJsonArray array);
    MainPartyWidget* main_party_widget_;
    QNetworkAccessManager* network_access_manager_;
public slots:
  void OnResult(QNetworkReply* reply);
};

#endif // REQUESTHANDLER_H
