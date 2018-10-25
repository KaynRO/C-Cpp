#include <stdio.h>
#include <stdlib.h>
#define NMAX 1000

typedef struct pct
{
    int X ;
    int Y ;
} punct ;

typedef struct lista1
{
    void* info ;
    struct lista1* next ;
}*TLS ;

typedef struct lista2
{
    punct P ;
    struct lista2* next ;
    struct lista2* prev ;
}*TLD ;

TLS insereazaOrdonat ( TLS p, int X, int Y )
{
    TLS aux = p ;
    TLS temp = (TLS) malloc ( sizeof(struct lista1) ) ;
    punct* PP = (punct*) malloc ( sizeof(struct pct) ) ;

    PP->X = X ;
    PP->Y = Y ;
    temp->info = (void*) PP ;
    temp->next = NULL ;

    if ( !p )
        return temp ;

    if ( X < ((punct*) p->info)->X ) //inserare inceput
    {
        temp->next = p ;
        p = temp ;
        return p ;
    }

    for ( ; p->next != NULL ; p = p->next ) // inserare mijloc
    {
        if ( X < ((punct*) p->next->info)->X && X > ((punct*) p->info)->X )
        {
            temp->next = p->next ;
            p->next = temp ;
            return aux ;
        }
    }

    p->next = temp ;
    return aux ;

}

TLS Copie_Lista ( TLD p, int* nrLR )
{
    int nLR = 0 ;
    TLS LR ;
    TLD aux ;

    for ( ; p->next != NULL ; p = p->next )
    {
        if ( ( ( p->next->P.X > 0 ? 0 : 1 ) ^ ( p->next->next->P.X > 0 ? 0 : 1 ) == 0 &&
                ( p->next->P.Y > 0 ? 0 : 1 ) ^ ( p->next->next->P.Y > 0 ? 0 : 1 ) == 0 ) ||
                ( ( p->next->P.X > 0 ? 0 : 1 ) ^ ( p->prev->P.X > 0 ? 0 : 1 ) == 0 &&
                  ( p->next->P.Y > 0 ? 0 : 1 ) ^ ( p->prev->P.Y > 0 ? 0 : 1 ) == 0 ) )
        {
            LR = insereazaOrdonat( LR, p->next->P.X, p->next->P.Y ) ;
            nLR-- ;
            aux = p ;
            p->prev->next = p->next ;
            p->next->prev = p->prev ;
            p = p->prev ;
            free(aux) ;
        }

        else nLR++ ;
    }

    nrLR = &nLR ;
    return LR ;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
