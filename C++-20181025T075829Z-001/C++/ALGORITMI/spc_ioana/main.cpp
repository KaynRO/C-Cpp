#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("s_p_c.in");
ofstream fout("s_p_c.out");

struct vectorstring
{
    char s[120];
}S[120],P[120],C[120];

int sub, pre, com;
char sir[120];

void afisare(char t[150])
{
    int l= strlen(t);
    for(int i=0; i<l; i++)
    {
        fout << t[i];
    }
    fout << ' ';
}

void sortare_vector(vectorstring a[120], int x)
{
    bool ok;
    char aux[120];
    while(!ok)
    {
        ok=true;
        for(int i=1; i<x-1; i++)
            if(strcmp(a[i].s, a[i+1].s)>0)
            {
                strcpy(aux, a[i].s);
                strcpy(a[i].s, a[i+1].s);
                strcpy(a[i+1].s, aux);
                ok=false;
            }
    }
}

void citire()
{
    int l;
    sub=1; pre=1; com=1;
    while(fin >> sir)
    {
        l= strlen(sir);
        if(sir[l-1]== 'S')
        {
            sir[l-2]= 0;
            strcpy(S[sub++].s, sir);
        }
        if(sir[l-1]== 'P')
        {
            sir[l-2]= 0;
            strcpy(P[pre++].s, sir);
        }
        if(sir[l-1]== 'C')
        {
            sir[l-2]= 0;
            strcpy(C[com++].s, sir);
        }
        if(sir[l-2]== 'C')
        {
            sir[l-3]= 0;
            strcpy(C[com++].s, sir);
        }
    }
}

int main()
{
    citire();
    sortare_vector(S, sub);
    sortare_vector(P, pre);
    sortare_vector(C, com);
    int i, j, x;
    for(i=1; i<sub; i++)
    {
        for(j=1; j<pre; j++)
        {
            for(x=1; x<com ; x++)
            {
                afisare(S[i].s);
                afisare(P[j].s);
                afisare(C[x].s);
                fout << '\n';
            }
        }
    }
    return 0;
}
