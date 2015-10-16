#include "calendarwidget.h"
#include <QWidget>
#include <QCalendarWidget>

CalendarWidget::CalendarWidget(QWidget *parent) :
  calendar_(new QCalendarWidget(this)) {

}
