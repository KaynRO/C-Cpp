#include <fstream>

using namespace std;

ifstream fin ( "nr.in" ) ;
ofstream fout ( "nr.out" ) ;

int nrcif[100000] , m ;

int nrcifre ( int x )
{
    int copie = x , nr = 0 ;
    while ( copie != 0 )
    {
        nr++ ;
        copie /= 10 ;
    }
    return nr ;
}
void let()
{
    int i = 1 ;
    int total = 0 ;
    while ( total <= 600000 )
    {
        nrcif[i] = nrcifre(i) ;
        total += nrcifre(i) ;
        i++ ;
    }
}

int src()
{
     int tt = 0 ;
     int i = 1 ;
     while ( tt != m )
     {
       tt += nrcif[i] ;
       i++ ;
     }
     if ( tt == m )
     fout << i%10 ;
}

int main()
{
    int k ;
    fin >> m ;
    let() ;
    src() ;
    return 0;
}



