#include <fstream>

using namespace std;

ifstream fin ( "izvor.in" ) ;
ofstream fout ( "izvor.out" ) ;

int n , m , numbers , matrix[25][25] , vis[25] , sol[25] , nr ;

int read()
{
    int x , y , z ;
    fin >> n >> m >> numbers ;
    for ( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y >> z ;
        if ( z == 0 ) matrix[x][y] = matrix[y][x] = -1 ;
        if ( z == 1 ) matrix[x][y] = matrix[y][x] = 1 ;
    }
}

int ok()
{
    if ( matrix[sol[1]][sol[numbers]] != 0 )
    {
        for ( int i = 1 ; i <= numbers - 1  ; i++ )
            if ( matrix[sol[i]][sol[i+1]] == 1 )
                return 1 ;
    }
    return 0 ;
}

void print()
{
    for ( int k = 1 ; k <= numbers ; k++ )
        fout << sol[k] << ' '  ;
    fout <<'\n' ;
}

int back ( int k )
{
    if ( k == numbers + 1 )
    {
        if ( ok () ) nr++ ;
    }
    else
    {
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !vis[i] && ( matrix[i][sol[k-1]] != 0 || sol[k-1] == -1 ) )
            {
                sol[k] = i ;
                vis[i] = 1 ;
                back ( k + 1 ) ;
                vis[i] = 0 ;
            }
        }
    }

}
int main()
{
    read() ;
    sol[0] = -1 ;
    back(1) ;
    fout << nr ;
    return 0;
}
