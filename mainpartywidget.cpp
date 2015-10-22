#include "mainpartywidget.h"
#include "partyinfo.h"
#include "requesthandler.h"

#include <QDebug>
#include <QCalendarWidget>
#include <QVBoxLayout>

MainPartyWidget::MainPartyWidget(QWidget *parent) :
  QWidget(parent),
  layout_(new QVBoxLayout(this)),
  calendar_(new QCalendarWidget(this)),
  party_info_(new PartyInfo(this)),
  request_(0)
{
  connect(calendar_, SIGNAL(clicked(QDate)), SLOT(OnClick(QDate)));
  layout_->addWidget(calendar_);
  layout_->addWidget(party_info_);
  this->setLayout(layout_);
}

void MainPartyWidget::OnClick(const QDate& date) {
    qDebug() << "aaaaaa";
    request_ = new RequestHandler(this, date.toString("yyyy-MM-dd"));
}

void MainPartyWidget::RequestedData(QVector<SinglePartyInfo>* wektor) {
  qDebug() << "Requested data called " << wektor->at(0).webpage;
  deleteRequest();
}

void MainPartyWidget::deleteRequest() {
  if (request_) {
    delete request_;
    request_ = 0;
  }
}


