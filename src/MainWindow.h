#pragma once

#include <QMainWindow>

class QWidget;
class QLabel;
class QVBoxLayout;
class QString;




class MainWindow : public QMainWindow
{
    Q_OBJECT;

private:

    QVBoxLayout* m_mainLayout;




    void setUI();

public:
    MainWindow(QWidget* patent = nullptr);

    QString countLineEdit(QString lineEditStr);


};