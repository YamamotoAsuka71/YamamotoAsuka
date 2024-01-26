#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<char> queue;

void Enqueue(char data)
{

    queue.insert(queue.begin(),data);
    cout<<data<<" enqueue"<<endl;
    for (size_t i = 0; i < queue.size(); ++i) 
    {
        cout << queue[i] << " ";
    }
    cout<<endl;
}

void Dequeue()
{
    cout<<queue.front()<<" dequeue"<<endl;
    queue.erase(queue.begin());
    for (size_t i = 0; i < queue.size(); ++i) 
    {
        cout << queue[i] << " ";
    }
    cout<<endl;
}

int main(void)
{

    Enqueue('A');
    Enqueue('B');
    Enqueue('C');
    Enqueue('D');
    Enqueue('E');
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue('F');
    Enqueue('G');
    Enqueue('H');
    Enqueue('I');
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue('J');
    Enqueue('K');
    Enqueue('L');
    Dequeue();
    Dequeue();
    Enqueue('M');
    Enqueue('N');
    Dequeue();
    Enqueue('O');

    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue('P');
    Enqueue('Q');
    Enqueue('R');
    Enqueue('S');
    Enqueue('T');
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue('U');
    Enqueue('V');
    Enqueue('W');
    Enqueue('X');
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue('Y');
    Enqueue('Z');
    return 0;
}