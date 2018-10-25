#include <fstream>
#include <vector>
#define NMAX 110
#define INF ( 1 << 30 )

using namespace std ;

ifstream fin ( "parc.in" ) ;
ofstream fout ( "parc.out" ) ;

int N , M , H[NMAX][NMAX] , gates , node_start ;
vector < int > Gate ;

void initialise()
{
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= N ; j++ )
            if ( i == j )
                H[i][j] = 0 ;
            else H[i][j] = INF ;
}

void roy_floyd()
{
    for ( int k = 1 ; k <= N ; k++ )
        for ( int i = 1 ; i <= N ; i++ )
            for ( int j = 1 ; j <= N ; j++ )
                if ( ( H[i][j] > H[i][k] + H[k][j] || H[i][j] == INF ) && i != j && H[i][k] != INF && H[k][j] != INF )
                    H[i][j] = H[i][k] + H[k][j] ;
}

int verify ( int node )
{
    for ( int i = 1 ; i <= N ; i++ )
        if ( i != node && H[node][i] == INF )
            return 0 ;
    return 1 ;
}

int main()
{
    int x , y , cost , index  , bestGate , bestsum = INF ;
    fin >> N >> M >> node_start ;
    initialise() ;
    for ( int i = 1 ; i <= M ; i++ )
    {
        fin >> x >> y >> cost ;
        H[x][y] = H[y][x] = cost ;
    }
    fin >> gates ;
    for ( int i = 1 ; i <= gates ; i++ )
    {
        fin >> index ;
        Gate.push_back(index) ;
    }
    roy_floyd() ;
    for ( vector < int > :: iterator it = Gate.begin() ; it != Gate.end() ; ++it )
        if ( H[*it][node_start] < bestsum )
        {
            bestsum = H[*it][node_start] ;
            bestGate = *it ;
        }
    fout << bestGate ;
    return 0;
}
