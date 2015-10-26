#include "partyinfo.h"
#include "requesthandler.h"

#include <QLabel>
#include <QWebView>
#include <QVBoxLayout>


PartyInfo::PartyInfo(QVector<SinglePartyInfo>* singiel_parties, QWidget *parent) :
  QWidget(parent)
{
  QVBoxLayout* layout = new QVBoxLayout(this);
  this->setLayout(layout);
  foreach (SinglePartyInfo single_party, *singiel_parties) {
      QLabel *webpage = new QLabel(this);
      webpage->setText(single_party.webpage);
      this->layout()->addWidget(webpage);
  }
}
