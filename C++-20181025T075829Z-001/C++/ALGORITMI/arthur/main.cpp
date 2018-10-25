#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>
#define oo 5000000

using namespace std;

ofstream fout ( "arthur.out" ) ;
int n , m , k , nrhanuri , lin_start , col_start , lin_finish , col_finish , matrix[250][250] , cost[250][250] , father[250] ;
int dist[250] , used[250] , path[250] , distance_up[250][250] , distance_down[250][250] ;
int dl_down[] = {-1 ,1 , 0 , 0 , 1 , 1 , -1 , -1 } , dc_down[] = {0 , 0 , 1 , -1 , -1 , 1 , 1 , -1 } ;
int dl_up[] = { -2 , -2 , -1 , -1 , 2 , 2 , 1 , 1 }   , dc_up[] = { 1 , -1 , 2 , -2 , - 1 , 1 , -2 , 2 } ;
int drum[250][250] ;

struct element
{
    int lin ;
    int col ;
} wayback[250] ;

queue <pair<int,int> > Q ;

struct han
{
    int lin ;
    int col ;
} Han[250] ;

void read()
{
    freopen ( "arthur.in" , "r" ,stdin ) ;
    scanf ( "%d %d %d %d" , &n , &m , &k , &nrhanuri ) ;
    scanf ( "%d %d" , &lin_start , &col_start ) ;
    scanf ( "%d %d" , &lin_finish , &col_finish ) ;
    for ( int i = 1 ; i <= nrhanuri ; i++ )
        scanf ( "%d %d" , &Han[i].lin , &Han[i].col ) ;
    Han[0].lin = lin_start ;
    Han[0].col = col_start ;
    Han[nrhanuri+1].lin = lin_finish ;
    Han[nrhanuri+1].col = col_finish ;

}

int firstlee ( int xs , int ys  , int way )
{
    memset(matrix,0,sizeof(matrix)) ;
    Q = queue <pair<int,int> > () ;
    int ln , cn , line , colomn , i ;
    matrix[xs][ys] = 1 ;
    Q.push( make_pair( xs , ys ) ) ;
    while ( !Q.empty() )
    {
        line = Q.front().first ;
        colomn = Q.front().second ;
        Q.pop() ;
        if ( way == 1 )
        {
            for (  i = 0 ; i <= 7 ; i++ )
            {
                ln = line + dl_up[i] ;
                cn = colomn + dc_up[i] ;
                if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m )
                {
                    if ( matrix[ln][cn] == 0 )
                    {
                        Q.push( make_pair ( ln , cn ) ) ;
                        matrix[ln][cn] = matrix[line][colomn] + 1;
                    }
                }
            }
        }
        if ( way == 2 )
        {
            for (  i = 0 ; i <= 7 ; i++ )
            {
                ln = line + dl_down[i] ;
                cn = colomn + dc_down[i] ;
                if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m )
                {
                    if ( matrix[ln][cn] == 0 )
                    {
                        Q.push( make_pair ( ln , cn ) ) ;
                        matrix[ln][cn] = matrix[line][colomn]+1;
                    }
                }
            }
        }
    }
    return 0 ;
}

int lee ( int xs , int ys , int xf , int yf , int way )
{
    memset(matrix,0,sizeof(matrix)) ;
    Q = queue <pair<int,int> > () ;
    int ln , cn , line , colomn , i ;
    matrix[xs][ys] = 1 ;
    Q.push( make_pair( xs , ys ) ) ;
    while ( !Q.empty() )
    {
        line = Q.front().first ;
        colomn = Q.front().second ;
        Q.pop() ;
        if ( way == 1 )
        {
            for (  i = 0 ; i <= 7 ; i++ )
            {
                ln = line + dl_up[i] ;
                cn = colomn + dc_up[i] ;
                if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m )
                {
                    if ( matrix[ln][cn] == 0 )
                    {
                        if ( ln == xf && cn == yf )
                        {
                            matrix[ln][cn] = matrix[line][colomn] + 1 ;
                            return matrix[line][colomn] + 1 ;
                        }
                        Q.push( make_pair ( ln , cn ) ) ;
                        matrix[ln][cn] = matrix[line][colomn] + 1;
                    }
                }
            }
        }
        if ( way == 2 )
        {
            for (  i = 0 ; i <= 7 ; i++ )
            {
                ln = line + dl_down[i] ;
                cn = colomn + dc_down[i] ;
                if ( ln >= 1 && ln <= n && cn >= 1 && cn <= m )
                {
                    if ( matrix[ln][cn] == 0 )
                    {
                        if ( ln == xf && yf == cn)
                        {
                            matrix[ln][cn] = matrix[line][colomn] + 1 ;
                            return matrix[line][colomn] + 1 ;
                        }
                        Q.push( make_pair ( ln , cn ) ) ;
                        matrix[ln][cn] = matrix[line][colomn] + 1 ;
                    }
                }
            }
        }
    }
    return 0 ;
}

