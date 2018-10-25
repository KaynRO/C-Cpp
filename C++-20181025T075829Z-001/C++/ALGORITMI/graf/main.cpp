#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define maxN 7505

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

vector < int > v[maxN];
queue < int > Q;
int n,m,st,dr;
int costX[maxN], costY[maxN];

void read()
{
    int a,b;
    fin>>n>>m>>st>>dr;
    while (m--)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void BFS()
{
    costX[st]=0;
    Q.push(st);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=0; i<v[x].size(); ++i)
            if (!costX[v[x][i]])
            {
                int val=costX[x]+1, nod=v[x][i];
                costX[nod]=val;
                Q.push(nod);
            }
    }

    costY[dr]=0;
    Q.push(dr);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=0; i<v[x].size(); ++i)
            if (!costY[v[x][i]])
            {
                int val=costY[x]+1, nod=v[x][i];
                costY[nod]=val;
                Q.push(nod);
            }
    }
    costX[st]=0;
    costY[dr]=0;
}

void solve()
{
    priority_queue <int, vector<int>, greater<int> > pq;
    int path=costX[dr];
    for (int i=1; i<=n; ++i) v[i].clear();
    for (int i=1; i<=n; ++i)
        if (costX[i]+costY[i]==path) v[costX[i]].push_back(i);
    for (int i=0; i<n; ++i)
        if (v[i].size()==1) pq.push(v[i][0]);
    fout<<pq.size()<<'\n';
    while (!pq.empty())
    {
        fout<<pq.top()<<" ";
        pq.pop();
    }
}

int main()
{
    read();
    BFS();
    solve();
    return 0;
}
