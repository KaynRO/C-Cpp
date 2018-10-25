#include <iostream>

using namespace std ;

int steps, coins, currentKingdom, nextKingdom ;
char direction ;

struct position
{
    int x ;
    int y ;
};

int getKingdom ( position A )
{
    if ( A.y > A.x )
        return 2 ;
    if ( A.y == A.x )
        return 0 ;
    return 1 ;
}

int main()
{
    cin >> steps ;

    currentKingdom = 0 ;
    position currentPosition ;
    currentPosition.x = 0, currentPosition.y = 0 ;

    for ( int i = 1 ; i <= steps ; i++ )
    {
        cin >> direction ;

        //cout << "Going from   " << currentPosition.x << ' ' << currentPosition.y ;

        if ( direction == 'R' )
            currentPosition.x++ ;
        if ( direction == 'U' )
            currentPosition.y++ ;

        //cout << "  --->   " << currentPosition.x << ' ' << currentPosition.y << '\n' ;

        nextKingdom = getKingdom(currentPosition) ;

        if ( nextKingdom == 0 ) continue ;

        if ( currentKingdom != 0 && nextKingdom != currentKingdom )
            {
                coins++ ;
                //cout << "Changing kingdom  " << currentKingdom << " --->  " << nextKingdom << '\n' ;
            }

        currentKingdom = nextKingdom ;

    }
    cout << coins ;
    return 0 ;
}
