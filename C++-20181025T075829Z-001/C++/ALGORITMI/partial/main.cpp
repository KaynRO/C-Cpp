#include <fstream>
#include <queue>

using namespace std;

ifstream fin ( "partial.in" ) ;
ofstream fout ( "partial.out" ) ;

int n , matrix[220][220] , nredges ;

void read()
{
    fin >> n ;
       while ( !fin.eof() )
    {
        int x , y ;
        fin >> x >> y ;
        if ( matrix[x][y] == 0 )
        nredges += 2 ;
        matrix[x][y] = matrix[y][x] = 1 ;
    }
}

int grad ( int x )
{
    int nr = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        if ( matrix[i][x] == 1 )
            nr++ ;
    return nr ;
}

void print()
{
   for ( int i = 1 ;  i <= n ; i++ )
   {
   for ( int j = 1 ; j <= n ; j++ )
   fout << matrix[i][j] << ' ' ;
   fout << '\n' ;
   }
}
int main()
{
   read() ;
   int eliminate = nredges / 2 ;
   while ( eliminate != 0 )
   {
      for ( int i = 1 ; i <= n ; i++ )
      {
         if ( eliminate == 0 ) break ;
         for ( int j = 1 ; j <= n ; j++ )
         {
         if ( eliminate == 0 ) break ;
            if ( matrix[i][j] == 1 && grad(i) > 1 && grad(j) > 1 )
            {
            matrix[i][j] = 0 ;
            matrix[j][i] = 0 ;
            eliminate -= 2  ;
            if ( eliminate == 0 ) break ;
            }
         }
      }
   }
   print() ;

    return 0;
}
