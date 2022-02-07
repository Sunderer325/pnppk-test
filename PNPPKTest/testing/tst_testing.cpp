#include <QtTest>

// add necessary includes here
#include "../calculations.h"
#include "../customlist.h"
#include "../customtree.h"

class testing : public QObject
{
    Q_OBJECT

private slots:
    void PrimesTest();
    void CountWordsTest();
    void BitwiseTest();

    void ListTest();

    void TreeTest();
};

void testing::PrimesTest()
{
    QVector<int> output;
    calculations::CalculatePrimes(5, output);
    QVector<int> t{2, 3, 5, 7, 11};
    QCOMPARE(output, t);
}

void testing::CountWordsTest(){
    QString input = "1 22 333 4444 333 22 1";
    QMap<int,int> output;
    QMap<int,int> compare{{1, 2},{2, 2},{3, 2},{4, 1}};
    calculations::CountWords(input, output);
    QCOMPARE(output, compare);
}

void testing::BitwiseTest(){
    unsigned int input = 96;
    unsigned int compareMax = 3221225472;
    unsigned int compareMin = 3;
    BitwiseOutput output = calculations::BitwiseCalculations(input);
    QCOMPARE(output.max, compareMax);
    QCOMPARE(output.min, compareMin);
}

void testing::ListTest(){
    customlist* head = new customlist;
    customlist::Generate(10, head);
    customlist::RemoveEveryAt(5, head);
    QString compare = "0, 1, 2, 3, 5, 6, 7, 8";

    QCOMPARE(customlist::ToQString(head), compare);
}

void testing::TreeTest(){
    treenode* root = treenode::Generate(0, 5);
    int compareDepth = treenode::CountMaxDepth(root);
    QVERIFY(compareDepth > 0);
    treenode::OnlyMaxDepth(root, compareDepth);
    QCOMPARE(treenode::CountMaxDepth(root), compareDepth);
}

QTEST_APPLESS_MAIN(testing)

#include "tst_testing.moc"
