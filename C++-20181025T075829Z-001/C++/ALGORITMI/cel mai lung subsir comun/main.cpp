#include <cstdio>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    FOR (i, 1, M)
        scanf("%d", &A[i]);
    FOR (i, 1, N)
        scanf("%d", &B[i]);

    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);

    return 0;
}
