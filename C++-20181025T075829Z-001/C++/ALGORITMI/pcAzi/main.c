#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a ;
    char b ;
}elev;

int main()
{
    char *s1 = "abcd" ;
    char s2[30] = "abcd" ;
    if ( strcmp ( s1 , s2 ) )
        printf("identice") ;
    else printf ("diferit") ;
    strcpy(s2,s1) ;
    printf("%s\n" , s1) ;
    strcpy(s1,s2) ;
    printf("%s\n" , s1) ;
    return 0 ;
}
