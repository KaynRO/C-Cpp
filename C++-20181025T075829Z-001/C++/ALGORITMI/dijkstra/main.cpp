#include <cstdio>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int N = 50000;

struct muchie
{
    int nod;
    int cost;
};



vector<muchie> vecin[1 + N];
queue<int> coadaBF;

int vizite[N + 1];
int dist[N + 1];
bool inCoada[N + 1];

int main()
{
    FILE *fin, *fout;

    fin = fopen("dijkstra.in", "r");
    fout = fopen("dijkstra.out", "w");

    int n, m;

    fscanf(fin, "%d %d", &n, &m);

    for(int i = 1; i <= m; i++)
    {
        int u, v, c;
        fscanf(fin, "%d%d%d", &u, &v, &c);
        vecin[u].push_back({v, c});
    }

    coadaBF.push(1);
    inCoada[1] = true;
    //[1] = 1;
    for(int i = 2; i <= n; i++)
        dist[i] = 0x3fffffff;

    while(!coadaBF.empty())
    {
        int nod = coadaBF.front();
        coadaBF.pop();
        inCoada[nod] = false;
        for(int i = 0; i < vecin[nod].size(); i++)
        {
            if(dist[vecin[nod][i].nod] > dist[nod] + vecin[nod][i].cost)
            {
                dist[vecin[nod][i].nod] = dist[nod] + vecin[nod][i].cost;
                if(!inCoada[vecin[nod][i].nod])
                {
                    coadaBF.push(vecin[nod][i].nod);
                    inCoada[vecin[nod][i].nod] = true;
                }
            }

            //vizite[vecin[nod][i].nod]++;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == 0x3fffffff)
            dist[i] = 0;
        fprintf(fout, "%d ", dist[i]);
    }

    return 0;
}
