#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

#include "ui_application.h"
#include "customtree.h"
#include "customlist.h"
#include "calculations.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

    Ui::Application *ui;

    customlist* head;
    treenode* root;

public:
    Application(QWidget *parent = nullptr);
    ~Application();


public slots:
    void CalculatePrimesButtonReleased() const;
    void CountWordsButtonReleased() const;
    void BitwiseCalculationsButtonReleased() const;
    void RemoveEveryFiveButtonReleased();
};
#endif // APPLICATION_H
