#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
 
float Score(char * mChar)
{
    float mFloat = 0.0;
 
    if (strcmp("A+", mChar) == 0) { mFloat = 4.3; }
    else if (strcmp("A0", mChar) == 0) { mFloat = 4.0; }
    else if (strcmp("A-", mChar) == 0) { mFloat = 3.7; }
    else if (strcmp("B+", mChar) == 0) { mFloat = 3.3; }
    else if (strcmp("B0", mChar) == 0) { mFloat = 3.0; }
    else if (strcmp("B-", mChar) == 0) { mFloat = 2.7; }
    else if (strcmp("C+", mChar) == 0) { mFloat = 2.3; }
    else if (strcmp("C0", mChar) == 0) { mFloat = 2.0; }
    else if (strcmp("C-", mChar) == 0) { mFloat = 1.7; }
    else if (strcmp("D+", mChar) == 0) { mFloat = 1.3; }
    else if (strcmp("D0", mChar) == 0) { mFloat = 1.0; }
    else if (strcmp("D-", mChar) == 0) { mFloat = 0.7; }
    else { mFloat = 0.0; }
 
    return mFloat;
}
 
int main(void)
{
    int N = 0, T = 0;
    cin >> N; getc(stdin);
 
    int M[2] = { 0, 0 };
    float Sum = 0;
    for (int count = 0; count < N; count++)
    {
        char mChar[105];
        fgets(mChar, sizeof(mChar), stdin);
 
        int Len = 0;
        for (; *(mChar + Len) != ' '; Len++);
        
        char mTemp[3];
        mTemp[0] = *(mChar + (Len + 3));
        mTemp[1] = *(mChar + (Len + 4));
        mTemp[2] = '\0';
 
        T += *(mChar + (Len+1)) - '0';
        Sum += (*(mChar + (Len + 1)) - '0') * Score(mTemp);
    }
 
    printf("%.2f\n", Sum/T);
 
    return 0;
}
