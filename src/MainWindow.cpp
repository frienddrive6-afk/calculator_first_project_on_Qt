#include "MainWindow.h"

#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QList>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    setUI();
}


void MainWindow::setUI()
{
    setWindowTitle("Qt Trenning");
    resize(360, 550);
    setStyleSheet("background-color: #f3f3f3;");       // Светло-серый фон (как на iOS)

    
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    m_mainLayout = new QVBoxLayout(centralWidget);

    centralWidget->setLayout(m_mainLayout);

    m_mainLayout->setSpacing(10);          // Расстояние между кнопками
    m_mainLayout->setContentsMargins(15, 15, 15, 15); // Отступы от краев окна


    QLineEdit* lineEdit = new QLineEdit();

    lineEdit->setAlignment(Qt::AlignRight);    // Выравнивание текста в право
    lineEdit->setReadOnly(true);
    lineEdit->setStyleSheet(
    "font-size: 40px;"
    "font-family: Arial;"
    "border: none;"
    "background: transparent;"
    "color: #202020;" // Почти черный цвет
    ); 




    
    m_mainLayout->addWidget(lineEdit);

    
    
    QHBoxLayout* line1 = new QHBoxLayout();
    line1->setSpacing(4);
    
    QPushButton* seven = new QPushButton("7");
    QPushButton* eight = new QPushButton("8");
    QPushButton* nine = new QPushButton("9");
    QPushButton* del = new QPushButton(" / ");

    line1->addWidget(seven);
    line1->addWidget(eight);
    line1->addWidget(nine);
    line1->addWidget(del);

    m_mainLayout->addLayout(line1);



    QHBoxLayout* line2 = new QHBoxLayout();
    line2->setSpacing(4);
    
    QPushButton* four = new QPushButton("4");
    QPushButton* five = new QPushButton("5");
    QPushButton* six = new QPushButton("6");
    QPushButton* mnog = new QPushButton(" * ");

    line2->addWidget(four);
    line2->addWidget(five);
    line2->addWidget(six);
    line2->addWidget(mnog);

    m_mainLayout->addLayout(line2);



    QHBoxLayout* line3 = new QHBoxLayout();
    line3->setSpacing(4);
    
    QPushButton* one = new QPushButton("1");
    QPushButton* two = new QPushButton("2");
    QPushButton* thee = new QPushButton("3");
    QPushButton* minus = new QPushButton(" - ");

    line3->addWidget(one);
    line3->addWidget(two);
    line3->addWidget(thee);
    line3->addWidget(minus);

    m_mainLayout->addLayout(line3);


    QHBoxLayout* line4 = new QHBoxLayout();
    line4->setSpacing(4);
    
    QPushButton* zero = new QPushButton("0");
    QPushButton* ravno = new QPushButton(" = ");
    QPushButton* plus = new QPushButton(" + ");
    QPushButton* tochka = new QPushButton(".");
    QPushButton* clear = new QPushButton("C");

    ravno->setStyleSheet(
    "background-color: #ff9f43;" // Оранжевый
    "color: white;"              // Белый текст
    "border: none;"
    "border-radius: 10px;"
    "font-weight: bold;"
    "font-size: 24px;"
    );

    QString greyStyle = 
    "background-color: #e0e0e0;"
    "border: 1px solid #cccccc;"
    "border-radius: 10px;"
    "font-size: 20px;";

    clear->setStyleSheet(greyStyle);
    del->setStyleSheet(greyStyle);
    plus->setStyleSheet(greyStyle);
    minus->setStyleSheet(greyStyle);
    mnog->setStyleSheet(greyStyle);


    line4->addWidget(zero);
    line4->addWidget(ravno);
    line4->addWidget(plus);
    line4->addWidget(tochka);
    line4->addWidget(clear);

    m_mainLayout->addLayout(line4);


    connect(one, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "1");
    });

    connect(two, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "2");
    });
    
    connect(thee, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "3");
    });

    connect(four, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "4");
    });

    connect(five, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "5");
    });

    connect(six, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "6");
    });

    connect(seven, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "7");
    });

    connect(eight, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "8");
    });

    connect(nine, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "9");
    });

    connect(zero, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "0");
    });

    connect(del, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + " / ");
    });

    connect(ravno, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + "=");
        lineEdit->setText(countLineEdit(lineEdit->text()));
    });

    connect(mnog, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + " * ");
    });

    connect(minus, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + " - ");
    });

    connect(plus, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + " + ");
    });

    connect(tochka, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText(lineEdit->text() + ".");
    });

    connect(clear, &QPushButton::clicked, lineEdit, [=](){
        lineEdit->setText("");
    });




    m_mainLayout->addStretch();



    this->setStyleSheet(
    "QWidget { background-color: #f3f3f3; }" // Фон окна
    
    "QPushButton {"
    "   background-color: #ffffff;"      // Белые кнопки
    "   border: 1px solid #dcdcdc;"      // Тонкая серая рамка
    "   border-radius: 10px;"            // Закругленные углы (как на фото)
    "   font-size: 20px;"                // Размер цифр
    "   color: #333333;"                 // Цвет цифр
    "   min-width: 60px;"                // Минимальная ширина
    "   min-height: 60px;"               // Минимальная высота (чтобы были квадратными)
    "}"
    
    "QPushButton:hover {"                // Когда наводим мышку
    "   background-color: #eaeaea;"
    "}"
    
    "QPushButton:pressed {"              // Когда нажали
    "   background-color: #d0d0d0;"
    "}"
    );

}



int priority(QChar op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void applyOp(QList<double>& nums, QChar op) {
    if (nums.size() < 2) return;
    double b = nums.takeLast(); 
    double a = nums.takeLast(); 
    
    if (op == '+') nums.push_back(a + b);
    else if (op == '-') nums.push_back(a - b);
    else if (op == '*') nums.push_back(a * b);
    else if (op == '/') nums.push_back(a / b);
}

QString  MainWindow::countLineEdit(QString lineEditStr)
{
    QString s = lineEditStr.simplified(); 
    QList<double> numbers;
    QList<QChar> operators;

    for(int i = 0; i < s.length(); ++i) {
        if (s[i].isDigit()) {
            QString numStr;
            while (i < s.length() && (s[i].isDigit() || s[i] == '.')) {
                numStr += s[i];
                i++;
            }
            i--; 
            numbers.push_back(numStr.toDouble());
        } 
        else if (QString("+-*/").contains(s[i])) {
            while (!operators.isEmpty() && priority(operators.last()) >= priority(s[i])) {
                applyOp(numbers, operators.takeLast());
            }
            operators.push_back(s[i]);
        }
    }

    while (!operators.isEmpty()) {
        applyOp(numbers, operators.takeLast());
    }

    return numbers.isEmpty() ? "0" : QString::number(numbers.first());
}