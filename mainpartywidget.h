#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "calendarwidget.h"
#include "partyinfo.h"

#include <QVBoxLayout>
#include <QWidget>

class MainPartyWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MainPartyWidget(QWidget *parent = 0);
private:
  QVBoxLayout* layout_;
  CalendarWidget* calendar_;
  PartyInfo* party_info_;

signals:

public slots:

};

#endif // MAINWIDGET_Hcd
