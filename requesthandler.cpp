#include "requesthandler.h"
#include "mainpartywidget.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestHandler::RequestHandler(MainPartyWidget* main_party_widget,
                               const QString& date) :
  main_party_widget_(main_party_widget){
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QUrl url("http://elritmo.pl/api.php?date=" + date);
    qDebug() << url.toString();
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager->get(request);  // GET
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(OnResult(QNetworkReply*)));
}

RequestHandler::~RequestHandler() {
}

void RequestHandler::OnResult(QNetworkReply* reply) {
    qDebug() << "on result" << reply->readAll();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObject = jsonDocument.object();
    QJsonArray array= jsonObject["results"].toArray();
    if (array.isEmpty()) {
      main_party_widget_->deleteRequest();
      return;
    }
    PrepaeAndSendResult(array);
    qDebug() << "json " ;
}

void RequestHandler::PrepaeAndSendResult(const QJsonArray array) {
  QVector<SinglePartyInfo>* party_infos = new QVector<SinglePartyInfo>();
  for (int i = 0; i < array.count(); ++i) {
    QJsonObject temp_object = array[i].toObject();
    SinglePartyInfo temp_single;
    temp_single.webpage = temp_object["webpage"].toString();
    party_infos->push_back(temp_single);
  }
  main_party_widget_->RequestedData(party_infos);
}
