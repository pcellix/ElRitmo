#include "mainpartywidget.h"

#include "requesthandler.h"

MainPartyWidget::MainPartyWidget(QWidget *parent) :
  QWidget(parent),
  layout_(new QVBoxLayout(this)),
  calendar_(new QCalendarWidget(this)),
  party_info_(new PartyInfo(this)),
  request_(0)
{
  connect(calendar_, SIGNAL(clicked(QDate)), SLOT(OnClick()));
  layout_->addWidget(calendar_);
  layout_->addWidget(party_info_);
  this->setLayout(layout_);
}

void MainPartyWidget::OnClick() {
    qDebug() << "aaaaaa";
    request_ = new RequestHandler(this);
}

void MainPartyWidget::RequestedData() {
  qDebug() << "Requested data called";
  if (request_) {
    delete request_;
    request_ = 0;
  }
}

