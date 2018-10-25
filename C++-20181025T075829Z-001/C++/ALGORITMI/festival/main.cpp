#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream fin ( "festival.in" ) ;
ofstream fout ( "festival.out" ) ;

int n , matrix[25][25] , comp  , use[25] ;
char *p , line[25][200] ;
queue <int> Q ;

void read()
{
    int i , j ;
    fin >> n ;
    fin.get() ;
    for ( int i = 1 ; i <= n ; i++ )
        fin.getline( line[i] , 200 ) ;
    for (  i = 1 ; i <= n - 1 ; i++ )
    {
        p = strtok ( line[i] , "," ) ;
        while ( p != NULL )
        {
            for ( j = i + 1 ;  j <= n ; j++ )
                if ( strstr ( line[j] , p ) )
                    matrix[i][j] = matrix[j][i] = 1 ;
            p = strtok ( NULL , "," ) ;
        }
    }
}

void bfs( int x )
{
    use[x] = ++comp ;
        for ( int i = 1 ; i <= n ; i++ )
            if ( use[i] == 0 && matrix[x][i] == 1 )
                use[i] = comp ;
}

int main()
{
    read() ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( use[i] == 0 )
            bfs(i) ;
    fout << comp ;
    return 0;
}