void do_before_djikstra()
{
    int d_up = 0  , d_down = 0  ;
    for ( int i = 0 ; i <= nrhanuri ; i++ )
    {
        firstlee ( Han[i].lin , Han[i].col , 1 ) ;
        for ( int j = i + 1 ; j <= nrhanuri + 1 ; j++ )
            distance_up[i][j] = matrix[Han[j].lin][Han[j].col] - 1 ;
        firstlee ( Han[i].lin , Han[i].col , 2 ) ;
        for ( int j = i + 1 ; j <= nrhanuri + 1 ; j++ )
            distance_down[i][j] = matrix[Han[j].lin][Han[j].col] - 1 ;
        for ( int j = i + 1 ; j <= nrhanuri + 1 ; j++ )
        {

            d_down = distance_down[i][j] ;
            d_up = distance_up[i][j] ;
            if ( d_down < d_up && d_down != 0 )
                cost[i][j] = d_down ;
            else
            {
                if ( d_up > k )
                    cost[i][j] = d_down ;
                else
                {
                    if ( i == 0 )
                        cost[i][j] = d_down ;
                    else
                        cost[i][j] = d_up ;
                }
            }
            cost[j][i] = cost[i][j] ;
            if ( cost[i][j] == d_down )
                drum[i][j] = 2 ;
            if ( cost[i][j] == d_up )
                drum[i][j] = 1 ;
            drum[j][i] = drum[i][j] ;
        }
    }
}

void prepare_dijkstra()
{
    for ( int i = 1 ; i <= nrhanuri + 1 ; i++ )
        dist[i] = oo ;
    for ( int i = 1 ; i <= nrhanuri+1 ; i++ )
    {
        dist[i] = cost[0][i] ;
        father[i] = 0 ;
    }
    used[0] = 1 ;
    father[0] = 0 ;
    dist[0] = 0 ;
}

void dijkstra()
{
    int dmin , vfmin ;
    for ( int j = 0 ; j <= nrhanuri ; j++ )
    {
        dmin = oo ;
        for ( int i = 0 ; i <= nrhanuri+1 ; i++ )
            if ( !used[i] && dmin > dist[i] )
            {
                dmin = dist[i] ;
                vfmin = i ;
            }
        used[vfmin] = 1 ;
        for ( int i = 0  ; i <= nrhanuri+1 ; i++ )
            if ( !used[i] && dist[i] > dmin + cost[vfmin][i] )
            {
                father[i] = vfmin ;
                dist[i] = dmin + cost[vfmin][i] ;
            }
    }
    fout << dist[nrhanuri+1] ;
}

void print_path( int i , int ok  )
{
    memset( wayback , 0 , sizeof(wayback) ) ;
    int lf = Han[path[i-1]].lin , cf = Han[path[i-1]].col , k = cost[path[i]][path[i-1]] - 1 , ln , cn ;
    if ( ok == 1 )
    {
        while ( k > 0 )
        {
            for ( int q = 0 ; q <= 7 ; q++ )
            {
                ln = lf + dl_up[q] ;
                cn = cf + dc_up[q] ;
                if ( ln >= 1 && cn >= 1 && ln <= n && cn <= m && matrix[ln][cn] + 1 == matrix[lf][cf] )
                {
                    wayback[k].lin = ln ;
                    wayback[k].col = cn ;
                    k-- ;
                    lf = ln ;
                    cf = cn ;
                    break ;
                }
            }
        }
    }
    if ( ok == 2 )
    {
        while ( k > 0 )
        {
            for ( int q = 0 ; q <= 7 ; q++ )
            {
                ln = lf + dl_down[q] ;
                cn = cf + dc_down[q] ;
                if ( ln >= 1 && cn >= 1 && ln <= n && cn <= m && matrix[ln][cn] + 1 == matrix[lf][cf] )
                {
                    wayback[k].lin = ln ;
                    wayback[k].col = cn ;
                    k-- ;
                    lf = ln ;
                    cf = cn ;
                    break ;
                }
            }
        }
    }

    for ( int q = 1 ; q <= cost[path[i]][path[i-1]] - 1 ; q ++ )
        fout << wayback[q].lin << ' ' << wayback[q].col << '\n' ;
}


void theway()
{
    int nod = nrhanuri + 1 ;
    int st = 0 ;
    path[++st] = nod ;
    while ( nod != 0 )
    {
        nod = father[nod] ;
        path[++st] = nod ;
    }
    for ( int i = st ; i >= 2; i -- )
    {
        fout << Han[path[i]].lin << ' ' << Han[path[i]].col << '\n' ;
        lee ( Han[path[i]].lin , Han[path[i]].col , Han[path[i-1]].lin , Han[path[i-1]].col , drum[path[i]][path[i-1]]  ) ;
        print_path(i,drum[path[i]][path[i-1]]) ;
    }
    fout << Han[nrhanuri+1].lin << ' ' << Han[nrhanuri+1].col << '\n' ;
}

int main()
{
    read() ;
    do_before_djikstra() ;
    prepare_dijkstra() ;
    dijkstra() ;
    fout << '\n' ;
    theway() ;
    return 0;
}
