#include <iostream>
using namespace std;
 
int main(void)
{
    long long int mArr[3] = { 0, 0, 0 };
    cin >> mArr[0] >> mArr[1] >> mArr[2];
 
    long long int mXor = mArr[0];
    for (int ii = 0; ii < mArr[2]; ii++)
    {
        mXor ^= mArr[1];
    }
 
    cout << mXor << endl;
 
    return 0;
}
