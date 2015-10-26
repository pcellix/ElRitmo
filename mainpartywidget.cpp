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
  party_info_layout_(new QVBoxLayout(this)),
  request_(new RequestHandler(this))
{
  connect(calendar_, SIGNAL(clicked(QDate)), SLOT(OnClick(QDate)));
  layout_->addLayout(party_info_layout_);
  layout_->addWidget(calendar_);
  this->setLayout(layout_);
}

void MainPartyWidget::OnClick(const QDate& date) {
    qDebug() << "aaaaaa";
    request_->MakeRequest(date.toString("yyyy-MM-dd"));
}

void MainPartyWidget::RequestedData(QVector<SinglePartyInfo>* wektor) {
  foreach (SinglePartyInfo single_party, *wektor) {
      party_info_layout_->addWidget(new PartyInfo(single_party, this));
      delete wektor;
  }
}



