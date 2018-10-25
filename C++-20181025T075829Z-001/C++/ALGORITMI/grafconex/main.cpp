#include <fstream>
#include <vector>
using namespace std;

ifstream fin ( "conex.in" ) ;
ofstream fout ( "conex.out" ) ;

int nr , matrix[120][120] , viz [120] ;
vector <int>  myvector ;

void read()
{
    int x , y ;
    fin >> nr ;
    while ( !fin.eof() )
    {
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }

}

int bfs ()
{
    viz[1] = 1 ;
    myvector.push_back(1) ;
    while ( !myvector.empty() )
    {
        int x = myvector.back() ;
        myvector.erase ( myvector.begin() + myvector.size() - 1 ) ;
        for ( int i = 1 ; i<= nr ; i++ )
        {
            if ( !viz[i]  && matrix[x][i] == 1 )
            {
                myvector.push_back ( i ) ;
                viz[i] = 1 ;
            }
        }
    }
}

int check ()
{
for ( int i = 1 ; i <= nr ; i ++ )
   if ( viz[i] == 0 ) return 0 ;
   return 1 ;
}
int main()
{
    read() ;
    bfs() ;
    if( check() ) fout << "DA" ;
    else fout << "NU" ;
    return 0;
}
