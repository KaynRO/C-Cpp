#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
void rezolvare(FILE*fin,FILE*fout,int steps);
void rezolvare_s_d(FILE*fin, FILE*fout, int steps);
void rezolvare_comprimat(FILE*fin, FILE*fout, int steps);
void rezolvare_stabil(FILE*fin, FILE*fout, int steps);
void extinde(int **GI, int N, int M)
{
    int i, j;
    for (i = 1; i <= M; i++)
    {
        GI[0][i] = GI[N][i];
        GI[N + 1][i] = GI[1][i];
    }
    for (j = 1; j <= N; j++)
    {
        GI[j][0] = GI[j][M];
        GI[j][M + 1] = GI[j][1];
    }
    GI[0][0] = GI[N][M];
    GI[0][M + 1] = GI[N][1];
    GI[N + 1][0] = GI[1][M];
    GI[N + 1][M + 1] = GI[1][1];

}
void rezolvare_generala(int **GI, int **nextG, int N, int M,int steps);
void afisare(FILE *fout,int**GI, int N, int M);
int main(int argc, char *argv[])
{
    int  i, j, k = 0, nrv = 0, steps = 0, N = 0, M = 0, comprimat = 0, s_d = 0, stabil = 0;
    FILE *fin = NULL, *fout = NULL;
    for (i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-in") == 0)
        {
            fin = fopen(argv[i + 1], "r");
        }
        if (strcmp(argv[i], "-out") == 0)
        {
            fout = fopen(argv[i + 1], "w");
        }
        if (strcmp(argv[i], "-steps") == 0)
        {
            steps = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], "-comprimat") == 0)
        {
            comprimat = 1;
        }
        if (strcmp(argv[i], "-super_dinamic") == 0)
        {
            s_d = 1;
        }
        if (strcmp(argv[i], "-stabil") == 0)
        {
            stabil = 1;
        }
    }
    if (fin == NULL)
    {
        fprintf(fout, "Fisierul nu exista!");
    }
    else
    {
        if (s_d == 1)
        {
            rezolvare_s_d(fin,fout,steps);
        }
        if (comprimat == 1)
        {
            rezolvare_comprimat(fin, fout, steps);
        }
        if (stabil == 1)
        {
            rezolvare_stabil(fin, fout, steps);
        }
        if (s_d == 0 && comprimat == 0 && stabil == 0)
        {
            rezolvare(fin, fout, steps);
        }
    }

    return 0;
}

