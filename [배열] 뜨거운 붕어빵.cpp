#include <iostream>
#define SWAP(X, Y, Z) (Z=X); (X=Y); (Y=Z); 
using namespace std;
 
int main(void)
{
    int num1 = 0, num2 = 0, num3 = 0;
    cin >> num1 >> num2;
 
    char mArr[11][11] = { 0, };
    int mVisit[11][11] = { 0, };
    for (int ii = 0; ii < num1; ii++)
    {
        for (int jj = 0; jj < num2; jj++)
        {
            cin >> mArr[ii][jj];
        }
    }
 
    for (int ii = 0; ii < num1; ii++)
    {
        for (int jj = 0, kk = num2 - 1; jj < num2; jj++, kk--)
        {
            if (mArr[ii][jj] != mArr[ii][kk])
            {
                if (mVisit[ii][jj] == 0 && mVisit[ii][kk] == 0) 
                { 
                    mVisit[ii][jj] = mVisit[ii][kk] = 1;
                    SWAP(mArr[ii][jj], mArr[ii][kk], num3); 
                }
            }
        }
    }
 
    for (int ii = 0; ii < num1; ii++)
    {
        for (int jj = 0; jj < num2; jj++)
        {
            cout << mArr[ii][jj];
        }
 
        cout << endl;
    }
 
    return 0;
}
