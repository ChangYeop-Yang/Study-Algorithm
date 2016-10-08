#include <iostream>
#include <cstdio>
using namespace std;
 
int main(void)
{
    char mTemp = 0;
    int num1 = 0, num2 = 0;
    cin >> num1;
 
    getchar();
 
    for (int ii = 0; ii < num1; ii++)
    {
        while (true) { if ((mTemp = getchar()) != '\n') { num2 = mTemp - '0'; } else { break; } }
        cout << ( num2 % 2 == 0 ? "even" : "odd" ) << endl;
    }
 
    return 0;
}
