#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    int data[] = {0,1,2,3,4,5,6,7,8,9};
    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; ++i) {
        cout << data[i] << " ";
    }
    cout<<endl;

    random_device rd;
    mt19937 gen(rd());

    shuffle(data, data + dataSize, gen);

    for (int i = 0; i < dataSize; ++i) {
        cout << data[i] << " ";
    }
    cout<<endl;

    int result = -1;
    int target = 5;

    for(int i=0;i<10;i++)
    {
        if(data[i]==target)
        {
            result=i;
            break;
        }
    }

    cout << "index of target is "<<result<<endl;

    return 0;
}