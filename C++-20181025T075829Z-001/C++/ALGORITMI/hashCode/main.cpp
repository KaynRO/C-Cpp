#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define START 100000

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

long long Rank[START] , TT[START] ;

struct RIDE{
	pll time,start,fin;
	ll ind;
} R[1000100];

struct edge
{
    int xx ;
    int yy ;
    int cost ;
};

vector < edge > APM , GG ;

bool compare_test ( struct edge a , struct edge b )
{
    return a.cost < b.cost ;
}

int father ( int node )
{
    while ( node != TT[node] )
        node = TT[node] ;
    return node ;
}

void Union ( int x , int y )
{
    if ( Rank[x] > Rank[y] )
        TT[y] = x ;
    else TT[x] = y ;
    if ( Rank[x] == Rank[y] )
        Rank[y]++ ;
}

struct VEHICLE{
	ll fin,ind;
	pll poz;
} V[1000100];

ll N,M,Veh,Rid,Bon,Steps,S[1000100];
vll G[1000100];

ll dist(pll a, pll b){return abs(a.x-b.x) + abs(a.y-b.y);}

bool cmp(RIDE &a,RIDE &b){
	return (a.time.y-a.time.x) > (b.time.y-b.time.x);
}

void doAPM()
{
    int xx , yy ;
    for ( int i = 1 ; i <= START ; i++ )
        TT[i] = i ;
    sort(GG.begin() , GG.end() , compare_test) ;

    for ( vector < edge > :: iterator it = GG.begin() ; it != GG.end() ; ++it )
    {
        xx = father ( it->xx ) ;
        yy = father ( it->yy ) ;
        if ( xx != yy )
        {
            Union ( xx , yy ) ;
            APM.push_back(*it) ;
        }
    }


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Veh >> Rid >> Bon >> Steps;

	for(int i = 0;i<Rid;i++) {
		cin >> R[i].start.x >> R[i].start.y >> R[i].fin.x >> R[i].fin.y >> R[i].time.x >> R[i].time.y;
	}

	sort(R,R+Rid,cmp);

	for(int i = 0;i<Rid;i++){
		if(dist({0,0},R[i].start) <= R[i].time.x) G[START].pb(i);

		for(int j = 0;j<Rid;j++)
			if(i!=j){
				if(R[i].time.x < R[j].time.y + dist(R[j].fin,R[i].start)) {G[j].pb(i) ; edge XX ; XX.xx = j ; XX.yy = i ; XX.cost = i ;GG.push_back(XX) ;}
				else
				if(R[j].time.x < R[i].time.y + dist(R[i].fin,R[j].start)) {G[j].pb(i) ; edge XX ; XX.xx = j ; XX.yy = i ; XX.cost = i ;GG.push_back(XX) ;}
			}
	}

	doAPM() ;


	return 0;
}
