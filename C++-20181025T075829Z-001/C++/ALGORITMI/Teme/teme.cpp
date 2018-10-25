#include <fstream>
#include <vector>
using namespace std;

ifstream fin ( "teme.in" ) ;
ofstream fout ( "teme.out" ) ;

int nr , matrix[320][320] , viz [320] , m ; 
vector <int>  myvector ;
int comp ;

void read()
{
    int x , y ;
    fin >> nr >> m ;
    for ( int i = 1 ; i <= m ; i++ ) 
      {  fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
      }

}

void bfs (int nod )
{
    viz[nod] = comp ;
    myvector.push_back(nod) ;
    while ( !myvector.empty() )
    {
        int x = myvector.back() ;
        myvector.erase ( myvector.begin() + myvector.size() - 1 ) ;
        for ( int i = 1 ; i<= nr ; i++ )
        {
            if ( !viz[i]  && matrix[x][i] == 1 )
            {
                myvector.push_back ( i ) ;
                viz[i] = comp  ;
            }
        }
    }
}

int main()
{
    read() ; 
    if ( m == 0 ) fout << nr ; 
   else 
   {
    for ( int i = 1 ; i <= nr ; i++ )
    {
        if ( viz[i] == 0 )
        {
            comp ++ ;
            bfs(i) ;
        }
    }
    fout << comp << '\n' ;
}

    return 0;
}
