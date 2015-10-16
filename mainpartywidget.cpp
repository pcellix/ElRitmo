#include "mainpartywidget.h"

MainPartyWidget::MainPartyWidget(QWidget *parent) :
  QWidget(parent),
  layout_(new QVBoxLayout(this)),
  calendar_(new CalendarWidget(this)),
  party_info_(new PartyInfo(this))
{
  layout_->addWidget(calendar_);
  layout_->addWidget(party_info_);
  this->setLayout(layout_);
}
