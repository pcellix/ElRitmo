#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "partyinfo.h"

#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QWidget>

class MainPartyWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MainPartyWidget(QWidget *parent = 0);
    void RequestedData();
public slots:
  void OnClick();
private:
  QVBoxLayout* layout_;
  QCalendarWidget* calendar_;
  PartyInfo* party_info_;
};

#endif // MAINWIDGET_Hcd
