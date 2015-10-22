#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QVector>
class PartyInfo;
class RequestHandler;
struct SinglePartyInfo;
class QCalendarWidget;
class QVBoxLayout;
class MainPartyWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MainPartyWidget(QWidget *parent = 0);
    void RequestedData(QVector<SinglePartyInfo>*);
    void deleteRequest();

public slots:
  void OnClick(const QDate &date);
private:
  QVBoxLayout* layout_;
  QCalendarWidget* calendar_;
  PartyInfo* party_info_;
  RequestHandler* request_;
};

#endif // MAINWIDGET_Hcd
