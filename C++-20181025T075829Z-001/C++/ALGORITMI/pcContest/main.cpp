#include <iostream>
#include <cstdio>
#define PI 3.14159265359

using namespace std ;

int D , H , speed , growth ;
double myLevel , bottomArea ;

int main()
{
    cin >> D >> H >> speed >> growth ;
    bottomArea = PI * D * D ;
    bottomArea /= 4 ;
    myLevel = (double) speed / (double) bottomArea ;
    if ( myLevel <= growth )
        printf("NO") ;
    else
    {
        printf("YES\n") ;
        myLevel = myLevel - growth ;
        printf( "%f" , H / myLevel ) ;
    }
    return 0 ;
}
