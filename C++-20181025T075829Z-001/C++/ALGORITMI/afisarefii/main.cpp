#include <fstream>
#include <vector>

using namespace std;

ifstream fin ( "afisarefii.in" ) ;
ofstream fout ( "afisarefii.out" ) ;

vector<int> Son[200] ;
int n , k , father[200] ;

int main()
{
    fin >> n ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        fin >> father[i] ;
        Son[father[i]].push_back(i) ;
    }
    fin >> k ;
    int node ;
    for ( int i = 1 ; i <= k ; i++ )
    {
        fin >> node ;
        fout << Son[node].size() << ' ' ;
        for ( vector<int> :: iterator it = Son[node].begin() ; it != Son[node].end() ; ++it )
            fout << *it << ' ' ;
        fout << '\n' ;
    }
    return 0;
}
