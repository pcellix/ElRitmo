#include "partyinfo.h"
#include "requesthandler.h"

#include <QLabel>
#include <QWebView>
#include <QVBoxLayout>


PartyInfo::PartyInfo(const SinglePartyInfo& single_party, QWidget *parent) :
  QWidget(parent),
  webpage(new QLabel(this))
{
  QVBoxLayout* layout = new QVBoxLayout(this);
  this->setLayout(layout);
  webpage->setText(single_party.webpage);
  this->layout()->addWidget(webpage);
//  this->layout()->removeWidget(webpage);
}
