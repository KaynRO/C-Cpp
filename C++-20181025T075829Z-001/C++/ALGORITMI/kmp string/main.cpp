#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

ifstream fin ( "strmatch.in" ) ;
ofstream fout ( "strmatch.out" ) ;

int main()
{
    string A , B ;
    vector<int> matches ;
    fin >> A >> B ;
    int pos = 0 ;
    int n = B.find( A , pos ) ;
    while( n != string::npos)
    {
        matches.push_back(n) ;
        pos = n ;
        n = B.find( A , pos + 1 ) ;
    }
    fout << matches.size() << '\n' ;
    if ( matches.size() >= 1000 )
        for ( int i = 0 ; i <= 999 ; i++ )
            fout << matches[i] << ' ' ;
    else
        for ( vector<int> :: iterator it = matches.begin() ; it != matches.end() ; ++it )
            fout << *it << ' ' ;
    return 0 ;
}
