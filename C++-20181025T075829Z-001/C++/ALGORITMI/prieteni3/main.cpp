#include <fstream>
#include <vector>
using namespace std;

ifstream fin ( "prieteni3.in" ) ;
ofstream fout ( "prieteni3.out" ) ;

int n , A , k , matrix[120][120] , vis[120] , rankk[120] ;
vector <int> myvector ;

void read()
{
    int nr , x , y ;
    fin >> n >> A >> k ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> nr ;
        for ( int s = 1 ; s <= nr ; s++ )
        {
            fin >> x ;
            matrix[i][x] = matrix[x][i] = 1 ;
        }
    }
}

void bfs ( int x )
{
    vis[x] = 1 ;
    myvector.push_back( x ) ;
    while ( !myvector.empty() )
    {
        int l = myvector.back () ;
        myvector.erase ( myvector.begin() + myvector.size() - 1 ) ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( matrix[l][i] == 1 && !vis[i] )
            {
                vis[i] = 1 ;
                rankk[i] = rankk[l] + 1 ;
                myvector.push_back( i ) ;
            }
        }
    }
}

int countt ( int k )
{
    int numbers = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( rankk[i] == k )
            numbers ++ ;
    return numbers ;
}

void print ( int k )
{
   for ( int i = 1 ; i <= n ; i++ )
      if ( rankk[i] == k )
      fout << i << ' ' ;
}
int main()
{
    read() ;
    bfs ( A ) ;
    fout << countt ( k ) << '\n' ;
    print ( k ) ;


    return 0;
}
