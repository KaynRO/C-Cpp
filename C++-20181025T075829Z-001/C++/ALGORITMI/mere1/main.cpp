#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin ( "mere.in" ) ;
ofstream fout ( "mere.out" ) ;

int nr  , maxim , matrix[1100][1100] , vis[1100] ;
queue <int> Q ;
struct apple
{
    int index ;
    int value ;
} apples[1100] ;
void read()
{
    fin >> nr ;
    for ( int i = 1 ; i <= nr ; i++ )
    {
        fin >> apples[i].value ;
        apples[i].index = i ;
    }
    while ( !fin.eof() )
    {
        int x , y ;
        fin >> x >> y ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }

}

bool test ( apple a , apple b )
{
    return a.value > b.value || ( a.value == b.value && a.index < b.index ) ;
}
int bfs()
{
    int sum = apples[1].value ;
    sort ( apples + 1 , apples + nr + 1 , test ) ;
    vis[1] = 1 ;
    Q.push(1) ;
    while ( !Q.empty() )
    {
        int k = Q.front() ;
        Q.pop() ;
        for ( int i = 1 ; i <= nr ; i++ )
        {
            if ( matrix[k][apples[i].index] == 1 && !vis[apples[i].index] )
            {
                vis[apples[i].index] = 1 ;
                Q.push( apples[i].index ) ;
                sum += apples[i].value ;
                break ;
            }
        }
    }
    return sum ;
}


int main()
{
    read() ;
    fout << bfs() ;
    return 0;
}
