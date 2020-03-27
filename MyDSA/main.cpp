#include <iostream>
#include "./Vector.cpp"
int main()
{
    Vector<int> c;
    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);
    c.insert(5);
    int num=c.find(5);
    std::cout<<num<<std::endl;
    return 0;
}
