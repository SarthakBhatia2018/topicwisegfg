#include <iostream>

using namespace std;

class base
{
public:
    int x = 5;
};

class derived : public base
{
public:
    int y = 10;
};

int main()
{
    base b;
    derived d=b;
    return 0;
}