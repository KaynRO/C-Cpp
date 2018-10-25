using namespace std;
#include <cstdio>
#include <vector>
#define maxn 50001
vector<int>a[maxn];

int n;
int sol[maxn],ns;
bool use[maxn];

inline void dfs(int n)
{
    if(use[n])return ;
    use[n]=1;

    for(vector<int>::iterator i=a[n].begin(); i!=a[n].end(); ++i)
        if(!use[*i])
            dfs(*i);
    sol[++ns]=n;
}

int main()
{
    freopen("sortaret.in","r",stdin);
    int m, p, q;
    scanf("%d %d\n", &n,&m);
    while(m--)
    {
        scanf("%d %d\n", &p, &q);
        a[p].push_back(q);
    }

    int i;
    for(i=1; i<=n; ++i)
        if(!use[i]) dfs(i);

    freopen("sortaret.out","w",stdout);
    for(i=n; i>=1; --i)printf("%d ", sol[i]);
    printf("\n");
    return 0;
}
