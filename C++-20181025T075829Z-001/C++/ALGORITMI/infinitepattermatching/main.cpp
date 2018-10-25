#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

ifstream fin ( "infinitepatternmatching.in" ) ;
ofstream fout ( "infinitepatternmatching.out" ) ;
char P[100] ;
char T[100000] ;

int nrtobinary ( int x )
{
    int p = x , power = 1 , nr = 0 ;
    while ( p != 0 )
    {
        nr = nr + power * ( p % 2 ) ;
        power = power * 10 ;
        p = p / 2 ;
    }
    return nr ;
}

int main()
{

    fin.getline( P , 60 ) ;
    int i = 1 ;
    char *pch ;
    char nb[10000] ;
    int ok = 0 ;
    while ( ok == 0  )
    {

        int y = nrtobinary(i) ;
        sprintf ( nb , "%d" , y ) ;
        strcat ( T , nb ) ;
        if ( strstr ( T , P ) )
        {
          ok = 1 ;
          pch =  strstr ( T , P ) ;
         int position = pch - T + 1 ;
         int lenght = strlen(P) ;
         fout << position + lenght - 1 ;
          exit(0) ;
        }
        i++ ;
    }

    return 0 ;
}
