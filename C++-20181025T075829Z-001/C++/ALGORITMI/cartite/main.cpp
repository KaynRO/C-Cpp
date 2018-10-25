#include <fstream>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

ofstream fout ( "cartite.out" ) ;
int n , m , matrix[230][230] , vis[200] , test , line_start , colomn_start , euler_lenght , nrfoxes , beg = 0 ;
int dlr1[] = { 1 , 0 , -1 , 0 } ;
int dcr1[] = { 0 , 1 , 0 , -1 } ;
int dlr2[] = { -2 , -1 , -1 , -1 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 2 } ;
int dcr2[] = { 0 , -1 , 0 , 1 , -2 , -1 , 1 , 2 , -1 , 0 , 1 , 0 } ;
queue < pair < int , int > > Q ;
vector <int> G1[500] ;
int start = 0 ;
stack <int> st ;
int l[1200] , new_node ;

struct fox
{
    int lin ;
    int col ;
    int range ;
} F[60] ;

struct bundle
{
    int ls ;
    int cs ;
    int lf ;
    int cf ;
} B[150] ;

struct point
{
    int ln ;
    int cn ;
} P[200] ;

void read()
{
    freopen ( "cartite.in" , "r" , stdin ) ;
    scanf ( "%d" , &test ) ;
    scanf ( "%d %d" , &n , &m ) ;
    scanf ( "%d %d" , &line_start , &colomn_start ) ;
    scanf ( "%d" , &nrfoxes ) ;
    for ( int i = 1 ; i <= nrfoxes ; i++ )
        scanf ( "%d %d %d" , &F[i].lin , &F[i].col , &F[i].range ) ;
    scanf ( "%d" , &euler_lenght ) ;
    for ( int i = 1 ; i <= euler_lenght ; i++ )
        scanf ( "%d %d %d %d" , &B[i].ls , &B[i].cs , &B[i].lf , &B[i].cf ) ;
}

int src(int xs , int ys , int &stop )
{
    for ( int i = 1 ; i <= stop ; i++ )
        if ( P[i].ln == xs && P[i].cn == ys )
            return 0 ;
    P[++stop].ln = xs ;
    P[stop].cn = ys ;
    return 1 ;
}
void prepare_for_lee()
{
    for ( int i = 1 ; i <= euler_lenght ; i++ )
    {
        matrix[B[i].ls][B[i].cs] = -2 ;
        matrix[B[i].lf][B[i].cf] = -2 ;
    }
    for ( int i = 1 ; i <= euler_lenght ; i++ )
    {
        src ( B[i].ls , B[i].cs , beg ) ;
        src ( B[i].lf , B[i].cf , beg ) ;
    }
    for ( int i = 1 ; i <= nrfoxes ; i++ )
    {
        matrix[F[i].lin][F[i].col] = -1 ;
        if ( F[i].range != 0 )
        {
            if ( F[i].range == 1 )
            {
                for ( int j = 0 ; j <= 3 ; j++ )
                    if ( F[i].lin+dlr1[j] >= 1 && F[i].lin+dlr1[j] <= n && F[i].col+dcr1[j] >= 1 && F[i].col+dcr1[j] <= m )
                        matrix[F[i].lin+dlr1[j]][F[i].col+dcr1[j]] = -1 ;
            }
            else
            {
                for ( int j = 0 ; j <= 11 ; j++ )
                    if ( F[i].lin+dlr2[j] >= 1 && F[i].lin+dlr2[j] <= n && F[i].col+dcr2[j] >= 1 && F[i].col+dcr2[j] <= m )
                        matrix[F[i].lin+dlr2[j]][F[i].col+dcr2[j]] = -1 ;
            }
        }
    }
}

int pos ( int xs , int ys )
{
    for ( int i = 1 ; i <= beg ; i++ )
        if ( P[i].ln == xs && P[i].cn == ys )
            return i ;
}

void construct_graph()
{
    int index1 , index2 ;
    for ( int i = 1 ; i <= euler_lenght ; i++ )
    {
        index1 = pos (B[i].ls , B[i].cs ) ;
        index2 = pos ( B[i].lf , B[i].cf ) ;
        G1[index1].push_back(index2) ;
        G1[index2].push_back(index1) ;
    }
}

int lee ( int xs , int ys )
{
    Q = queue < pair < int , int > > () ;
    matrix[xs][ys] = 1 ;
    int line , colomn ;
    Q.push( make_pair( xs , ys ) ) ;
    int ln , cn ;
    while ( !Q.empty() )
    {
        line = Q.front().first ;
        colomn = Q.front().second ;
        Q.pop() ;
        for ( int i = 0 ; i <= 3 ; i++ )
        {
            ln = line + dlr1[i] ;
            cn = colomn + dcr1[i] ;
            if ( ln >= 1 && cn >= 1 && ln <= n && cn <= m )
            {
                if ( matrix[ln][cn] == 0 || matrix[ln][cn] == -2 )
                {
                    if ( matrix[ln][cn] == -2 )
                    {
                        fout << ln << ' ' << cn << ' ' ;
                        matrix[ln][cn] = matrix[line][colomn] + 1 ;
                        fout << matrix[ln][cn] - 1 ;
                        return 0 ;
                    }
                    else
                    {
                        matrix[ln][cn] = matrix[line][colomn] + 1 ;
                        Q.push ( make_pair( ln , cn ) ) ;
                    }
                }
            }

        }

    }
    return 0 ;
}

void euler_path ( int node )
{
    st.push(node) ;
    while( !st.empty() )
    {
        node = st.top() ;
        l[node] = G1[node].size() ;
        if( l[node] )
        {
            new_node = G1[node].back() ;
            st.push(new_node) ;
            G1[new_node].erase( find ( G1[new_node].begin() , G1[new_node].end() , node ) ) ;
            G1[node].pop_back() ;
        }
        else
        {
            vis[++start] = node ;
            st.pop() ;
        }
    }
}
int main()
{
    read() ;
    prepare_for_lee() ;
    if ( test == 1 )
    {
        if ( matrix[line_start][colomn_start] == -2 )
            fout << line_start << ' ' << colomn_start << ' ' << "0" << '\n' ;
        else
            lee ( line_start , colomn_start ) ;
    }
    else
    {
        int q = 1 ;
        construct_graph() ;
        for ( int i = 1 ; i <= beg ; i++ )
            l[i] = G1[i].size() ;
        for ( int i = 1 ; i <= beg ; i++ )
            if ( l[i] != 0 )
                euler_path(i) ;
        for ( int i = 1 ; i <= start ; i++ )
            fout << P[vis[i]].ln << ' ' << P[vis[i]].cn << '\n' ;
    }
    return 0;
}
