#include <iostream>

using namespace std;

int main()
{
    char symbol;
    int number1, number2;
    cin>>symbol>>number1>>number2;
    if(symbol == '+')
        cout<<number1 + number2;
    if(symbol == '-')
        cout<<number1 - number2;
    if(symbol == '*')
        cout<<number1 * number2;
    if(symbol == '/')
        cout<<number1 / number2;
    return 0;
}
