#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QObject>

struct SinglePartyInfo {
    QString name;
    QString webpage;
};
class MainPartyWidget;
class QNetworkReply;
class RequestHandler :  public QObject {
    Q_OBJECT
public:
    RequestHandler(MainPartyWidget* main_party_widget, const QString &date);
    ~RequestHandler();
    void MakeRequest();
private:void
    PrepaeAndSendResult(const QJsonArray array);
    MainPartyWidget* main_party_widget_;
public slots:
  void OnResult(QNetworkReply* reply);
};

#endif // REQUESTHANDLER_H
