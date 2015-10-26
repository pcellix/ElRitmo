#ifndef PARTYINFO_H
#define PARTYINFO_H

#include <QWidget>
#include <QLabel>
struct SinglePartyInfo;
struct PartyInfo : public QWidget
{
  Q_OBJECT
 public:
  explicit PartyInfo(const SinglePartyInfo& singiel_party,
            QWidget *parent = 0);
  QLabel* webpage;

};
#endif // PARTYINFO_H
