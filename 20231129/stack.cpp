#include "stdlib.h"
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<char> stack;

void push(char data)
{

    stack.push_back(data);
    cout<<data<<" push"<<endl;
    for (size_t i = 0; i < stack.size(); ++i) 
    {
        cout << stack[i] << " ";
    }
    cout<<endl;
}

void pop()
{
    cout<<stack.back()<<" pop"<<endl;
    stack.pop_back();
    for (size_t i = 0; i < stack.size(); ++i) 
    {
        cout << stack[i] << " ";
    }
    cout<<endl;
}

int main(void)
{

    push('A');
    push('B');
    push('C');
    push('D');
    push('E');
    pop();
    pop();
    pop();
    pop();
    push('F');
    push('G');
    push('H');
    push('I');
    pop();
    pop();
    pop();
    push('J');
    push('K');
    push('L');
    pop();
    pop();
    push('M');
    push('N');
    pop();
    push('O');

    pop();
    pop();
    pop();
    pop();
    pop();
    push('P');
    push('Q');
    push('R');
    push('S');
    push('T');
    pop();
    pop();
    pop();
    pop();
    push('U');
    push('V');
    push('W');
    push('X');
    pop();
    pop();
    pop();
    push('Y');
    push('Z');
    return 0;
}