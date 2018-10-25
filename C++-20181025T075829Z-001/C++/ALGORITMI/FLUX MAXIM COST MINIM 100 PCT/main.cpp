#include<fstream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

#define MAXN 700

int S, D;
int n;
int F[MAXN][MAXN], C[MAXN][MAXN], K[MAXN][MAXN];
int OLDD[MAXN], REALD[MAXN], DIST[MAXN];
int PARENT[MAXN];

vector<int> G[MAXN];
void addEdge(int a, int b, int cap, int cost)
{
    G[a].push_back(b);
    G[b].push_back(a);
    C[a][b] = cap;
    K[a][b] = cost;
    K[b][a] = -cost;
}

bool INQ[MAXN];
void Bellman()
{
    queue<int> Q;

    memset(OLDD, 0xf, sizeof(OLDD));
    OLDD[S] = 0;

    Q.push(S);
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        INQ[node] = 0;

        for( vector < int > :: iterator vec = G[node].begin() ; vec != G[node].end() ; ++vec )
        {
            if(OLDD[*vec] > OLDD[node] + K[node][*vec] && F[node][*vec] < C[node][*vec])
            {
                OLDD[*vec] = OLDD[node] + K[node][*vec];
                if(!INQ[*vec])
                {
                    Q.push(*vec);
                    INQ[*vec] = 1;
                }
            }
        }
    }
}
typedef pair<int, int> pii;
#define mp make_pair
priority_queue< pii, vector<pii> >Q;

bool Dijkstra()
{
    memset(DIST, 0xf, sizeof(DIST));
    memset(REALD, 0xf, sizeof(REALD));
    memset(PARENT, 0, sizeof(PARENT));

    DIST[S] = REALD[S] = 0;
    Q.push(mp(0, S));

    while(!Q.empty())
    {
        pair < int , int > top = Q.top();
        Q.pop();
        int node = top.second;

        if(-top.first > DIST[node])
            continue;

        for(vector < int > :: iterator vec = G[node].begin() ; vec != G[node].end() ; ++vec)
        {
            if(F[node][*vec] < C[node][*vec] && DIST[*vec] > DIST[node] + OLDD[node] - OLDD[*vec] + K[node][*vec])
            {
                DIST[*vec] = DIST[node] + OLDD[node] - OLDD[*vec] + K[node][*vec];
                PARENT[*vec] = node;
                REALD[*vec] = REALD[node] + K[node][*vec];

                Q.push(mp(-DIST[*vec], *vec));
            }
        }
    }

    return PARENT[D] != 0;
}


int fmcm()
{

    int total = 0;
    Bellman();

    while(Dijkstra())
    {
        int M = (1 << 30);
        for(int node = D; node != S; node = PARENT[node])
        {
            M = min(M, C[PARENT[node]][node] - F[PARENT[node]][node]);
        }
        for(int node = D; node != S; node = PARENT[node])
        {
            F[PARENT[node]][node] += M;
            F[node][PARENT[node]] -= M;

            total += K[PARENT[node]][node] * M;
        }

        memcpy(OLDD, REALD, sizeof(OLDD));
    }

    return total;
}


int main()
{
    int m, a, b, c, d;
    fin>>n>>m>>S>>D;

    while(m--)
    {
        fin>>a>>b>>c>>d;
        addEdge(a, b, c, d);
    }

    fout<<fmcm();
    return 0;
}
