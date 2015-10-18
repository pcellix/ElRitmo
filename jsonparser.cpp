#include "jsonparser.h"

#include <QString>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

JsonParser::JsonParser(MainPartyWidget* main_party_widget) :
  main_party_widget_(main_party_widget){
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QUrl url("http://czytowyplata.modernweb.pl");
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager->get(request);  // GET
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(OnResult(QNetworkReply*)));
}

JsonParser::~JsonParser() {

}

void JsonParser::OnResult(QNetworkReply* reply) {
    qDebug() << "on result";
    if (reply ->error() != QNetworkReply::NoError)
        return;  // ...only in a blog post
    QString data = (QString) reply->readAll();
     qDebug() << "Date:" << data;
     main_party_widget_->RequestedData();
}
