#include "stdlib.h"
#include <iostream>
#include <string.h>

using namespace std;

#define LIST_SIZE 5

void push(string &list_, int *currentIndex_, char data)
{
    list_[*currentIndex_]=data;
    *currentIndex_ = *currentIndex_ + 1;
    cout << "push " << data << endl;
    for(int i = 0 ; i < LIST_SIZE ; i++)
    {
        cout << list_[i] << endl;
    }
}

void pop(string &list_, int *currentIndex_)
{
    *currentIndex_ = *currentIndex_ - 1;
    cout << "pop " << list_[*currentIndex_]<<endl;
    list_[*currentIndex_]=' ';
    for(int i = 0 ; i < LIST_SIZE ; i++)
    {
        cout << list_[i] << endl;
    }
}

int main(void)
{
    int currentIndex = 0;
    string list[LIST_SIZE] = {};

    push(*list, &currentIndex,'A');
    cout << currentIndex << endl;

    pop(*list,&currentIndex);
    cout << currentIndex << endl;

    return 0;
}