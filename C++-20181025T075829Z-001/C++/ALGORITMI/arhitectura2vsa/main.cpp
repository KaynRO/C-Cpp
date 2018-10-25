#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("arhitectura2.in");
ofstream fout ("arhitectura2.out");

int v[1000010],n,maxim;
bool a[2000010];

int main()
{
    int i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        int x;
        fin>>x;
        v[x]++;
        if(x>maxim)
            maxim=x;
    }
    cout<<"0";
    for(i=maxim;i>=2;i--)
    {
        int dist=1;
        if(v[i]>2)
                {
                    while(v[i]>2)
                    {
                        v[i]--;
                        cout<<"1";
                    }
                    cout<<"0";
                    break;
                }
        else if(v[i]==2)
            cout<<"00";
        else if(v[i])
        {
            while(!v[i+dist]&&!v[i-dist])
                dist++;
            if(v[i+dist]&&v[i-dist])
                cout<<"1";
            else
                cout<<"0";
        }
    }
    cout<<"0";
    return 0;
}
