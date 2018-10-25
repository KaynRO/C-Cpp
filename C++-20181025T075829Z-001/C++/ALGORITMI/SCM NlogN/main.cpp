#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005 ;
int V[N] ;
int pos[N] ;
int order[N] ;
vector <int> X ;

int main()
{
    int  n , value , k = 0 , nr = 0 ;
    freopen ( "scmax.in" , "r" , stdin ) ;
    freopen ( "scmax.out" , "w" , stdout ) ;
    scanf ( "%d" , &n ) ;
    for( int i = 1 ; i <= n ; ++i )
    {
        scanf ( "%d" , &value ) ;
        V[i] = value ;
    }
    X.push_back( V[1] ) ; // consideram secventa ce are ca element v[1]
    for( int i = 2 ; i <= n ; ++i )
    {
        vector <int>::iterator position ;
        position = lower_bound ( X.begin() , X.end() , V[i] ) ; // cautam in secventa curenta prima pozitie a elementului din secventa > v[i]
        if( position == X.end() )
        {
            X.push_back(V[i]) ; // daca nu exista nicio valoare mai mare adaugam v[i] la secventa curenta la final
            pos[i] = X.size() - 1 ; // retinem pozitia pe care l-am pus
        }
        else
        {
            pos[i] = position - X.begin() ; // altfel actualizam noua pozitie
            X[pos[i]] = V[i] ; // actualizam elementul din secventa cu cel mai mic
        }
    }
    nr = X.size() - 1 ; // lungimea maxima a unei secvente
    for( int i = n ; i > 0 ; --i)
    {
        if(pos[i] == nr) // cautam elementele pe pozitii consecutiv in vector si pe pozitii consecutive in secventa
        {
            order[ ++k ] = V[i] ; // il tinem minte
            --nr ;
        }
    }
    printf( "%d\n" , k ) ;
    for( int i = k ; i > 0 ; --i )
    {
        printf( "%d " , order[i] ) ; // afisam
    }
    printf("\n") ;
    return 0 ;
}
