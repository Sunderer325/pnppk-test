#include "application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);

    head = new customlist;
    customlist::Generate(50, head);
    ui->listOutput->setText(customlist::ToQString(head));

    root = treenode::Generate(0, 5);

    auto originalRootItem = treenode::ToQTreeWidgetItem(root);
    originalRootItem->setText(0, "Root");

    ui->originalTreeOutput->addTopLevelItem(originalRootItem);

    int depth = treenode::CountMaxDepth(root);
    ui->depthOutput->setText(QString::number(depth));

    treenode::OnlyMaxDepth(root, depth);

    auto rootItem = treenode::ToQTreeWidgetItem(root);
    rootItem->setText(0, "Root");

    ui->treeOutput->addTopLevelItem(rootItem);
}

Application::~Application()
{
    customlist* current = head;

    while(current != nullptr){
        customlist* next = current->next;
        delete current;
        current = next;
    }
    delete ui;
}

void Application::CalculatePrimesButtonReleased() const
{
    const int totalAmount = ui->primesAmount->value();

    QVector<int> primes;
    calculations::CalculatePrimes(totalAmount, primes);

    QString str;
    for(int i = 0; i < (int)primes.size(); i++){
        str += QString::number(primes[i]);
        str += ' ';
    }

    ui->primesOutput->setText(str);
}

void Application::CountWordsButtonReleased() const
{
    QString text = ui->textToCount->toPlainText();
    QMap<int, int> results;

    calculations::CountWords(text, results);

    ui->wordsCountOutput->clear();

    for(int i = 0; i < results.size(); i++){
        int key = results.keys()[i];

        QString str = QString::number(key);
        str.append(", ");
        str.append(QString::number(results[key]));

        ui->wordsCountOutput->addItem(str);
    }
}

void Application::BitwiseCalculationsButtonReleased() const
{
    unsigned int number = ui->numberToBits->value();
    BitwiseOutput out = calculations::BitwiseCalculations(number);

    ui->binaryOutput->setText(calculations::UIntToBinaryString(number));
    ui->maxBinaryOutput->setText(QString::number(out.max) + " :: " + calculations::UIntToBinaryString(out.max));
    ui->minBinaryOutput->setText(QString::number(out.min) + " :: " + calculations::UIntToBinaryString(out.min));
}

void Application::RemoveEveryFiveButtonReleased(){
    customlist::RemoveEveryAt(5, head);
    ui->listOutput->setText(customlist::ToQString(head));
}
