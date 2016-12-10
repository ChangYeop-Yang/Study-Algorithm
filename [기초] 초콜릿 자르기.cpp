#include <stdio.h>

int main(void)
{
    int mValue[2] = {0, 0};
    scanf("%d %d", &mValue[0], &mValue[1]);
    
    printf("%d\n", (mValue[0] * mValue[1])-1);
    
    return 0;
}
