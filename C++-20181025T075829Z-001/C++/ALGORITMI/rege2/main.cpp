#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int maxn = 100005;
const int inf = (1 << 30);

vector <pair<int, int> > g[maxn];
int n, s, cnt, dp[maxn];

void dfs(int node, int father, int &energy)
{
    dp[node] = -1;
    for(auto it : g[node])
    {
        if(it.first == father)
            continue;
        dfs(it.first, node, energy);
        if(dp[it.first] - it.second < 0)
        {
            ++ cnt;
            dp[it.first] = energy;
        }
        if(dp[it.first] - it.second > dp[node])
            dp[node] = dp[it.first] - it.second;
    }
    if(dp[node] == -1)
    {
        ++ cnt;
        dp[node] = energy;
    }
}

bool check(int energy)
{
    cnt = 0;
    dfs(1, 0, energy);
    //cerr << energy << ' ' << cnt << '\n';
    return cnt <= s;
}

int main()
{
    freopen("rege.in", "r", stdin);
    freopen("rege.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n >> s;
        int li = 0, ls = inf;
        for(int i = 1 ; i < n; ++ i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x].push_back(make_pair(y, z));
            g[y].push_back(make_pair(x, z));
            li = max(li, z);
        }
        int ans = -1;
        while(li <= ls)
        {
            int mid = li + (ls - li) / 2;
            if(check(mid))
            {
                ans = mid;
                ls = mid - 1;
            }
            else
                li = mid + 1;
        }
        cout << ans << '\n';
        for(int i = 1 ; i <= n ; ++ i)
        {
            vector <pair<int, int> > ().swap(g[i]);
        }
    }
}
