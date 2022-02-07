#include "calculations.h"

void calculations::BitShiftToLeft(unsigned int& input){
    for(int i = UINTSIZE - 1; i >= 0; i --){
        for(int j = 1; !((input) & (1 << i)); j++){
            if(i - j < 0)
                break;

            unsigned int temp = input & (1 << (i - j));
            if(temp){
                temp <<= j;
                input &= ~(1 << i);
                input &= ~(1 << (i - j));
                input |= temp;
            }
        }
    }
}

unsigned int calculations::BitReverse(const unsigned int input){
    unsigned int output = 0;

    for(int i = 0; i < UINTSIZE; i ++){
        if(input & (1 << i))
            output |= 1 << (UINTSIZE - i - 1);
    }

    return output;
}

void calculations::CalculatePrimes(const int amount, QVector<int>& output){
    int n = 2;

    output.push_back(n);

    while((int)output.size() < amount){
        n++;

        bool isPrime = true;
        for(int i = 0; i < (int)output.size(); i++){
            if(n % output[i] == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            output.push_back(n);
        }
    }
}

void calculations::CountWords(QString& text, QMap<int, int>& output){
    text.replace(QChar(','), QChar(' '));
    text.replace(QChar('.'), QChar(' '));
    text = text.simplified();

    QStringList words = text.split(' ');

    for(int i = 0; i < words.size(); i++){
        int counter = output[words[i].length()];
        output[words[i].length()] = ++counter;
    }
}

BitwiseOutput calculations::BitwiseCalculations(const unsigned int input){
    BitwiseOutput output{0, input};

    calculations::BitShiftToLeft(output.max);
    output.min = calculations::BitReverse(output.max);

    return output;
}

QString calculations::UIntToBinaryString(const unsigned int input){
    QString output = "0b";

    for(int i = UINTSIZE - 1; i >= 0; i --){
        if(input & (1 << i))
            output += '1';
        else output += '0';
    }

    return output;
}
