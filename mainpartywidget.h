#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMap>
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

public slots:
  void OnClick(const QDate &date);
private:
  QVBoxLayout* layout_;
  QCalendarWidget* calendar_;
  QVBoxLayout* party_info_layout_;
  RequestHandler* request_;
  QMap<QString, PartyInfo*> map;
};

#endif // MAINWIDGET_Hcd
