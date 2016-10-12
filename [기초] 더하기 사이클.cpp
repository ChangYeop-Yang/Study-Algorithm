#include <iostream>
#include <vector>
using namespace std;
 
vector<int> mVec;
 
int main(void)
{
    int num1 = 0, num2 = 0;
    cin >> num1;
 
    num2 = num1 % 10;
    num1 = num1 < 10 ? num1 : ((num1 / 10) + (num1 % 10)) % 10;
    while (true)
    {
        int temp = (num2 * 10) + num1;
        for (int ii = 0; ii < mVec.size(); ii++)
        {
            if (mVec.at(ii) == temp) { cout << mVec.size() - ii << endl; return 0; }
        } mVec.push_back(temp);
 
        num2 = temp % 10;
        num1 = temp < 10 ? temp : ((temp / 10) + (temp % 10)) % 10;
    }
 
    return 0;
}
