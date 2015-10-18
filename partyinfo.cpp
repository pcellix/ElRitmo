#include "partyinfo.h"

PartyInfo::PartyInfo(QWidget *parent) :
  QWidget(parent),
  layout_(new QVBoxLayout(parent)),
  name_(new QLabel(this)),
  date_(new QLabel(this))
 // webview_(new QWebView(this))
{
  name_->setText("dasas");
  layout_->addWidget(name_);
  layout_->addWidget(date_);
  this->setLayout(layout_);
 // layout_->addWidget(webview_);
}
