#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(0, 999);

    int data[100]={};
    for(int i=0;i<100;i++)
    {
        data[i]=dis(gen);
    }

    for(int i=0;i<100;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;

    int valueA,valueB;

    for(int i=0;i<100;++i)
    {
        for(int j=100-1;j>=i+1;--j)
        {
            valueA=data[i];
            valueB=data[j];
            if(valueA>valueB)
            {
                int max=valueA;
                int min=valueB;
                data[i]=min;
                data[j]=max;
            }
        }
    }

    for(int i=0;i<100;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;

    return 0;
}