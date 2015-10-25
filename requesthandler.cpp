#include "requesthandler.h"
#include "mainpartywidget.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestHandler::RequestHandler(MainPartyWidget* main_party_widget) :
  main_party_widget_(main_party_widget) {
    network_access_manager_ = new QNetworkAccessManager(this);
    connect(network_access_manager_, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(OnResult(QNetworkReply*)));
}

void RequestHandler::MakeRequest(const QString& date) {
    QUrl url("http://elritmo.pl/api.php?date=" + date);
    qDebug() << url.toString();
    QNetworkRequest request;
    request.setUrl(url);
    network_access_manager_->get(request);
}

RequestHandler::~RequestHandler() {
}

void RequestHandler::OnResult(QNetworkReply* reply) {
    qDebug() << "on result" << reply->readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObject = jsonDocument.object();
    QString status("status");
    status.toUtf8();
    QJsonArray array = jsonObject["results"].toArray();
    if (array.isEmpty()) {
      return;
    }
    PrepareAndSendResult(array);
}

void RequestHandler::PrepareAndSendResult(const QJsonArray array) {
  QVector<SinglePartyInfo>* party_infos = new QVector<SinglePartyInfo>();
  for (int i = 0; i < array.count(); ++i) {
    QJsonObject temp_object = array[i].toObject();
    SinglePartyInfo temp_single;
    temp_single.webpage = temp_object["webpage"].toString();
    party_infos->push_back(temp_single);
  }
  main_party_widget_->RequestedData(party_infos);
}
