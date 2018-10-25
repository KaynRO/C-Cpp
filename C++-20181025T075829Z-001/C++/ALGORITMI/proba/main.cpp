#include <vector>
#include <algorithm>
#include <iostream>
#define NMAX ( 1 << 30 ) // asa se declara infinitu

using namespace std ;

vector < int > V ;  // asta e vectoru alocat dinamic din stl, in momentul asta ocupa 2 bytes

int main()
{
    int minim = NMAX , value , N ;
    cin >> N ;
    for ( int i = 0 ; i < N ; i++ )
    {
        cin >> value ;
        V.push_back(value) ;  // bag in vector elementu citit, isi aloca singur o singura zona de memorie ca sa intre
    }
    for ( int i = 0 ; i < V.size() ; i++ ) // merg in vector pana la dimensiunea lui maxima, cum incepe de la 0, elementele sunt numerotate de la 0 la dimensiunea lui - 1
        for ( int j = i + 1 ; j < V.size() ; j++ )
        {
            if( V[i] > V[j] )
            value = V[i] - V[j] ;
            else value = V[j] - V[i] ; // retin modulul diferentei
            if ( value < minim )
                minim = value ; // vad minimul
        }
    cout << minim ;
    return 0;
}
