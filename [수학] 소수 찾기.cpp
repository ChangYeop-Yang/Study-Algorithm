#include <iostream>
using namespace std;
 
bool bArr[1001];
 
bool getChe(int num)
{
    for (int qq = 2; qq <= num; qq++) { bArr[qq] = true; }
 
    for (int qq = 2; qq*qq <= num; qq++)
    {
        if (!bArr[qq]) continue;
 
        for (int hh = qq + qq; hh <= num; hh += qq) { bArr[hh] = false; }
    }
 
    return (bArr[num] ? true : false);
}
 
int main(void)
{
    /* Input */
    int num = 0, count = 0;
    cin >> num;
 
    for (int qq = 0; qq < num; qq++) 
    { 
        int temp = 0;
        cin >> temp;
 
        if (getChe(temp)) { count++; } 
    }
     
    /* Output */
    cout << count << endl;
 
    return 0;
}
