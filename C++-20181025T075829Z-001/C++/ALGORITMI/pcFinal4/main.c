#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100
#define NFUNCT 3
#define TVA 18

double taxaMica ( unsigned int nrSurseVenit, double surseVenit[NMAX] )
{
    return 0 ;
}

double taxaMedie ( unsigned int nrSurseVenit, double surseVenit[NMAX] )
{
    return 0 ;
}

double taxaMare( unsigned int nrSurseVenit, double surseVenit[NMAX] )
{
    return 0 ;
}

typedef struct TPersoana
{
    unsigned int varsta, nrSurseVenit ;
    char* nume ;
    double surseVenit[NMAX] ;
    double (*calculeazaTaxa)(unsigned int nrSurseVenit, double surseVenit[NMAX]) ;
} TPersoana;

typedef struct TPopulatie
{
    unsigned int nrLocuitori ;
    double taxaMediePersoana ;
    TPersoana** persoane ;
} TPopulatie;

TPopulatie *alocaPopulatie( unsigned int nrLoc )
{
    int i ;
    TPopulatie* populatie = malloc ( sizeof(TPopulatie) ) ;

    populatie->nrLocuitori = nrLoc ;
    populatie->persoane = (TPersoana**) malloc ( nrLoc * sizeof(TPersoana*) ) ;

    for ( i = 0 ; i < nrLoc ; i++ )
    {
        populatie->persoane[i]->nume = (char*) malloc ( NMAX * sizeof(char) ) ;
        populatie->persoane[i]->calculeazaTaxa = malloc ( sizeof(taxaMica) ) ;
    }

    return populatie ;
}

TPopulatie **alocaPopulatii( unsigned int nrPopulatii, unsigned int *nrPersoane )
{
    int i ;
    TPopulatie** populatii = (TPopulatie**) malloc ( nrPopulatii * sizeof(TPopulatie*) ) ;
    TPopulatie* populatie = malloc ( sizeof(TPopulatie*) ) ;


    for ( i = 0 ; i < nrPopulatii ; i++ )
    {
        populatie = alocaPopulatie(nrPersoane[i]) ;
        populatii[i] = populatie ;
    }

    return populatii ;

}

TPopulatie** citesteFisier ( FILE *f )
{
    int nrPopulatii, nrLoc, varsta, nrSurseVenit, i, j, k ;
    double sursaVenit ;
    char* nume = malloc ( NMAX * sizeof(char) ) ;
    TPopulatie** populatii ;

    fscanf( f, "%u", &nrPopulatii ) ;
    populatii = (TPopulatie**) malloc ( nrPopulatii * sizeof(TPopulatie*) ) ;

    for ( i = 0 ; i < nrPopulatii ; i++ )
    {
        fscanf ( f, "%u", &nrLoc ) ;
        populatii[i]->nrLocuitori = nrLoc ;
        for ( j = 0 ;  j < nrLoc ; j++ )
        {
            fscanf( f, "%u %u", &varsta, &nrSurseVenit ) ;
            fscanf( f, "%s", nume ) ;

            populatii[i]->persoane[j]->varsta = varsta ;
            populatii[i]->persoane[j]->nrSurseVenit = nrSurseVenit ;
            populatii[i]->persoane[j]->nume = nume ;

            for ( k = 0 ; k < nrSurseVenit ; k++ )
            {
                fscanf( f, "%lf", &sursaVenit ) ;
                populatii[i]->persoane[j]->surseVenit[k] = sursaVenit ;
            }
        }
    }

    return populatii ;
}

double totalVenit ( TPersoana* persoana )
{
    int i ;
    double suma = 0 ;

    for ( i = 0 ; i < persoana->nrSurseVenit ; i++ )
        suma += persoana->surseVenit[i] ;

    return suma ;

}

int suma3500 ( TPersoana* persoana )
{
    int i ;

    for ( i = 0 ; i <= persoana->nrSurseVenit ; i++ )
        if ( persoana->surseVenit[i] > 3500 ) return 1 ;

    return 0 ;

}

void modificaTaxa ( TPopulatie* populatie, unsigned int nrPersoane )
{
    int i ;

    for ( i = 0 ; i < nrPersoane ; i++ )
    {
        if ( populatie->persoane[i]->nrSurseVenit <= 2 && totalVenit(populatie->persoane[i]) <= 1600 )
            populatie->persoane[i]-> calculeazaTaxa = taxaMica ;
        else if ( populatie->persoane[i]->nrSurseVenit <= 5 && suma3500(populatie->persoane[i]) )
            populatie->persoane[i]-> calculeazaTaxa = taxaMedie ;
        else
            populatie->persoane[i]-> calculeazaTaxa = taxaMare ;
    }

}

TPopulatie** calculeazaTaxaMedie ( TPopulatie** populatii, unsigned int nrPopulatii )
{
    int i, j ;
    double suma = 0 ;

    for ( i = 0 ; i < nrPopulatii ; i++ )
    {
        for ( j = 0 ; j < populatii[i]->nrLocuitori ; j++ )
            suma += totalVenit( populatii[i]->persoane[j] ) ;

        populatii[i]->taxaMediePersoana = (double) suma / (double) populatii[i]->nrLocuitori  ;
    }

    return populatii ;

}

int comparaTaxe ( const void *a, const void *b )
{
    TPopulatie* x = (TPopulatie*) a ;
    TPopulatie* y = (TPopulatie*) b ;

    return x->taxaMediePersoana < y->taxaMediePersoana ;
}

void sortarePopulatii ( TPopulatie **populatii, unsigned int *nrPopulatii )
{
    qsort( populatii, *nrPopulatii, sizeof(TPopulatie*), comparaTaxe ) ;
}

void dezalocaPopulatii ( TPopulatie** populatii, unsigned int *nrPopulatii )
{
    int i, j ;

    for ( i = 0 ; i < *nrPopulatii ; i++ )
    {
        for ( j = 0 ; j < populatii[i]->nrLocuitori ; j++ )
        {
            free ( populatii[i]->persoane[j]->nume) ;
            free ( populatii[i]->persoane[j]->calculeazaTaxa) ;
            free ( populatii[i]->persoane[j] ) ;
        }
        free ( populatii[i]->persoane ) ;
        free ( populatii[i] ) ;
    }
    free(populatii) ;
}

int main()
{
    return 0 ;
}
