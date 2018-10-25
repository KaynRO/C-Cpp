#include<iostream>
using namespace std;

char sp[]="   ";

int x[20], n, nrsol=0, max[20], maxim;

int DeterminareMaxim(int k)
{
    int maxim=0,i;
    for(i=1; i<=k; i++)
        if (x[i]>maxim) maxim=x[i];
    return maxim;
}


void Afisare()
{
    int i,j;
    cout<<sp;
    maxim=DeterminareMaxim(n);
    for(j=1; j<=maxim; j++)
    {
        cout<<"{";
        for(i=1; i<=n; i++)
            if (x[i]==j) cout<<i<<" ";
        cout<<"}  ";
    }
    cout<<endl;
    nrsol++;
    if (nrsol%22==0) cin.get();
}

void BackRec(int k)
{
    int i;
    for(i=1; i<=DeterminareMaxim(k-1)+1; i++)
    {
        x[k]=i;
        if (k==n) Afisare();
        else BackRec(k+1);
    }
}


int main()
{
    cout<<endl<<endl<<sp<<"Partiile multimii {1,2,3.....,n}"<<endl;
    cout<<endl<<sp<<" Dati valoarea lui n: ";
    cin>>n;
    cout<<endl;
    BackRec(1);
    cout<<endl<<sp<<"Numar solutii: "<<nrsol;
    return 0;
}
