#include "mainpartywidget.h"

#include "jsonparser.h"

MainPartyWidget::MainPartyWidget(QWidget *parent) :
  QWidget(parent),
  layout_(new QVBoxLayout(this)),
  calendar_(new QCalendarWidget(this)),
  party_info_(new PartyInfo(this))
{
  connect(calendar_, SIGNAL(clicked(QDate)), SLOT(OnClick()));
  layout_->addWidget(calendar_);
  layout_->addWidget(party_info_);
  this->setLayout(layout_);
}

void MainPartyWidget::OnClick() {
    qDebug() << "aaaaaa";
    JsonParser* request = new JsonParser(this);
}

void MainPartyWidget::RequestedData() {
  qDebug() << "Requested data called";
}

