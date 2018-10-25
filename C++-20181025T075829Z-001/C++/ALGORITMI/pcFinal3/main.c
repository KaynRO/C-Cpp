#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 100

typedef struct
{
    char* nume ;
    int* atribute ;
    int pozX ;
    int pozY ;
} TJucator ;

typedef struct
{
    int lungime ;
    int latime ;
    int nrMaxJucatori ;
    int nrCrtJucatori ;
    char* numeHarta ;
    TJucator* jucatori ;
    int nrAtribute ;
} THarta;

THarta* aloca( int nrMaxJucatori, int nrAtribute )
{
    THarta* harta = (THarta*) malloc ( 1 * sizeof(THarta) ) ;
    if ( !harta ) return NULL ;

    harta->nrAtribute = nrAtribute ;
    harta->nrMaxJucatori = nrMaxJucatori ;
    harta->nrCrtJucatori = 0 ;

    harta->numeHarta = malloc ( NMAX * sizeof(char) ) ;
    if ( !harta->numeHarta )
    {
        free(harta) ;
        return NULL ;
    }

    harta->jucatori = (TJucator*) malloc ( nrMaxJucatori * sizeof(TJucator) ) ;
    if ( !harta->jucatori )
    {
        free(harta->numeHarta) ;
        free(harta) ;
        return NULL ;
    }

    int i ;
    for ( i = 0 ; i < nrMaxJucatori ; i++ )
    {
        harta->jucatori[i].nume = (char*) malloc ( NMAX * sizeof(char) ) ;
        harta->jucatori[i].atribute = (int*) malloc ( NMAX * sizeof(char) ) ;

        if ( !harta->jucatori[i].nume )
        {
            free(harta->jucatori) ;
            free(harta->numeHarta) ;
            free(harta) ;
            return NULL ;
        }

        if ( !harta->jucatori[i].atribute )
        {
            free(harta->jucatori) ;
            free(harta->numeHarta) ;
            free(harta) ;
            return NULL ;
        }

    }

    return harta ;
}

int cmp ( const void *a, const void *b )
{
    TJucator *j1 = (TJucator*) a ;
    TJucator *j2 = (TJucator*) b ;
    int dist1 = sqrt ( j1->pozX * j1->pozX + j1->pozY * j1->pozY ) ;
    int dist2 = sqrt ( j2->pozX * j2->pozX + j2->pozY * j2->pozY ) ;

    return dist1 < dist2 ;

}

void sort ( THarta* harta )
{
    qsort(harta->jucatori, harta->nrCrtJucatori, sizeof(TJucator), cmp) ;
}

TJucator* cauta( int p, THarta* harta )
{
    int i = 0 ;
    sort(harta) ;

    for ( i = 0 ; i < harta->nrCrtJucatori ; i++ )
    {
        double raport = harta->jucatori[i].atribute[0] / harta->jucatori[i].atribute[0] ;
        if ( raport < p )
            return &(harta->jucatori[i]) ;
    }

    return NULL ;
}

void salveaza ( FILE *f, THarta* harta )
{
    int i = 0 ;

    fwrite(&harta->lungime,sizeof(int),1,f) ;
    fwrite(&harta->latime,sizeof(int),1,f) ;
    fwrite(&harta->nrCrtJucatori,sizeof(int),1,f) ;
    fwrite(&harta->nrMaxJucatori,sizeof(int),1,f) ;
    fwrite(&harta->nrAtribute,sizeof(int),1,f) ;
    fwrite(harta->numeHarta,sizeof(char),NMAX,f) ;

    for ( i = 0 ; i < harta->nrCrtJucatori ; i++ )
    {
        fwrite(harta->jucatori[i].atribute,sizeof(int),NMAX,f) ;
        fwrite(harta->jucatori[i].nume,sizeof(char),NMAX,f) ;
        fwrite(&harta->jucatori[i].pozX,sizeof(int),1,f) ;
        fwrite(&harta->jucatori[i].pozY,sizeof(int),1,f) ;
    }
}

void elibereaza ( THarta **harta )
{
    int i = 0 ;
    free ((*harta)->numeHarta) ;

    for ( i = 0 ; i <= (*harta)->nrCrtJucatori ; i++ )
    {
        free((*harta)->jucatori[i].nume) ;
        free((*harta)->jucatori[i].atribute) ;
    }

    free((*harta)->jucatori) ;
    free(*harta) ;
    *harta = NULL ;
}

int main()
{

    return 0 ;
}
