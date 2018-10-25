#include <bits/stdc++.h>

using namespace std;

#define MAXN 100500

int N, M, A, B;
double cost[MAXN];
vector<int> G[MAXN];
int in[MAXN];
queue<int> Q;
int order[MAXN];
double dp[MAXN];

int main()
{
    assert(freopen("hektor.in", "r", stdin));
    assert(freopen("hektor.out", "w", stdout));
    cin.sync_with_stdio(false);

    cin >> N >> M >> A >> B;
    A--;
    B--;
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        in[b]++;
    }

    for (int i = 0; i < N; i++)
    {
        if (in[i] == 0)
        {
            Q.push(i);
        }
    }
    int K = 0;
    while (!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        order[K++] = p;
        for (int x : G[p])
        {
            in[x]--;
            if (in[x] == 0)
            {
                Q.push(x);
            }
        }
    }

    for (int k = K - 1; k >= 0; k--)
    {
        int p = order[k];

        int num = 0;
        for (int x : G[p])
        {
            if (dp[x] > 0.0)
            {
                num++;
            }
        }

        if (num > 0)
        {
            for (int x : G[p])
            {
                dp[p] += dp[x];
            }
            dp[p] /= num;
        }

        if (p == B || dp[p] > 0.0)
        {
            dp[p] += cost[p];
        }
    }

    cout << fixed << setprecision(10) << dp[A] << endl;

    return 0;
}
