#include <fstream>
#include<cstdio>
#define Nmax 101
#define Mmax 500
#define Tmax 101
#define oo 300000000

using namespace std;

ofstream fout ( "auto2.out" ) ;
int n , m , a , b , tf ;
int p[Nmax] , mad[Nmax][Nmax] , lung[Mmax] , cost_auto[Mmax][Tmax] , c_min[Nmax][Tmax] ;

void read()
{
    int i , j , o1 , o2 , l ;
    freopen ( "auto2.in" , "r" , stdin ) ;
    scanf ( "%d %d" , &n , &m ) ;
    scanf ( "%d %d %d\n" , &a , &b , &tf ) ;
    a--;
    b--;
    for ( i = 0 ; i < n ; i++ )
        for ( j = 0 ; j < n ; j++ )
            mad[i][j] = -1 ;
    for ( i = 0 ; i < n ; i ++ )
        scanf ( "%d" , &p[i] ) ;
    p[a] = p[b] = 0 ;
    for ( i = 0 ; i < m ; i++ )
    {
        scanf ( "%d %d %d\n" , &o1 , &o2 , &l);
        mad[o1-1][o2-1] = mad[o2-1][o1-1] = i ;
        lung[i] = l ;
        for ( j = 0 ; j < tf ; j++ )
            scanf ( "%d" , &cost_auto[i][j] ) ;
    }

}

void solve()
{
    int i , j , k , l , lm , m ;
    for ( i = 0 ; i < n ; i++ )
        for ( j = 0 ; j <tf ; j++ )
            c_min[i][j] = -1 ;
    c_min[a][0] = 0 ;
    for ( i = 1 ; i <= tf ; i++ )
        for ( j = 0 ; j < n ; j++ )
        {
            c_min[j][i] = oo ;
            for ( k = 0 ; k < i ; k++ )
                for ( l = 0 ; l < n ; l++ )
                {
                    if ( c_min[l][k] == -1 ) continue ;
                    if ( mad[j][l] == -1 ) continue ;
                    lm = lung[mad[j][l]] ;
                    if ( lm > i - k ) continue ;
                    m = c_min[l][k] + cost_auto[mad[j][l]][i-lm] * lm + p[l] * ( i - k - lm ) ;
                    if ( m < c_min[j][i] )
                        c_min[j][i] = m ;

                }
            if ( c_min[j][i] == oo )
                c_min[j][i] = -1 ;

        }

}

void print()
{
  int j , minim = oo ;
  for ( j = 0 ; j <= tf ; j++ )
  {
     if ( c_min[b][j] != -1 && c_min[b][j] < minim )
     minim = c_min[b][j] ;
  }
  fout << minim ;
}

int main()
{
    read() ;
    solve() ;
    print() ;
    return 0;
}
