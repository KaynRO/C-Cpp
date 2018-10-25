#include <stdio.h>
#include <stdlib.h>

typedef struct Persoana
{
    char* name ;
    char* email ;
    int anNastere ;
    struct Persoana** prieteni  ;
    int nrPrieteni ;
    int nrMaxPrieteni ;
} Persoana ;

typedef struct
{
    Persoana* colectiePersoane ;
    int nrMaxPersoane ;
} ReteaSociala ;

Persoana* aloca( int nrMaxPrieteni )
{
    Persoana* persoana ;
    persoana = (Persoana*)malloc ( 1 * sizeof(Persoana) ) ;
    persoana->nrMaxPrieteni = nrMaxPrieteni ;
    return persoana ;
}

int adaugaPersoana ( Persoana* p1, Persoana* p2 )
{
    if ( p1->nrPrieteni == p1->nrMaxPrieteni || p2->nrMaxPrieteni == p2->nrPrieteni )
        return 0 ;

    p1->nrPrieteni++ ;
    p2->nrPrieteni++ ;

    p1->prieteni = realloc( p1->prieteni, p1->nrPrieteni * sizeof(Persoana) ) ;
    p1->prieteni[p1->nrPrieteni - 1] = p2 ;

    p2->prieteni = realloc ( p2->prieteni, p2->nrPrieteni * sizeof(Persoana) ) ;
    p2->prieteni[p2->nrPrieteni - 1] = p1 ;

    return 1 ;
}

int EliminaPersoana ( Persoana* p1, Persoana* p2 )
{
    int ok = 0, i, index1, index2 ;
    for ( i = 0  ; i <= p1->nrPrieteni - 1 ; i++ )
        if ( p1->prieteni[i] == p2 ) ok = 1 ;

    if ( ok == 0 ) return 0 ;

    for ( i = 0 ; i <= p1->nrPrieteni - 1 ; i++ )
        if ( p1->prieteni[i] == p2 ) index1 = i ;

    for ( i = 0 ; i <= p2->nrPrieteni - 1 ; i++ )
        if ( p2->prieteni[i] == p1 ) index2 = i ;

    for ( i = index1 ; i <= p1->nrPrieteni - 2 ; i++ )
        p1->prieteni[i] = p1->prieteni[i + 1] ;

    for ( i = index2 ; i <= p2->nrPrieteni - 2 ; i++ )
        p2->prieteni[i] = p2->prieteni[i + 1] ;

    p1->nrPrieteni-- ;
    p2->nrPrieteni-- ;
    p1->prieteni = realloc ( p1->prieteni, p1->nrPrieteni * sizeof(Persoana) ) ;
    p2->prieteni = realloc ( p2->prieteni, p2->nrPrieteni * sizeof(Persoana) ) ;

    return 1 ;

}

void Free ( ReteaSociala *rs )
{
    int i, j, nrPersoane = sizeof(*rs->colectiePersoane) / sizeof(Persoana) ;

    for ( i = 0 ; i <= nrPersoane ; i++ )
    {
        free(rs->colectiePersoane[i].email) ;
        free(rs->colectiePersoane[i].name) ;
        for ( j = 0 ; j <= rs->colectiePersoane[i].nrPrieteni - 1 ; j++ )
            free(rs->colectiePersoane[i].prieteni[j]) ;
    }
    free(rs) ;

}

void citeste ( FILE *f, ReteaSociala *b )
{
    int nrPersoane, i;

    fscanf( f, "%d", &nrPersoane ) ;
    b->colectiePersoane = (Persoana*) malloc ( 2 * sizeof(Persoana) ) ;

    for ( i = 1 ; i <= nrPersoane ; i++ )
    {
        char name[40], email[40] ;
        Persoana p ;

        p.name = name ;
        p.email = email ;
        fscanf( f, "%s", p.name ) ;
        fscanf( f, "%s", p.email ) ;

        int Rsize = sizeof(*b->colectiePersoane) / sizeof(Persoana) ;

        printf("%d" , Rsize) ;

        b->colectiePersoane = (Persoana*) realloc ( b->colectiePersoane, ( Rsize + 1 ) * sizeof(Persoana) ) ;
        b->colectiePersoane[Rsize - 1] = p ;

    }
}
int main()
{
    FILE *f ;
    f = fopen("RS.in", "rw+" ) ;

    ReteaSociala mine ;

    ReteaSociala *RS = &mine ;
    citeste ( f, RS ) ;

    return 0 ;
}
