#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin ( "seriale.in" ) ;
ofstream fout ( "seriale.out" ) ;

int n , m ;
vector <int> L1 , L2 ;

void read()
{
    int x ;
    fin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> x ;
        L1.push_back(x) ;
    }
    for ( int i = 1 ; i <= m ; i++ )
    {
        fin >> x ;
        L2.push_back(x) ;
    }
    sort ( L2.begin() , L2.end()  ) ;
}

int determine_maxim()
{
    int maxim = -1 ;
    for ( int i = 0 ; i <= L1.size() - 1 ; i++ )
        if ( L1[i] > maxim )
            maxim = L1[i] ;
    return maxim ;
}

int determine_minim()
{
    int minim = 999999 ;
    for ( int i = 0 ; i <= L1.size() - 1 ; i++ )
        if ( L1[i] < minim )
            minim = L1[i] ;
    return minim ;
}

int is_sort()
{
    for ( int i = 0 ; i <= L1.size() - 2 ; i++ )
        if ( L1[i] > L1[i+1] )
            return 0 ;
    return 1 ;
}

int main()
{
    int maxloc , minloc = 0 , nrerase = 0 ;
    int next_to_erase = 0 ;
    read() ;
    while ( !is_sort() )
    {
        maxloc = determine_maxim() ;
        L1.erase( find ( L1.begin() , L1.end() , maxloc ) ) ;
        nrerase++ ;
        if ( is_sort() )
        {
            fout << nrerase ;
            return 0 ;
        }
        L1.push_back( L2[0] ) ;
        L2.erase ( L2.begin() , L2.begin() ) ;
        minloc = determine_minim() ;
        L1.erase ( find ( L1.begin() , L1.end() , minloc) ) ;
        nrerase++ ;
        if ( is_sort() )
        {
            fout << nrerase ;
            return 0 ;
        }
        L1.push_back( L2[0] ) ;
        L2.erase ( L2.begin() , L2.begin() ) ;
    }
    return 0;
}
