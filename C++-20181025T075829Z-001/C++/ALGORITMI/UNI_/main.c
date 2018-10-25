#include <stdio.h>
#include <stdlib.h>

void mk ( int *q )
{
    printf("%d" , q) ;
    q-- ;
}

int main()
{
    int r;
    scanf("%d" , &r) ;
    mk(&r) ;
    printf("%d" , r) ;
    return 0;
}
