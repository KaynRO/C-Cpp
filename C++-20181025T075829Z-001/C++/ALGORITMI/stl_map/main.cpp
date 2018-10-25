#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

ifstream fin ( "ex.in" ) ;
ofstream fout ( "ex.out" ) ;
map<int,map<int,int> > M ;
map<int,int > mq ;
map<int,int > :: iterator mqi ;
map<int,map<int,int> > ::iterator it ;

int main()
{
    int m , x , y , z ;
    fin >> m ;
    {
        for ( int i = 1 ; i <= m ; i++ )
        {
            fin >> x >> y >> z ;
            if ( M[x].find(y) == M[x].end() )
            {
                mq.insert ( make_pair ( y , z ) ) ;
                M[x].insert ( make_pair ( y , z ) ) ;
            }
            else
                M[x][y] = min ( M[x][y] , z ) ;
        }
    }
    for ( it = M.begin() ; it != M.end() ; ++it )
        for ( mqi = M[it->first].begin() ; mqi != M[it->first].end() ; ++mqi )
            fout <<  it->first << ' ' << mqi->first << ' ' << mqi->second << '\n' ;

    return 0;
}
