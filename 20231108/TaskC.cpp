#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    int data[10]={};
    for(int i=0;i<10;i++)
    {
        data[i]=dis(gen);
    }

    for(int i=0;i<10;i++)
    {
        std::cout<<data[i]<<std::endl;
    }
    return 0;
}