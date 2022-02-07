#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include <QString>

struct customlist
{
    struct customlist* next;
    int value;

    static void Generate(const int amount, customlist* head);
    static void RemoveEveryAt(const unsigned int index, customlist* first);

    static QString ToQString(customlist* head);
};

#endif // CUSTOMLIST_H
