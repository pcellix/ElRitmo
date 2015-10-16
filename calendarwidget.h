#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QWidget>

class CalendarWidget : public QWidget
{
  Q_OBJECT
 public:
  explicit CalendarWidget(QWidget *parent = 0);
  ~CalendarWidget() { }
 private:
  QVBoxLayout* layout_;
  QCalendarWidget* calendar_;

};

#endif // CALENDARWIDGET_H
