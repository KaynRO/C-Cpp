#include <stdio.h>
#include <stdlib.h>
#define IMAX 1000

typedef struct TPoarta
{
    int identificator ;
    int nrCrtIntrari ;
    struct TPoarta** portiIntrare ;
    char* intrari ;
    char iesire ;
    char tipPoarta ;
} TPoarta;

typedef struct TCircuit
{
    int nrMaxPorti, nrCrtPorti, nrMaxIntrari ;
    TPoarta* porti ;
} TCircuit;

TCircuit* aloca ( int nrMaxPorti, int nrMaxIntrari )
{
    int i = 0, j = 0 ;
    TCircuit* p = (TCircuit*) malloc ( 1 * sizeof(TCircuit) ) ;

    p->nrMaxIntrari = nrMaxIntrari ;
    p->nrMaxPorti = nrMaxPorti ;
    p->nrCrtPorti = 0 ;

    p->porti = (TPoarta*) malloc ( nrMaxPorti * sizeof(TPoarta) ) ;

    for ( i = 0 ; i < nrMaxPorti ; i++ )
    {
        p->porti[i].intrari = (char*) malloc ( nrMaxIntrari * sizeof(char) ) ;
        p->porti[i].portiIntrare = (TPoarta**) malloc ( nrMaxIntrari * sizeof(TPoarta*) ) ;
        for ( j = 0 ; j < nrMaxIntrari ; j++ )
            p->porti[i].portiIntrare[j]->intrari = (char*) malloc ( nrMaxIntrari * sizeof(char) ) ;
    }

    return p ;
}

TPoarta* adaugaPoarta( TCircuit c )
{
    c.nrCrtPorti++ ;
    c.porti[c.nrCrtPorti].identificator = c.nrCrtPorti ;

    TPoarta* p = &(c.porti[c.nrCrtPorti]) ;
    return p ;
}

TPoarta* adaugaIntrare( TPoarta* p, TPoarta* in, char valintrare )
{
    if ( p->nrCrtIntrari == IMAX )
        return NULL ;

    p->nrCrtIntrari++ ;
    p->portiIntrare[p->nrCrtIntrari] = in ;
    p->intrari[p->nrCrtIntrari] = valintrare ;

    return p ;
}

int verifica( TCircuit c )
{
    int i ;
    for ( i = 0 ; i < c.nrCrtPorti ; i++ )
        if ( (int) c.porti[i].iesire == -1 )
            return 0 ;
    return 1 ;
}

int calculeaza ( TPoarta* p )
{
    int i , valoare ;

    if ( p->nrCrtIntrari == 0 )
        p->iesire = p->tipPoarta ;

    for ( i = 0 ; i < p->nrCrtIntrari ; i++ )
    {
        if ( (int) p->portiIntrare[i]->iesire == -1 )
            calculeaza(p->portiIntrare[i]) ;
    }

    for ( i = 0 ; i < p->nrCrtIntrari ; i++ )
    {
        if ( p->tipPoarta == 0 )
            valoare &= (int) p->portiIntrare[i]->iesire ;
        else valoare |= (int) p->portiIntrare[i]->iesire ;
    }

    return (int) p->iesire ;
}

int main()
{
    return 0 ;
}
