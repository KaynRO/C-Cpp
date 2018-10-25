#include <fstream>
#include <cstdio>
using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

int n,m,p,nr,q,dp[20][250005];


int main()
{
    f>>n>>m;
    for (int i=1; i<=n; ++i)
        f>>dp[0][i];

    for (int j=1; (1<<j)<=n; ++j)
        for (int i=1; i<=n; ++i)
            dp[j][i]=dp[j-1][dp[j-1][i]];

    for (int i=1; i<=m; ++i)
    {
        f>>q>>p;
        for (int j = 0; (1<<j) <= p; ++j)
            if ((1<<j) & p)
                q = dp[j][q];
        g<<q<<'\n';
    }
    return 0;
}