void rezolvare_stabil(FILE *fin, FILE *fout, int steps)
{
    int **GI = NULL, **nextG = NULL;
    int** Stabil;
    int **p=NULL;
    int n = 0, m = 0,contor = 0, u0 = 0, u1 = 0, aux = steps;
    int jul = 1,iul;
    int i, j, vecini, k;
    int dl[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    fscanf(fin, "%d %d", &n, &m);
    if (n < 3 || m < 3)
    {
        fprintf(fout, "Configuratie invalida");

    }
    else
    {
        GI = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            GI[i] = (int *)calloc((m + 2), sizeof(int));
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                fscanf(fin, "%d", &GI[i][j]);
            }
        nextG = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            nextG[i] = (int *)calloc((m + 2), sizeof(int));
        }
        extinde(GI, n, m);
        Stabil = (int**)calloc((steps+1), sizeof(int*));
        for(i=1; i<=n; i++)
            for (j = 1; j <= m; j++)
            {
                if (GI[i][j] == 1)
                {
                    contor++;
                }
            }
        Stabil[1] = (int *)calloc((contor + 2), sizeof(int));
        Stabil[1][0] = contor;

        contor = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                if (GI[i][j] == 1)
                {
                    contor++;
                    Stabil[1][contor] = (i - 1)*m + j - 1;
                }
            }
    }
    int gasit = 1;
    while (steps&&gasit)
    {

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                vecini = 0;
                for (k = 0; k < 8; k++)
                    if (GI[i + dl[k]][j + dc[k]] == 1)
                        vecini++;
                if (GI[i][j] == 1)
                {
                    if (vecini < 2 || vecini > 3) nextG[i][j] = 0;
                    else
                        nextG[i][j] = GI[i][j];
                }
                else if (vecini == 3)
                    nextG[i][j] = 1;
            }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                GI[i][j] = nextG[i][j];
        contor = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                if (GI[i][j] == 1)
                {
                    contor++;
                }
            }
        Stabil[2] = (int *)calloc((contor + 2), sizeof(int));
        Stabil[2][0] = contor;
        contor = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                if (GI[i][j] == 1)
                {
                    contor++;
                    Stabil[aux-steps+2][contor] = (i - 1)*m + j - 1;
                }
            }
        for (iul = 1; iul < aux - steps + 2 && gasit!=0; iul++)
        {
            if (Stabil[aux - steps + 2][0] == Stabil[iul][0])
            {
                for (jul = 1; jul <= contor; jul++)
                {
                    if (Stabil[aux - steps + 2][contor] == Stabil[jul][contor])
                    {

                    }
                    else
                        break;
                }
                if (jul > contor)
                {
                    gasit = 0;

                }
            }
        }

        for (i = 1; i <= m; i++)
        {
            GI[0][i] = GI[n][i];
            GI[n + 1][i] = GI[1][i];
        }
        for (j = 1; j <= n; j++)
        {
            GI[j][0] = GI[j][m];
            GI[j][m + 1] = GI[j][1];
        }
        GI[0][0] = GI[n][m];
        GI[0][m + 1] = GI[n][1];
        GI[n + 1][0] = GI[1][m];
        GI[n + 1][m + 1] = GI[1][1];
        steps--;
    }
    if (steps == 0)
    {
        fprintf(fout,"Nu a fost gasita o configuratie stabila. \n");
        afisare(fout, GI, n, m);
    }
    else
    {
        steps = aux - steps;
        fprintf(fout,"Configuratie stabila la pasul:%d \n", steps);
        afisare(fout, GI, n, m);
    }
}
void rezolvare_s_d(FILE *fin, FILE *fout, int steps)
{
    int **GI = NULL, **nextG = NULL;
    int n=0, m=0, i, j,contor=0,u0=0,u1=0;
    int *p,*t=NULL;
    char c;
    while (!feof(fin))
    {
        u0 = 0, u1 = 0;
        fscanf(fin, "%c", &c);
        if (c =='\n'&&m==0)
        {
            m = contor;
        }
        if (c == '0' || c == '1')
        {
            contor++;

            if (c == '0')
            {
                p = (int *)realloc(t,contor*sizeof(int));
                if (p != NULL)
                {
                    t = p;
                    t[contor - 1] = 0;
                }
                else
                {
                    free(t);
                }

            }
            if (c == '1')
            {
                p = (int *)realloc(t, contor * sizeof(int));

                if (p != NULL)
                {
                    t = p;
                    t[contor - 1] = 1;
                }
                else
                {
                    free(t);
                }
            }
        }

    }
    n = contor / m;

    GI = (int **)malloc((n + 2) * sizeof(int *));
    for (i = 0; i <= n + 1; i++)
    {
        GI[i] = (int *)calloc((m + 2), sizeof(int));
    }
    for(i=1; i<=n; i++)
        for (j = 1; j <= m; j++)
        {
            GI[i][j] = t[(i-1)*m + j - 1];
        }
    free(t);
    nextG = (int **)malloc((n + 2) * sizeof(int *));
    for (i = 0; i <= n + 1; i++)
    {
        nextG[i] = (int *)calloc((m + 2), sizeof(int));
    }
    extinde(GI, n, m);
    rezolvare_generala(GI, nextG, n, m, steps);
    afisare(fout, GI, n, m);
    for (i = 0; i <= n + 1; i++)
    {
        free(GI[i]);

    }
    free(GI);
    for (i = 0; i <= n + 1; i++)
    {
        free(nextG[i]);

    }
    free(nextG);

}
void rezolvare_comprimat(FILE *fin, FILE *fout, int steps)
{
    int **GI = NULL, **nextG = NULL;
    int n, m, i, j;
    fscanf(fin, "%d %d", &n, &m);
    if (n < 3 || m < 3)
    {
        fprintf(fout, "Configuratie invalida");

    }
    else
    {
        GI = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            GI[i] = (int *)calloc((m + 2), sizeof(int));
        }
        nextG = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            nextG[i] = (int *)calloc((m + 2), sizeof(int));
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                GI[i][j]=0;
            }
        while (!feof(fin))
        {
            int a, b;
            fscanf(fin, "%d %d", &a, &b);
            GI[a + 1][b + 1] = 1;

        }
    }
    extinde(GI, n, m);
    rezolvare_generala(GI, nextG, n, m, steps);
    afisare(fout, GI, n, m);
    for (i = 0; i <= n + 1; i++)
    {
        free(GI[i]);

    }
    free(GI);
    for (i = 0; i <= n + 1; i++)
    {
        free(nextG[i]);

    }
    free(nextG);

}
void rezolvare(FILE *fin,FILE *fout,int steps)
{
    int **GI=NULL, **nextG=NULL;
    int n,m,i,j;
    fscanf(fin, "%d %d", &n, &m);
    if (n < 3 || m < 3)
    {
        fprintf(fout, "Configuratie invalida");

    }
    else
    {
        GI = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            GI[i] = (int *)calloc((m + 2), sizeof(int));
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
            {
                fscanf(fin, "%d", &GI[i][j]);
            }
        nextG = (int **)malloc((n + 2) * sizeof(int *));
        for (i = 0; i <= n + 1; i++)
        {
            nextG[i] = (int *)calloc((m + 2), sizeof(int));
        }

        extinde(GI, n, m);
        rezolvare_generala(GI, nextG, n, m, steps);
        afisare(fout, GI, n, m);
        for (i = 0; i <= n + 1; i++)
        {
            free(GI[i]);

        }
        free(GI);
        for (i = 0; i <= n + 1; i++)
        {
            free(nextG[i]);

        }
        free(nextG);

    }
}

void rezolvare_generala(int **GI, int **nextG, int N, int M,int steps)
{
    int i, j, vecini,k;
    int dl[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    while (steps)
    {

        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
            {
                vecini = 0;
                for (k = 0; k < 8; k++)
                    if (GI[i + dl[k]][j + dc[k]] == 1)
                        vecini++;
                if (GI[i][j] == 1)
                {
                    if (vecini < 2 || vecini > 3) nextG[i][j] = 0;
                    else
                        nextG[i][j] = GI[i][j];
                }
                else if (vecini == 3)
                    nextG[i][j] = 1;
            }
        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
                GI[i][j] = nextG[i][j];
        for (i = 1; i <= M; i++)
        {
            GI[0][i] = GI[N][i];
            GI[N + 1][i] = GI[1][i];
        }
        for (j = 1; j <= N; j++)
        {
            GI[j][0] = GI[j][M];
            GI[j][M + 1] = GI[j][1];
        }
        GI[0][0] = GI[N][M];
        GI[0][M + 1] = GI[N][1];
        GI[N + 1][0] = GI[1][M];
        GI[N + 1][M + 1] = GI[1][1];
        steps--;
    }

}
void afisare(FILE*fout,int**GI, int N, int M)
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (GI[i][j] == 1)
                fprintf(fout, "1 ");
            else
                fprintf(fout, "0 ");
        }
        fprintf(fout, "\n");
    }

}
