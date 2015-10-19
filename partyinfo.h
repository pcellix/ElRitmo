#ifndef PARTYINFO_H
#define PARTYINFO_H

#include <QWidget>

class QLabel;
class QVBoxLayout;

class PartyInfo : public QWidget
{
  Q_OBJECT
public:
  explicit PartyInfo(QWidget *parent = 0);

private:
  QVBoxLayout* layout_;
  QLabel* name_;
  QLabel* date_;
signals:

public slots:

};
#endif // PARTYINFO_H
