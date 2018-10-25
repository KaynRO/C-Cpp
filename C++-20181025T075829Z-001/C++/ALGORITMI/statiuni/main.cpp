#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100010;
const int inf = 0x3f3f3f3f;

int N, K;
int DP[NMAX][2][2];
vector<int> T[NMAX];

void updateDP(int current[2][2], int next[2][2])
{
    if (current[0][0] > next[0][0] + 1)
    {
        current[1][0] = current[0][0];
        current[1][1] = current[0][1];
        current[0][0] = next[0][0] + 1;
        current[0][1] = next[0][1];
    }
    else if (current[1][0] > next[0][0] + 1 && next[0][1] != current[0][1])
    {
        current[1][0] = next[0][0] + 1;
        current[1][1] = next[0][1];
    }
    if (current[1][0] > next[1][0] + 1 && next[1][1] != current[0][1])
    {
        current[1][0] = next[1][0] + 1;
        current[1][1] = next[1][1];
    }
}

void downDFS(int node, int from)
{
    if (T[node].size() == 1)
    {
        DP[node][0][0] = 0;
        DP[node][0][1] = node;
        if (from)
            return;
    }
for (const int &it: T[node])
    {
        if (it == from)
            continue;
        downDFS(it, node);
        updateDP(DP[node], DP[it]);
    }
}

void upDFS(int node, int from)
{
    if (from)
        updateDP(DP[node], DP[from]);
for (const int &it: T[node])
    {
        if (it == from)
            continue;
        updateDP(DP[it], DP[node]);
        upDFS(it, node);
    }
}

int main()
{
    assert(freopen("statiuni.in", "r", stdin));
    assert(freopen("statiuni.out", "w", stdout));

    int i;
    scanf("%d %d", &N, &K);
    for (i = 1; i < N; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        T[x].push_back(y);
        T[y].push_back(x);
    }

    memset(DP, inf, sizeof DP);
    downDFS(1, 0);
    upDFS(1, 0);

    int answer = 0;
    for (i = 1; i <= N; ++i)
        if (DP[i][0][0] <= K && DP[i][1][0] <= K)
            ++answer;
    cout << answer << '\n';

    return 0;
}
