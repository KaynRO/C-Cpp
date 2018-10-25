#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    char Time[10] ;
    int a ;

    cin >> Time >> a ;

    int hours = 10 * (Time[0] - '0') + (Time[1] - '0') ;
    int minutes = 10 * (Time[3] - '0') + (Time[4] - '0') ;

    int cat = ( minutes + a ) / 60 ;
    int remind = ( minutes + a ) % 60 ;
    hours += cat ;
    hours %= 24 ;

    if ( hours / 10 < 1 && remind / 10 < 1 )
        cout << '0' << hours << ':' << '0' << remind ;
    else if ( hours / 10 < 1 )
        cout << '0' << hours << ':' << remind ;
    else if ( remind / 10 < 1 )
        cout << hours << ':' << '0' << remind ;
    else if ( remind / 10 >= 1 && hours / 10 >= 1 )
        cout << setprecision(2) << hours << ':' << remind ;
    return 0;
}
