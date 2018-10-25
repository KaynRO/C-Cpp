#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 256

typedef struct hanoi
{
    char *culoare_hanoi ;
    void *A ;
    void *B ;
    void *C ;
} turn_hanoi ;

typedef struct stiva
{
    void* info ;
    struct stiva* next ;
} TStiva, *ASt;

void *InitS()
{
	ASt a = (ASt)malloc(sizeof(TStiva));
	a->info = NULL ;
  	a->next = NULL ;
  	return (void *)a;
}

/* pune element in varful stivei */
void *Push(void *a, void *ae)
{
    void* aux = InitS(ae) ;
  	((ASt)aux)->next = a ;
  	a = aux ;
  	return aux;
}

/* extrage elementul din varful stivei la adresa ae */
void *Pop(void *a, void *ae)
{
	void* aux = a ;
	ae = ((ASt)a)->info ;
	a = ((ASt)a)->next ;
	free(aux) ;
	return a ;

}

/* copiaza elementul din varful stivei la adresa ae */
void Top(void *a, void *ae)
{
  	ae = ((ASt)a)->info ;
}

/* test stiva vida */
int VidaS(void *a)
{
	return a == NULL ? 1 : 0 ;
}

/* numarul de elemente din stiva */
size_t NrES(void *a)
{
    void* aux = a ;
	size_t contor = 0 ;
	void* info ;

	while(!VidaS(a))
	{
        Pop(a , info) ;
        contor++ ;
	}
	a = aux ;
	return contor ;
}

/* transforma stiva in stiva vida */
void ResetS(void *a)
{
    void* info ;
	while (!VidaS(a))
        Pop(a , info) ;
    return ;
}

/* elibereaza intregul spatiu ocupat de stiva */
void DistrS(void **aa)
{
	ResetS(*aa) ;
	free(aa) ;
}

void opAdd( char *culoare_disc, char *dimensiune_disc, turn_hanoi *Hanoi )
{
    int i ;

    for ( i = 0 ;  i < NMAX ; i++ )
    {
        if ( !strcmp(Hanoi[i].culoare_hanoi, culoare_disc) )
        {
            Push( Hanoi[i].A, (void*)dimensiune_disc ) ;
            break ;
        }
        if ( !strcmp(Hanoi[i].culoare_hanoi, "nothing") )
        {
            strcpy( Hanoi[i].culoare_hanoi, culoare_disc ) ;
            Push( Hanoi[i].A, (void*)dimensiune_disc ) ;
            break ;
        }
    }
}

void opPlay( char *culoare, int numar_mutari )
{
    printf("Operatia play : %s %d\n", culoare, numar_mutari) ;
}

void Afiseaza(void* a)
{
    void* curent ;
    curent = a ;
    do
    {
        printf("%s ", (char*)(((ASt)curent)->info)) ;
        curent = ((ASt)curent)->next ;
    }
    while(curent != NULL) ;
    printf("\n") ;
}


void opShow( char *culoare, turn_hanoi *Hanoi )
{
    int i ;
    for ( i = 0 ; i < NMAX ; i++ )
    {
        if ( !strcmp(Hanoi[i].culoare_hanoi, culoare) )
        {
            printf("A_%s: ", culoare) ;
            Afiseaza(Hanoi[i].A) ;

            printf("B_%s: ", culoare) ;
            Afiseaza(Hanoi[i].B) ;

            printf("C_%s: ", culoare) ;
            Afiseaza(Hanoi[i].C) ;
        }
        else
            break ;
    }
}

void opShowMoves( char *culoare, int numar_mutari )
{
    printf("Operatia show_moves : %s %d\n", culoare, numar_mutari) ;
}

void citeste( char *filename, turn_hanoi *Hanoi )
{
    int i, N, numar_mutari ;
    char *op, *culoare_disc, *culoare, *dimensiune_disc ;

    op = (char*) malloc( NMAX * sizeof(char) ) ;
    culoare_disc = (char*) malloc( NMAX * sizeof(char) ) ;
    culoare = (char*) malloc( NMAX * sizeof(char) ) ;
    dimensiune_disc = (char*) malloc( NMAX * sizeof(char) ) ;

    FILE *file ;
    file = fopen (filename, "r" ) ;

    fscanf( file, "%d", &N ) ;

    for ( i = 1 ; i <= N ; i++ )
    {
        fscanf( file, "%s", op) ;
        if ( !strcmp( op, "add") )
        {
            fscanf( file, "%s %s", culoare_disc, dimensiune_disc ) ;
            //opAdd( culoare_disc, dimensiune_disc, Hanoi ) ;
        }
        if ( !strcmp( op, "play" ) )
        {
            fscanf( file, "%s %d", culoare, &numar_mutari ) ;
            opPlay( culoare, numar_mutari ) ;
        }
        if ( !strcmp( op, "show") )
        {
            fscanf( file, "%s", culoare ) ;
            //opShow( culoare, Hanoi ) ;
        }
        if ( !strcmp( op, "show_moves" ) )
        {
            fscanf( file, "%s %d", culoare, &numar_mutari ) ;
            opShowMoves( culoare, numar_mutari ) ;
        }
    }

    fclose(file) ;
    free(op) ;
    free(culoare_disc) ;
    free(culoare) ;
}

void print(turn_hanoi *Hanoi)
{
    int i ;
    for ( i = 0 ; i < NMAX ; i++ )
        if ( !strcmp(Hanoi[i].culoare_hanoi, "nothing" ) )
            return ;
        else
            printf("%s ", Hanoi[i].culoare_hanoi) ;
}

int main( int argc, char *argv[] )
{
    int i ;
    turn_hanoi *Hanoi = (turn_hanoi*) malloc ( NMAX * sizeof(turn_hanoi) ) ;

    for ( i = 0 ; i < NMAX ; i++ )
    {
        Hanoi[i].A = (ASt) InitS() ;
        Hanoi[i].B = (ASt) InitS() ;
        Hanoi[i].C = (ASt) InitS() ;
        Hanoi[i].culoare_hanoi = (char*) malloc ( NMAX * sizeof(char) ) ;
        strcpy(Hanoi[i].culoare_hanoi, "nothing") ;

    }

    citeste(argv[1], Hanoi) ;

    for ( i = 0 ; i < NMAX ; i++ )
    {
        DistrS(&(Hanoi[i].A)) ;
        DistrS(&(Hanoi[i].B)) ;
        DistrS(&(Hanoi[i].C)) ;
        free(Hanoi[i].culoare_hanoi) ;
    }

    free(Hanoi) ;

    return 0 ;
}
