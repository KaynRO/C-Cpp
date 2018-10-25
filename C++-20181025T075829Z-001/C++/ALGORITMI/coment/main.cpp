#include <fstream>
#define NMaxVf 101
using namespace std ;
ifstream fin ( "coment.in" ) ;
ofstream fout( "coment.out" ) ;
unsigned G[NMaxVf][NMaxVf];
unsigned uz[NMaxVf];
unsigned n;
struct Nod
{
    int v;
    Nod * urm;
};
typedef Nod* Lista;
Lista d;

void Citire()
{
    int x, y;
    fin>>n;
    int m=n*(n-1)/2;
    for (int i=1; i<=m; i++)
    {
        fin>>x>>y;
        G[x][y]=1;
    }
    fin.close();
}

void Scrie()
{
    Lista p=d;
    while (p)
    {
        fout<<p->v;
        if (p->urm)
            fout<<' ';
        p=p->urm;
    }
    fout<<'\n';
    fout.close();
}

int cautpred(int vf)
{
    for (int i=1; i<=n; i++)
        if (!uz[i] && G[i][vf]) return i;
    return 0;
}

int cautsucc(int vf)
{
    for (int i=1; i<=n; i++)
        if (!uz[i] && G[vf][i]) return i;
    return 0;
}

void Determina()
{
    Lista p, sf, pq, q;
    int vf;
    d=new Nod;
    d->v=1;
    d->urm=NULL;
    uz[1]=1;
    vf=1;
    sf=d;
    while (vf)
    {
        vf=cautpred(vf);
        if (vf)
        {
            p=new Nod;
            p->v=vf;
            p->urm=d;
            d=p;
            uz[vf]=1;
        }
    }
    vf=1;
    while(vf)
    {
        vf=cautsucc(vf);
        if (vf)
        {
            p=new Nod;
            p->v=vf;
            p->urm=NULL;
            sf->urm=p;
            sf=p;
            uz[vf]=1;
        }
    }
    for (vf=2; vf<=n; vf++)
        if (!uz[vf]) //inserez vf pe pozitia corecta pe lant
        {
            pq=d;
            q=d->urm;
            while (G[q->v][vf])
            {
                pq=q;
                q=q->urm;
            }
            p=new Nod;
            p->v=vf;
            p->urm=q;
            pq->urm=p;
            uz[vf]=1;
        }



}
int main()
{
    Citire();
    Determina();
    Scrie();
    return 0;
}
