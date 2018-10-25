#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 20;
const int MAXX = 262150;
const int INF = 100000000;

int N, M, Sol;
int Cost[MAXN][MAXN];
int C[MAXX][MAXN];
vector <int> A[MAXN];

int main()
{
    ifstream fin("hamilton.in");
    ofstream fout("hamilton.out");

    fin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) Cost[i][j] = INF;

    for (int i = 1; i <= M; ++i)
    {
        int x, y;

        fin >> x >> y;
        A[y].push_back(x);
        fin >> Cost[x][y];
    }

    for (int i = 0; i < 1 << N; ++i)
        for (int j = 0; j < N; ++j) C[i][j] = INF;

    C[1][0] = 0;

    for (int i = 0; i < 1 << N; ++i)
        for (int j = 0; j < N; ++j)
            if (i & (1<<j))
                for (size_t k = 0; k < A[j].size(); ++k)
                    if (i & (1<<A[j][k]))
                        C[i][j] = min(C[i][j], C[i ^ (1<<j)][ A[j][k] ] + Cost[ A[j][k] ][j]);

    Sol = INF;
    for (size_t i = 0; i < A[0].size(); ++i)
        Sol = min(Sol, C[(1<<N) - 1][ A[0][i] ] + Cost[ A[0][i] ][0]);

    if (Sol == INF) fout << "Nu exista solutie" << endl;
    else fout << Sol << endl;

    return 0;
}
