#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define IN "chei.in"
#define OUT "chei.out"
#define NMAX 100005

FILE *fin = fopen(IN, "r");
FILE *fout = fopen(OUT, "w");

int n, m;
int viz[NMAX];
int viz2[NMAX];
int predecesor[NMAX];
vector<int> matrice[NMAX];
stack<int> stiva;

void dfs(int);

int main()
{
    int i, j, contor, solutie=0, nod;
    fscanf(fin, "%d", &n);
    for(j = 1; j <= n; ++j)//liste de adiacenta
    {
        fscanf(fin, "%d", &i);
        matrice[i].push_back(j);
        predecesor[j] = i;
    }

    for(contor = 1; contor <= n; ++contor)
    {//plec de la fiecare purcelus
        if(viz[contor]==0)    //inca nu e vizitat
        {
            ++solutie;        //am o solutie (unul 'spart')
            viz2[contor] = solutie;  //marchez
            nod = predecesor[contor];//cat predecesorul
            while(viz2[nod] != solutie)//caut circuitul
            {
                viz2[nod] = solutie;
                nod = predecesor[nod];
            }
            dfs(nod);    //fac DFS de la nod ca sa-i marchez pe toti ca rezovati
        }
    }
    fprintf(fout,"%d\n", solutie);
    fclose(fin);
    fclose(fout);
    return 0;
}

void dfs(int start)
{
    int element, z;
    unsigned int i;
    viz[start] = 1;       //plec de aici
    stiva.push(start);    //pun in stiva
    while(!stiva.empty()) //mai am pe stiva?
    {
        element = stiva.top();  //iau din varf
        z = -1;
        for(i = 0; i < matrice[element].size(); ++i)
        {           //parcurg lista nodului 'element'
            if(viz[matrice[element][i]] == 0)
            {
                z = matrice[element][i];   //am gasit
                break;
            }
        }
        if(z == -1)       //daca nu am gasit
            stiva.pop();  //trec la urmatorul in stiva
        else              //daca am gasit
        {
            stiva.push(z);//il pun pe stiva
            viz[z] = 1;   //si-l marchez
        }
    }
}
