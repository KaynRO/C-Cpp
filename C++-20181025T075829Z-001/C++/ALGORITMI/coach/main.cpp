#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
#define inf 0x3fffffff

using namespace std;

ofstream fout ( "coach.out" ) ;
int n , m , tneed , vis[150] ;
queue<int> Q ;
vector<int> G[150] ;
vector<int> :: iterator it ;

void read()
{
    freopen ( "coach.in" , "r" , stdin ) ;
    scanf ( "%d %d %d" , &n , &m , &tneed ) ;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
