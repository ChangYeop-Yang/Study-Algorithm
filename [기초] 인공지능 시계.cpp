#include <iostream>
using namespace std;
 
int main(void)
{
    int num1 = 0, num2 = 0, num3 = 0;
    cin >> num1 >> num2 >> num3;
 
    int num4 = 0;
    cin >> num4;
 
    num3 += num4;
    if (num3 >= 60)
    {
        num2 += (num3 / 60);
        if (num2 >= 60)
        {
            num1 += (num2 / 60);
            if (num1 >= 24) 
            { 
                int temp = num1;
                num1 = 0;
 
                num1 += (temp % 24);
            }
 
            num2 = (num2 % 60);
        }
 
        num3 = (num3 % 60);
    }
 
    cout << num1 << ' ' << num2 << ' ' << num3 << endl;
 
    return 0;
}
