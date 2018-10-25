#include <iostream>
#include <iomanip>
#define PI 3,1415

using namespace std ;

int D , H , speed , growth ;
double myLevel , bottomArea ;

int main()
{
    cin >> D >> H >> speed >> growth ;
    bottomArea = (double)PI * D * D / (double)4 ;
    cout << bottomArea ;
    myLevel = (double) speed / (double) bottomArea ;
    if ( myLevel <= growth )
        cout << "NO" ;
    else
    {
        cout << "YES" ;
        myLevel = myLevel - growth ;
        cout << H / myLevel ;
    }
    return 0 ;
}
