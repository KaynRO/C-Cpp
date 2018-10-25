#include <cstdio>
#define M 23

using namespace std ;

int T[M][M],I,x[M],v[M],px[M],py[M],mx[M],my[M],sens[M],sf;

void scrie()
{
    FILE *f;
    int i;
    f=fopen("immortal.out","wt");
    if(I==1)
    {
        fprintf(f,"0\n");
        fclose(f);
        return;
    }
    for(i=1; i<I; i++)
    {
        fprintf(f,"%d %d ",mx[i],my[i]);
        switch(sens[i])
        {
        case 1:
            my[i]+=2;
            break;
        case 2:
            my[i]-=2;
            break;
        case 3:
            mx[i]+=2;
            break;
        case 4:
            mx[i]-=2;
            break;
        }
        fprintf(f,"%d %d\n",mx[i],my[i]);
    }
    fclose(f);
    return;
}
void back(int k)
{
    int i,X,Y,z;
    if(sf) return;
    if(k==I)
    {
        sf=1;
        scrie();
        return;
    }
    for(i=I; i>=1; i--) if(v[i]==0)
        {
            X=px[i];
            Y=py[i];
            if((z=T[X][Y-1])>0 && T[X][Y+1]==0)
            {
                v[i]=1;
                sens[k]=1;
                mx[k]=X;
                my[k]=Y-1;
                py[z]+=2;
                T[X][Y]=0;
                T[X][Y-1]=0;
                T[X][Y+1]=z;
                back(k+1);
                v[i]=0;
                py[z]-=2;
                T[X][Y]=i;
                T[X][Y+1]=0;
                T[X][Y-1]=z;
            }
            if((z=T[X][Y+1])>0 && T[X][Y-1]==0)
            {
                v[i]=1;
                sens[k]=2;
                mx[k]=X;
                my[k]=Y+1;
                py[z]-=2;
                T[X][Y]=0;
                T[X][Y+1]=0;
                T[X][Y-1]=z;
                back(k+1);
                v[i]=0;
                py[z]+=2;
                T[X][Y]=i;
                T[X][Y-1]=0;
                T[X][Y+1]=z;
            }
            if((z=T[X-1][Y])>0 && T[X+1][Y]==0)
            {
                v[i]=1;
                sens[k]=3;
                mx[k]=X-1;
                my[k]=Y;
                px[z]+=2;
                T[X][Y]=0;
                T[X-1][Y]=0;
                T[X+1][Y]=z;
                back(k+1);
                v[i]=0;
                px[z]-=2;
                T[X][Y]=i;
                T[X+1][Y]=0;
                T[X-1][Y]=z;
            }
            if((z=T[X+1][Y])>0 && T[X-1][Y]==0)
            {
                v[i]=1;
                sens[k]=4;
                mx[k]=X+1;
                my[k]=Y;
                px[z]-=2;
                T[X][Y]=0;
                T[X+1][Y]=0;
                T[X-1][Y]=z;
                back(k+1);
                v[i]=0;
                px[z]+=2;
                T[X][Y]=i;
                T[X-1][Y]=0;
                T[X+1][Y]=z;
            }
        }
}
int main()
{
    FILE *f;
    int i,j,k,n,m;
    f=fopen("immortal.in","r");
    fscanf(f,"%d %d %d",&n,&m,&I);
    for(i=0; i<=n+1; i++) T[i][0]=T[i][m+1]=-1;
    for(i=1; i<=m; i++) T[0][i]=T[n+1][i]=-1;
    for(i=1; i<=I; i++)
    {
        fscanf(f,"%d %d",&j,&k);
        T[j][k]=i;
        px[i]=j;
        py[i]=k;
    }
    fclose(f);
    back(1);
    return 0;
}
