#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std ;

ifstream fin ( "parchet.in" ) ;
ofstream fout ( "parchet.out" ) ;
int p, N, M, X, suprafata, vis[300][300], Zona[2100], posibilitati, camera ;
char Mx[300][300] ;
int dl[] = { 0, 0, 1, -1 }, dc[] = { -1, 1, 0, 0 } ;
queue < pair < int, int > > Q ;

void cauta_suprafata ( int i, int j )
{
    Q.push ( make_pair ( i, j ) ) ;
    ++suprafata ;
    vis[i][j] = 1 ;
    while ( !Q.empty() )
    {
        int line = Q.front().first ;
        int colomn = Q.front().second ;
        Q.pop() ;
        vis[line][colomn] = 1 ;
        for ( int k = 0 ; k < 4 ; k++ )
        {
            if ( line + dl[k] <= N && line + dl[k] >= 1 && colomn + dc[k] <= M && colomn + dc[k] >= 1 )
            {
                if ( Mx[line + dl[k]][colomn + dc[k]] == 'S' && !vis[line + dl[k]][colomn + dc[k]]  )
                {
                    Q.push ( make_pair ( line + dl[k], colomn + dc[k] ) ) ;
                    vis[line + dl[k]][colomn + dc[k]] = 1 ;
                    suprafata++ ;
                }
            }
        }
    }
}

void read()
{
    freopen ( "parchet.in", "r", stdin ) ;
    fin >> p >> N >> M >> X ;
    fin.get() ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            fin >> Mx[i][j] ;
}
void calc_pos()
{
    int nrsel, NRSEL = 0, suprafata, i;
    int used[100] = {0};
    while (!used[0])
    {
        i = camera;
        while (used[i]) used[i--] = 0;
        used[i] = 1;
        suprafata = 0;
        nrsel = 0;
        for (i = 1; i <= camera; i++)
            if (used[i])
            {
                suprafata += Zona[i];
                nrsel++;
            }
        if (suprafata == X)
        {
            if (nrsel > NRSEL)
            {
                NRSEL = nrsel;
                posibilitati = 1 ;
            }
            else if (nrsel == NRSEL)
                posibilitati++ ;
        }
    }
}

int main()
{
    read() ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            if ( Mx[i][j] == 'S' && vis[i][j] == 0 )
            {
                cauta_suprafata ( i, j ) ;
                Zona[++camera] = suprafata ;
                suprafata = 0 ;
            }
    sort ( Zona + 1, Zona + camera + 1 ) ;
    int suma = 0, camere = 0 ;
    for ( int i = camera ; i >= 1 ; i-- )
        if ( suma + Zona[i]  <= X )
        {
            suma += Zona[i] ;
            camere++ ;
        }
        else break ;
    if ( p == 1 )
        fout << camere << ' ' << X - suma ;
    else
    {
        int sum = 0 ;
        for ( int i = 1 ; i <= camera ; i++ )
            sum += Zona[i] ;
        if ( sum <= X )
            fout << "1" ;
        else
        {
            calc_pos() ;
            fout << posibilitati ;
        }
    }
    return 0 ;
}
