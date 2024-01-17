#include <iostream>

using namespace std;

int main()
{
    for(int i=1;i<=100;i++)
    {
        if(i%3==0&&i%5==0)
        {
            cout<<"fizz buzz"<<endl;
        }
        if(i%3==0)
        {
            cout<<"fizz"<<endl;
        }
        if(i%5==0)
        {
            cout<<"buzz"<<endl;
        }
    }

    return 0;
}