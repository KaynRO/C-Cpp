#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>


using namespace std;

int STEP, MOD ;
vector < int > Step , Mod ;
map < int , string > Message ;
int itt = 0 ;

int number_digits ( int value )
{
    int cpy = value ;
    int count = 0 ;
    while ( cpy != 0 )
    {
        cpy /= 10 ;
        count++ ;
    }
    return count ;
}

void solve ( int step , int mod )
{
    bool ok = true ;
    int minimum = min( step , mod ) ;
    int maximum = max ( step , mod ) ;
    for ( int d = 2 ; d <= maximum / 2 ; d++ )
        if ( minimum % d == 0 && maximum % d == 0 )
            ok = false ;
    Step.push_back(step) ;
    Mod.push_back(mod) ;
    if ( ok == true )
        Message[itt] = "Good Choice" ;
    else Message[itt] = "Bad Choice" ;
    itt++ ;
}
void read()
{
    string input ;
    cin >> STEP >> MOD ;
    solve ( STEP , MOD ) ;
    while ( cin >> STEP >> MOD )
    {
        solve ( STEP , MOD ) ;
    }
}

void print()
{
    for ( int i = 0 ;  i <= Step.size() - 1 ; i++ )
    {
        int step_digit = number_digits( Step[i] ) ;
        for ( int j = 1 ; j <= 10 - step_digit ; j++ )
            cout << ' ' ;
        cout << Step[i] ;
        int mod_digit = number_digits( Mod[i] ) ;
        for ( int j = 1 ; j <= 10 - mod_digit ; j++ )
            cout << ' ' ;
        cout << Mod[i] ;
        for ( int j = 1 ; j <= 4 ; j++ )
            cout << ' ' ;
        cout << Message[i] << '\n' ;
        //cout << Step[i] << ' ' << Mod[i] << Message[i] <<'\n' ;
    }
}
int main()
{
    read();
    print() ;
    return 0;
}
