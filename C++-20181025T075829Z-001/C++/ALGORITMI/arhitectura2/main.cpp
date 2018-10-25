#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

ofstream fout ( "arhitectura.out" ) ;
int n , G[2000010] , k ;

void read()
{
    freopen ( "arhitectura.in" , "r" , stdin ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf ( "%d" , &G[i] ) ;
        if ( G[i] > k )
            k = G[i] ;
    }
}

void counting_sort ( int A[] , int k , int n )
{
    int i , j ;
    int B[2000010] , C[120000] ;
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (i = n ; i >= 1 ; i-- )
        fout << B[i] << ' ' ;
    fout << '\n' ;
    fout << "0" << ' ' ;
    for ( int i = n - 1 ; i >= 2 ; i-- )
        if ( B[i] == ( B[i+1] + B[i-1] ) / 2 )
            fout << "1" << ' ' ;
        else fout << "0" << ' ';
    if ( B[1] == B[2] / 2 )
        fout << "1" << ' ' ;
    else fout << "0" << ' ';
}
int main()
{
    read() ;
    counting_sort ( G , k , n ) ;
    return 0 ;
}
