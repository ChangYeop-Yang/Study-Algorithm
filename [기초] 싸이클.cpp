#include <iostream>
#include <vector>
using namespace std;
 
vector<int> mVector;
 
int main(void)
{
    int count = 0;
    int num1 = 0, num2 = 0, num3 = 0;
    cin >> num1 >> num2;
 
    /* Init */
    mVector.push_back(num1);
    num3 = num1;
    while (true)
    {
        num3 = (num1 * num3) % num2;
 
        for (int ii = 0; ii < mVector.size(); ii++)
        {
            if (mVector.at(ii) == num3) { cout << mVector.size() - ii << endl; return 0; }
        }
 
        mVector.push_back(num3);
    }
 
    return 0;
}
