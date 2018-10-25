#include <fstream>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

using namespace std;

void asteapta(int ms)
{
    int st = clock();
    while (clock() - st < ms);
}

void GotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

int GI[100][100], nextG[100][100], i, j, k, nrv, nrg,N,n,m,prag,t,nrinc;
int dl[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int M[100][100],Af[100][100],p,Use[27];
int c,b;
char carac;

int main()
{
    setcolor(2);
    cout<<"REBUS MATEMATIC"<<"\n"<<"\n";
    setcolor(3);
    cout<<"1.GEOMETRIE(dificultate mica)"<<"\n"<<'\n';
    setcolor(5);
    cout<<"2.INEGALITATI(dificultate mare destinat in special olimpicilor)"<<'\n'<<'\n';
    setcolor(4);
    cout<<"3.ALGEBRA(dificultate medie)"<<'\n'<<'\n';
    setcolor(6);
    cout<<"4.SIRURI(dificultate medie)"<<'\n'<<'\n';
    setcolor(7);
     cout<<"5.IESIRE"<<'\n'<<'\n';
    cin >> N ;
    if(N==1)
    {

        system ("CLS");

        ifstream g("geometrie.in");
        system ("CLS");
         g>>n>>m>>prag;

         for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             g>>c;
             M[i][j]=c;
         }
            }
          for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             Af[i][j]=0;
             setcolor(4);
             if(j==8)
                setcolor(6);
             if(M[i][j]!=0)
             cout<<"*";
             else
                cout<<"-";
         }
         cout<<'\n';
            }

              for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.PLAN,DREAPTA,..."<<'\n';
         cout<<"2.PATRULATER CU 2 BAZE PARALELE"<<"\n";
         cout<<"3.POLIGON CE POATE FI INSCRIS INTR-UN CERC"<<'\n';
         cout<<"4.TRIUNGHI FARA PROPRIETATI SPECIALE"<<'\n';
         cout<<"5.OPUSUL PATRULATERULUI CONVEX ESTE PATRULATERUL ..."<<'\n';
         cout<<"6.IN CLASA A IX A LA GEOMETRIE APARE NOTIUNEA DE ..."<<'\n';

         while(prag>0)
         {
             cin>>b;
             nrinc++;
             system ("CLS");
             for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             if(M[i][j]==b&&Use[b]==0)
             {
                 Af[i][j]=1;
                 prag--;
             }
         }
            }

             for(i=1;i<=n;i++)
         {
             for(j=1;j<=m;j++)
             {
                 if(Af[i][j]==0)
                 {
                     setcolor(i);
                     if(j==8)
                     {
                         setcolor(6);
                     }
                     if(M[i][j]!=0)
                     cout<<"*";
                     else
                        cout<<"-";
                 }
                 if(Af[i][j]==1)
                 {
                     setcolor(4);
                     if(j==8)
                     {
                         setcolor(6);
                     }
                     carac='A'+M[i][j]-1;
                     if('Z'<carac||carac<'A')
                       {
                        cout<<"NU AI RESPECTAT CERINTA SI JOCUL SE VA INCHIDE"<<'\n';
                        prag=0;
                       }
                     else
                     cout<<carac;
                 }
             }
             cout<<'\n';
         }
         for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.PLAN,DREAPTA,..."<<'\n';
         cout<<"2.PATRULATER CU 2 BAZE PARALELE"<<"\n";
         cout<<"3.POLIGON CE POATE FI INSCRIS INTR-UN CERC"<<'\n';
         cout<<"4.TRIUNGHI FARA PROPRIETATI SPECIALE"<<'\n';
         cout<<"5.OPUSUL PATRULATERULUI CONVEX ESTE PATRULATERUL ..."<<'\n';
         cout<<"6.IN CLASA A IX A LA GEOMETRIE APARE NOTIUNEA DE ..."<<'\n';

         Use[b]=1;
         }
      setcolor(3);
       cout<<"AI AVUT "<<nrinc<<' '<<"INCERCARI"<<'\n';
       if(nrinc<=20)
       {
           cout<<"ESTI BUN LA ACEST CAPITOL";

       }
       if(nrinc>20)
       {
           cout<<"AR MAI TREBUI SA INVETI PUTIN";
       }
    }
    if(N==2)
    {
        system ("CLS");
ifstream gi("inegalitati.in");
        system ("CLS");
         gi>>n>>m>>prag;

         for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             gi>>c;
             M[i][j]=c;
         }
            }
          for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             Af[i][j]=0;
             setcolor(4);
             if(j==5)
                setcolor(6);
             if(M[i][j]!=0)
             cout<<"*";
             else
                cout<<"-";
         }
         cout<<'\n';
            }

              for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.AUTOR AL UNEI INEGALITATI ASEMANATOARE CU CBS"<<'\n';
         cout<<"2.INEGALITATE CE SE MODIFICA IN FUNCTIE DE MONOTONIE"<<"\n";
         cout<<"3.RATIONAMENT DE DEMONSTRATIE A ANUMITOR INEGALITATI"<<'\n';
         cout<<"4.UNA DINTRE CELE 4 MEDII FOLOSITE IN INEGALITATI"<<'\n';
         cout<<"5.PRENUMELE UNUI MATEMATICIAN ROMAN CE TRATEAZA UN CAZ PARTICULAR AL CBS-ului .."<<'\n';
         cout<<"6.AUTOR AL UNEI INEGALITATI DIN GEOMETRIE..."<<'\n';
         cout<<"7.AUTOR ITALIAN AL UNEI INEGALITATI FOLOSITE IN SPECIAL IN CLASA A VII A ..."<<'\n';
         cout<<"8.AUTOR AL UNEI INEGALITATI FOLOSITE PENTRU CONCURSURI IN CLASELE (VII-IX) ..."<<'\n';
         while(prag>0)
         {
             cin>>b;
             nrinc++;
             system ("CLS");
             for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             if(M[i][j]==b&&Use[b]==0)
             {
                 Af[i][j]=1;
                 prag--;
             }
         }
            }

             for(i=1;i<=n;i++)
         {
             for(j=1;j<=m;j++)
             {
                 if(Af[i][j]==0)
                 {
                     setcolor(i);
                     if(j==5)
                     {
                         setcolor(6);
                     }
                     if(M[i][j]!=0)
                     cout<<"*";
                     else
                        cout<<"-";
                 }
                 if(Af[i][j]==1)
                 {
                     setcolor(4);
                     if(j==5)
                     {
                         setcolor(6);
                     }
                     carac='A'+M[i][j]-1;
                     if('Z'<carac||carac<'A')
                       {
                        cout<<"NU AI RESPECTAT CERINTA SI JOCUL SE VA INCHIDE"<<'\n';
                        prag=0;
                       }
                     else
                     cout<<carac;
                 }
             }
             cout<<'\n';
         }
         for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
          cout<<"1.AUTOR AL UNEI INEGALITATI ASEMANATOARE CU CBS"<<'\n';
         cout<<"2.INEGALITATE CE SE MODIFICA IN FUNCTIE DE MONOTONIE"<<"\n";
         cout<<"3.RATIONAMENT DE DEMONSTRATIE A ANUMITOR INEGALITATI"<<'\n';
         cout<<"4.UNA DINTRE CELE 4 MEDII FOLOSITE IN INEGALITATI"<<'\n';
         cout<<"5.PRENUMELE UNUI MATEMATICIAN ROMAN CE TRATEAZA UN CAZ PARTICULAR AL CBS-ului .."<<'\n';
         cout<<"6.AUTOR AL UNEI INEGALITATI DIN GEOMETRIE..."<<'\n';
         cout<<"7.AUTOR ITALIAN AL UNEI INEGALITATI FOLOSITE IN SPECIAL IN CLASA A VII A ..."<<'\n';
         cout<<"8.AUTOR AL UNEI INEGALITATI FOLOSITE PENTRU CONCURSURI IN CLASELE (VII-IX) ..."<<'\n';

         Use[b]=1;
         }
      setcolor(3);
       cout<<"AI AVUT "<<nrinc<<' '<<"INCERCARI"<<'\n';
       if(nrinc<=20)
       {
           cout<<"ESTI BUN LA ACEST CAPITOL";

       }
       if(nrinc>20)
       {
           cout<<"AR MAI TREBUI SA INVETI PUTIN";
       }

    }
    if(N==3)
    {
        system ("CLS");
        ifstream cit("algebra.in");
        system ("CLS");
         cit>>n>>m>>prag;

         for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             cit>>c;
             M[i][j]=c;
         }
            }
          for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             Af[i][j]=0;
             setcolor(4);
             if(j==9)
                setcolor(6);
             if(M[i][j]!=0)
             cout<<"*";
             else
                cout<<"-";
         }
         cout<<'\n';
            }

              for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.LA ORICE MATRICE SE POATE CALCULA"<<'\n';
         cout<<"2.NOTIUNE INVATATA IN CLASELE V-VI"<<"\n";
         cout<<"3.HERMANN SCHWARZ LOCUIA IN ..."<<'\n';
         cout<<"4.ORICE MATRICE CU DETERMINANT NENUL ARE ..."<<'\n';
         cout<<"5.PRESCURTARE LA O INEGALITATE CELEBRA SI UTILA"<<'\n';
         cout<<"6.LA ALGEBRA DE CLASA A XI A LUCRAM IN GENERAL CU ..."<<'\n';
         cout<<"7.SUMA DE PE DIAGONALA PRINCIPALA A UNEI MATRICI SE NUMESTE ..."<<'\n';
         while(prag>0)
         {
             cin>>b;
             nrinc++;
             system ("CLS");
             for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             if(M[i][j]==b&&Use[b]==0)
             {
                 Af[i][j]=1;
                 prag--;
             }
         }
            }

             for(i=1;i<=n;i++)
         {
             for(j=1;j<=m;j++)
             {
                 if(Af[i][j]==0)
                 {
                     setcolor(i);
                     if(j==9)
                     {
                         setcolor(6);
                     }
                     if(M[i][j]!=0)
                     cout<<"*";
                     else
                        cout<<"-";
                 }
                 if(Af[i][j]==1)
                 {
                     setcolor(4);
                     if(j==9)
                     {
                         setcolor(6);
                     }
                     carac='A'+M[i][j]-1;
                     if('Z'<carac||carac<'A')
                       {
                        cout<<"NU AI RESPECTAT CERINTA SI JOCUL SE VA INCHIDE"<<'\n';
                        prag=0;
                       }
                     else
                     cout<<carac;
                 }
             }
             cout<<'\n';
         }
         for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.LA ORICE MATRICE SE POATE CALCULA"<<'\n';
         cout<<"2.NOTIUNE INVATATA IN CLASELE V-VI"<<"\n";
         cout<<"3.HERMANN SCHWARZ LOCUIA IN ..."<<'\n';
         cout<<"4.ORICE MATRICE CU DETERMINANT NENUL ARE ..."<<'\n';
         cout<<"5.PRESCURTARE LA O INEGALITATE CELEBRA SI UTILA"<<'\n';
         cout<<"6.LA ALGEBRA DE CLASA A XI A LUCRAM IN GENERAL CU ..."<<'\n';
         cout<<"7.SUMA DE PE DIAGONALA PRINCIPALA A UNEI MATRICI SE NUMESTE ..."<<'\n';
         Use[b]=1;
         }
      setcolor(3);
       cout<<"AI AVUT "<<nrinc<<' '<<"INCERCARI"<<'\n';
       if(nrinc<=20)
       {
           cout<<"ESTI BUN LA ACEST CAPITOL";

       }
       if(nrinc>20)
       {
           cout<<"AR MAI TREBUI SA INVETI PUTIN";
       }
    }
    if(N==4)
    {
        ifstream fin("sir.in");
        system ("CLS");
         fin>>n>>m>>prag;

         for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             fin>>c;
             M[i][j]=c;
         }
            }
          for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             Af[i][j]=0;
             setcolor(4);
             if(j==8)
                setcolor(6);
             if(M[i][j]!=0)
             cout<<"*";
             else
                cout<<"-";
         }
         cout<<'\n';
            }

              for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
         cout<<"1.UN SIR SPECIAL"<<'\n';
         cout<<"2.UNA DINTRE CELE 3 PROPRIETATI ALE SIRURILOR"<<"\n";
         cout<<"3.MATEMATICIAN"<<'\n';
         while(prag>0)
         {
             cin>>b;
             nrinc++;
             system ("CLS");
             for(i=1;i<=n;i++)
            {for(j=1;j<=m;j++)
         {
             if(M[i][j]==b&&Use[b]==0)
             {
                 Af[i][j]=1;
                 prag--;
             }
         }
            }

             for(i=1;i<=n;i++)
         {
             for(j=1;j<=m;j++)
             {
                 if(Af[i][j]==0)
                 {
                     setcolor(i+10);
                     if(j==8)
                     {
                         setcolor(6);
                     }
                     if(M[i][j]!=0)
                     cout<<"*";
                     else
                        cout<<"-";
                 }
                 if(Af[i][j]==1)
                 {
                     setcolor(4);
                     if(j==8)
                     {
                         setcolor(6);
                     }
                     carac='A'+M[i][j]-1;
                     if('Z'<carac||carac<'A')
                       {
                        cout<<"NU AI RESPECTAT CERINTA SI JOCUL SE VA INCHIDE"<<'\n';
                        prag=0;
                       }
                     else
                     cout<<carac;
                 }
             }
             cout<<'\n';
         }
         for(p=1;p<=26;p=p+2)
         {
             carac='A'+p-1;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p<<")"<<' ';
              carac='A'+p;
             t=carac-'A'+65;
             cout<<carac<<' '<<"0"<<t<<"("<<p+1<<")"<<'\n';

         }
          cout<<"1.UN SIR SPECIAL"<<'\n';
         cout<<"2.UNA DINTRE CELE 3 PROPRIETATI ALE SIRURILOR"<<"\n";
         cout<<"3.MATEMATICIAN"<<'\n';
         Use[b]=1;
         }
      setcolor(3);
       cout<<"AI AVUT "<<nrinc<<' '<<"INCERCARI"<<'\n';
       if(nrinc<=16)
       {
           cout<<"ESTI BUN LA ACEST CAPITOL";

       }
       if(nrinc>16)
       {
           cout<<"AR MAI TREBUI SA INVETI PUTIN";
       }
    }
    if(N==5)
    {
        system ("CLS");
    }

    return 0;
}
