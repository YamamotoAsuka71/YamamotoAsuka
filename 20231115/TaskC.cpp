#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(0, 100);

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

    int target = 50;
    int result = -1;
    int left = 0;
    int right = 100 - 1;
    int mid;

    while(true)
    {
        mid = (left + right) / 2;

        if(data[mid]==target)
        {
            result=mid;
            break;
        }
        else
        {
            if(data[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        if(left>=right)
        {
            break;
        }
    }
    if(result>=0)
    {
        cout<<"index of target is "<<result<<endl;
    }
    else
    {
        cout<<"target not found"<<endl;
    }


    return 0;
}