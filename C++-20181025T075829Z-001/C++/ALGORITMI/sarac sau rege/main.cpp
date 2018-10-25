#include <fstream>
#include <algorithm>
#define NMAX 50010

using namespace std ;

ifstream fin ( "saracsaurege.in" ) ;
ofstream fout ( "saracsaurege.out" ) ;

int N, Q, lft, rgt , j ;

struct element
{
    int value ;
    int poz ;
} V[NMAX] ;

int cmp ( element A, element B )
{
    if ( A.value == B.value )
        return A.poz < B.poz ;
    return A.value < B.value ;
}

int main()
{
    fin >> N >> Q ;
    for ( int i = 1 ; i <= N ; i++ )
        fin >> V[i].value, V[i].poz = i ;

    sort ( V + 1, V + N + 1, cmp ) ;

    for ( int i = 1 ; i <= Q ; i++ )
    {
        fin >> lft >> rgt ;
        for ( j = N ; j >= 1 && ( lft > V[j].poz || rgt < V[j].poz ) ; j-- ) ;
        fout << V[j].value << '\n' ;
    }
    return 0;
}
