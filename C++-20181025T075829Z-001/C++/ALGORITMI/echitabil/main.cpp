#include<cstdio>
#include<cstdlib>
#define MAX 25001
using namespace std ;
unsigned s[MAX], g[1001], viz[1001], n, nr, S1, S2, gtot;
FILE *f;

void repartitie(int);

int main()
{
   int i ;
   gtot=0;
   f=fopen("echitabil.in", "r");
   fscanf(f, "%d", &n);
   for (i=1; i<=n; i++)
       {
	 fscanf(f, "%d", &g[i]);
	 gtot+=g[i];
       }
   fclose(f);
   for (i=1; i<=gtot/2; i++) s[i]=1001;
      // s[i]=j; ultima valoare adaug. pt a obt. greut. s[i] este g[j]
   for (i=1; i<=n; i++)
       for (int j=0; j<=gtot/2-g[i]; j++)
	   if (s[j]<i && s[j+g[i]] == 1001)
	       s[j+g[i]]=i;

   f=fopen("echitabil.out", "w");

   for (int j=gtot/2; j>=0; j--)
       if (s[j]!=1001)
	 {
	 fprintf(f, "%d %d\n", j, gtot-j);
	 repartitie(j);
	 fprintf(f, "\n");
	 break;
	 }
    fprintf(f,"%d\n",n-nr);
   for (i=1; i<=n; i++)
       if (!viz[i])  fprintf(f, "%d ", g[i]);
   fclose(f);
   return 0;
}


void repartitie(int i)
{
  if (s[i]>0)
     {
       nr++;
       repartitie(i-g[s[i]]);
       fprintf(f, "%d ", g[s[i]]);
       viz[s[i]]=1;
     }
    else
    fprintf(f,"%d\n",nr);
}
