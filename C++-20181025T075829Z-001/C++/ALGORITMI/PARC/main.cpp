#include<cstdio>
#include<algorithm>
#include<cmath>
#define MOD 31313
using namespace std;
int XP,YP,xg,yg,xp,yp,xc,yc,XL,XR,YD,YU,m,n,i,j,M,N,L,R,U,D,X[20010],Y[20010];
double SOL;
void read(),solve();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("parc1.in","r",stdin);
    freopen("parc1.out","w",stdout);
    scanf("%d%d",&XP,&YP);
    XP++;
    YP++;
    scanf("%d%d",&xg,&yg);
    scanf("%d%d",&xp,&yp);
    int aux;
    scanf("%d",&m);
    m*=2;
    X[++R]=0;
    for(; m; m--)
    {
        scanf("%d",&aux);
        X[++R]=aux;
    }
    X[++R]=XP;
    L=1;
    scanf("%d",&m);
    m*=2;
    Y[++U]=0;
    for(; m; m--)
    {
        scanf("%d",&aux);
        Y[++U]=aux;
    }
    Y[++U]=YP;
    D=1;
}
void solve()
{
    if(xp==xg)
    {
        YP=yg>yp?yg-yp:yp-yg;
        printf("%d\n1\n",YP);
        return;
    }
    if(yp==yg)
    {
        XP=xg>xp?xg-xp:xp-xg;
        printf("%d\n1\n",XP);
        return;
    }

    if(xg>xp)
    {
        xg=XP-xg;
        xp=XP-xp;
        for(i=L; i<=R; i++)X[i]=XP-X[i];
    }
    if(yg>yp)
    {
        yg=YP-yg;
        yp=YP-yp;
        for(i=D; i<=U; i++)Y[i]=YP-Y[i];
    }

    sort(X+L,X+R+1);
    for(;; L+=2)if(X[L]<=xg&&xg<=X[L+1])break;
    for(;; R-=2)if(X[R-1]<=xp&&xp<=X[R])break;
    X[L]=xg;
    X[R]=xp;

    sort(Y+D,Y+U+1);
    for(;; D+=2)if(Y[D]<=yg&&yg<=Y[D+1])break;
    for(;; U-=2)if(Y[U-1]<=yp&&yp<=Y[U])break;
    Y[D]=yg;
    Y[U]=yp;
    int CX=0,CY=0;
    double cx,cy;
    for(i=L; i<R; i+=2)CX+=X[i+1]-X[i];
    for(i=D; i<U; i+=2)CY+=Y[i+1]-Y[i];
    SOL+=(double)(X[R]-X[L]-CX);
    SOL+=(double)(Y[U]-Y[D]-CY);
    cx=(double)CX;
    cy=(double)CY;
    SOL+=sqrt(cx*cx+cy*cy);
    printf("%lf\n",SOL);
    for(n=0,i=L+1; i<=R; i+=2,n++)X[n+1]=X[n]+X[i]-X[i-1];
    for(m=0,i=D+1; i<=U; i+=2,m++)Y[m+1]=Y[m]+Y[i]-Y[i-1];
    for(D=X[n],U=Y[m]; U;)
    {
        R=D%U;
        D=U;
        U=R;
    }
    xg=X[n]/D;
    yg=Y[m]/D;
    for(i=1,j=1,U=1; i<n&&j<m;)
    {
        if(X[i]%xg)
        {
            i++;
            continue;
        }
        if(Y[j]%yg)
        {
            j++;
            continue;
        }
        if(X[i]/xg<Y[j]/yg)
        {
            i++;
            continue;
        }
        if(X[i]/xg>Y[j]/yg)
        {
            j++;
            continue;
        }
        i++;
        j++;
        U*=2;

    }
    printf("%d\n",U);
}
