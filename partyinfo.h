#ifndef PARTYINFO_H
#define PARTYINFO_H

#include <QWidget>
#include <QLabel>
#include <QWebView>
#include <QVBoxLayout>
class PartyInfo : public QWidget
{
  Q_OBJECT
public:
  explicit PartyInfo(QWidget *parent = 0);

private:
  QVBoxLayout* layout_;
  QLabel* name_;
  QLabel* date_;
  QWebView webview_;
signals:

public slots:

};

#endif // PARTYINFO_H
