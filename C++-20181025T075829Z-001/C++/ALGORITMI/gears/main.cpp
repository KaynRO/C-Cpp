#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "gears.in" ) ;
ofstream fout ( "gears.out" ) ;

int n  , matrix[120][120] , sens[120] , start , vis[120] ;

vector <int> myvector ;

void read()
{
    fin >> n >> start ;
    int x , y ;
    while ( !fin.eof() )
    {
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }

}



void bfs ( int x )
{
    vis[x] = 1 ;
    sens[x] = 1 ;
    myvector.push_back( x ) ;
    while ( !myvector.empty() )
    {
        int k = myvector.back() ;
        myvector.erase ( myvector.begin() + myvector.size() - 1 ) ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !vis[i] && matrix[k][i] == 1 )
            {
                sens[i] = (-1 )* sens[k] ;
                vis[i] = 1 ;
                myvector.push_back( i ) ;


            }
        }
    }

}

int main()
{
    read() ;
    bfs ( start ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( sens[i] == 1 ) fout << "D" ;
        else fout << "S" ;
    }
    return 0;
}
