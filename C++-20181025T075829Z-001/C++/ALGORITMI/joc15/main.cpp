#include <stdio.h>
#define M 5001
using namespace std ;
int main()
{
    int n,k,i,j,j1,s,max,a[2][M],b[2][M];
    FILE *f1,*f2;
    f1=fopen("joc15.in","r");
    fscanf(f1,"%d %d",&n,&k);
    for(i=0; i<2; i++)
        for(j=0; j<n; j++) fscanf(f1,"%d",&a[i][j]);
    fclose(f1);
    b[0][0]=a[0][0];
    b[1][0]=0;
    for(i=1; i<n; i++)
        for(j=0; j<2; j++)
        {
            max=-11111;
            s=a[j][i];
            for(j1=1; j1<k&&j1<=i; j1++)
            {
                s+=a[j][i-j1];
                if(s+b[1-j][i-j1]>max) max=s+b[1-j][i-j1];
            }
            b[j][i]=max;
        }
    f2=fopen("joc15.out","wt");
    if(b[0][n-1]+a[1][n-1]>b[1][n-1]) b[1][n-1]=b[0][n-1]+a[1][n-1];
    fprintf(f2,"%d\n",b[1][n-1]);
    fclose(f2);
    return 0;
}
