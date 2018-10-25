#include <iostream>
#include <queue>
#define DIM 1000

using namespace std ;

int dl[] = { -1, 1, 0, 0 } ;
int dc[] = { 0, 0, -1, 1 } ;

struct element
{
    int ln ;
    int cn ;
};

queue <  element > Q ;
int Mx[DIM][DIM], N, M ;

int main()
{
    element ex ;
    int nr = 1 ;

    cin >> N >> M ;
    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            cin >> Mx[i][j] ;

    for ( int i = 1 ; i <= N ; i++ )
        for ( int j = 1 ; j <= M ; j++ )
            if ( Mx[i][j] == 1 )
            {
                ++nr ;
                Mx[i][j] = nr ;
                ex.ln = i, ex.cn = j ;
                Q.push(ex) ;

                while ( !Q.empty() )
                {
                    ex = Q.front() ;
                    Mx[ex.ln][ex.cn] = nr ;
                    Q.pop() ;
                    for ( int k = 0 ; k <= 3 ; k++ )
                    {
                        int line = ex.ln + dl[k] ;
                        int colomn = ex.cn + dc[k] ;
                        if ( line >= 1 && line <= N && colomn >= 1 && colomn <= M && Mx[line][colomn] == 1 )
                        {
                            Mx[line][colomn] = nr ;
                            ex.ln = line, ex.cn = colomn ;
                            Q.push(ex) ;
                        }
                    }

                }
            }

    for ( int i = 1 ; i <= N ; i++ )
    {
        for ( int j = 1 ; j <= M ; j++ )
            cout << Mx[i][j] << ' ' ;
        cout << '\n' ;
    }

    return 0;
}
