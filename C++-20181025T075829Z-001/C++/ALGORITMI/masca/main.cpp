#include <fstream>
#include <map>
#include <cstring>
#include <string>
#include <iostream>

using namespace std ;

ifstream fin ( "masca.in" ) ;
ofstream fout ( "masca.out" ) ;

int test , n , nrp ;
string mask , line ;
map< string , int > M ;

bool compare ( string x , string mask , int posx , int posmask )
{
    if ( posx == x.lenght() && posmask == mask.lenght() )
        if  ( x[posx] == mask[posmask]  || mask[posmask] == '?' )
            return true ;
        else ;
    else
    {
        if ( mask[posmask] == x[posx] || mask[posmask] == '?' )
            compare ( x , mask , posx + 1 , posmask + 1 ) ;
        if ( mask[posmask] == '*' )
        {
            compare ( x , mask , posx , posmask + 1 ) ;
            for ( int i = 1 ; i <=  x.lenght() - mask.lenght() ; i++ )
                compare ( x , mask , posx + i , posmask + 1 ) ;
        }
    }
    return false ;
}

int main()
{
    fin >> test ;
    fin >> mask ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> line ;
        M[line]++ ;
    }
    if ( test == 1 )
        fout << M.size() ;
    else
    {
        for ( map < string , int > :: iterator it = M.begin() ; it != M.end() ; ++it )
            //if ( compare ( it->first , mask , 0 , 0 ) )
                nrp++ ;
        fout << nrp ;
    }
    return 0;
}
