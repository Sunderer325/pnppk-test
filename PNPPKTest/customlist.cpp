#include "customlist.h"

QString customlist::ToQString(customlist* head){
    customlist* temp = head->next;
    QString str = QString::number(head->value);

    while(temp != nullptr){
        str.append(", ");
        str.append(QString::number(temp->value));
        temp = temp->next;
    }

    return str;
}

void customlist::Generate(const int amount, customlist* head){
    customlist* temp = head;

    for(int i = 0; i < amount; i++){
        customlist* next = (i < amount - 1) ? new customlist : nullptr;
        *temp = {next, i};
        temp = next;
    }
}

void customlist::RemoveEveryAt(const unsigned int index, customlist* first){
    unsigned int iterator = 0;

    customlist* prev;
    customlist* current = first;

    do{
        iterator ++;

        if(iterator == index){
            if(prev == nullptr){
                current = current->next;
            }
            else{
                prev->next = current->next;
            }

            iterator = 0;
        }

        prev = current;
        current = current->next;
    }
    while(current != nullptr);
}

