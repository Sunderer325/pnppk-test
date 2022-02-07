#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <QMap>
#include <QChar>
#include <QString>
#include <QVector>
#include <QStringList>

#define UINTSIZE (int)sizeof(unsigned int) * 8

struct BitwiseOutput{
    unsigned int min;
    unsigned int max;
};

class calculations
{
    calculations() = delete;

    static void BitShiftToLeft(unsigned int& input);
    static unsigned int BitReverse(const unsigned int input);

public:
    static void CalculatePrimes(const int amount, QVector<int>& output);
    static void CountWords(QString& text, QMap<int, int>& output);
    static BitwiseOutput BitwiseCalculations(const unsigned int input);
    static QString UIntToBinaryString(const unsigned int input);
};

#endif // CALCULATIONS_H
