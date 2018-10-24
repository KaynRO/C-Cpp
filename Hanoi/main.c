                                        // GRIGORAS ANDREI - 313CB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10000

typedef struct hanoi // definim un element de tip "sistem hanoi" ce contine 3 stive, culoare, numar discuri
{
    char *culoare_hanoi ;
    int noDiscs ;
    void *A ;
    void *B ;
    void *C ;
} turn_hanoi ;

typedef struct node // element al unei liste simplu inlantuite "nod"
{
    void* info ;
    struct node* next ;
} TStiva, *ASt;

typedef struct queue // coada, generated reprezentand daca pentru un sistem hanoi specificat s-au generat mutarile
{
    void* rear ;
    void* front ;
    int generated ;
}*Queue ;

void* InitQ ( void* movesQueue ) // initializam coada
{
    Queue temp = (Queue) malloc ( sizeof(struct queue) ) ;
    temp->rear = temp->front = NULL ;
    temp->generated = 0 ;
    movesQueue = (void*) temp ;
    return movesQueue ;
}

void* enQueue ( void* movesQueue, void* info ) // adaugam un element in coada
{
    ASt aux = (ASt) malloc ( sizeof(TStiva) ) ;
    aux->info = info ;
    aux->next = NULL ;

    if ( ((Queue)movesQueue)->rear == NULL )
    {
        ((Queue)movesQueue)->front = ((Queue)movesQueue)->rear = aux ;
        return movesQueue ;
    }

    ((ASt)((Queue)movesQueue)->rear)->next = aux ;
    ((Queue)movesQueue)->rear = aux ;
    return movesQueue ;
}

void* deQueue ( void* movesQueue ) // extragem din coada
{
    if ( ((Queue)movesQueue)->front == NULL )
        return NULL ;

    ((Queue)movesQueue)->front = ((ASt)((Queue)movesQueue)->front)->next ;

    if ( ((Queue)movesQueue)->front == NULL )
        ((Queue)movesQueue)->rear = NULL ;
    return movesQueue ;
}

void* InitS ( void* head ) // initilizam stiva
{
    head = NULL ;
    return head ;
}

void* Push ( void* head, void* info ) // push in stiva
{
    ASt aux =  (ASt) malloc  (sizeof(TStiva)) ;
    aux->info = info ;
    aux->next =  (ASt) head ;
    head =  (void*) aux ;
    return head ;
}

void* Pop (void* head) // pop din stiva
{
    ASt aux =  head ;
    head = ((ASt)head)->next ;
    free (aux) ;
    return head ;
}

void* Top ( void* head ) // vf stivei
{
    return  ( (ASt)head)->info ;
}

int Empty (void* head) // e vida
{
    return head == NULL ? 1 : 0 ;
}

void Free ( void* head )
{
    while ( head != NULL )
        head = Pop(head) ;

    free(head) ;
}

void* Revert ( void* head ) // inversarea stivei
{
    void* aux = NULL ;

    while ( !Empty(head) )
    {
        void* info = Top (head) ;
        head = Pop (head) ;
        aux = Push ( aux, info ) ;
    }

    head = aux ;
    return head ;
}

void Display ( void* head, FILE* filenameWrite ) // afisarea din stiva
{
    ASt aux =  (ASt) head ;

    while (aux != NULL)
    {
        fprintf ( filenameWrite, " " ) ;
        fprintf ( filenameWrite,"%s",  (char*)aux->info) ;
        aux = aux->next ;
    }

    fprintf ( filenameWrite,"\n") ;
}

void* Sort(void* head) // sortarea descrescatoare a stivei
{
    void* aux = NULL ;

    while (!Empty(head))
    {
        void* info = Top (head) ;
        head = Pop (head) ;
        while ( !Empty(aux) && atoi((char*)Top(aux)) > atoi((char*)info) )
        {
            head = Push ( head,Top(aux) ) ;
            aux = Pop (aux) ;
        }
        aux = Push ( aux, info ) ;
    }

    head = aux ;
    return head ;
}

void opAdd ( char* culoare, char* dimensiune, turn_hanoi* Hanoi ) // adaugarea unui nou disc
{
    int i ;

    for ( i = 0 ; i < NMAX ; i++ )
    {
        if  ( !strcmp ( Hanoi[i].culoare_hanoi, "nothing" ) )
        {
            strcpy ( Hanoi[i].culoare_hanoi, culoare ) ;
            Hanoi[i].A = Push ( Hanoi[i].A, dimensiune ) ;
            Hanoi[i].A = Sort (Hanoi[i].A) ;
            Hanoi[i].A = Revert (Hanoi[i].A) ;
            Hanoi[i].noDiscs++ ;
            break ;
        }
        if  ( !strcmp ( Hanoi[i].culoare_hanoi, culoare ) )
        {
            Hanoi[i].A = Push ( Hanoi[i].A, dimensiune ) ;
            Hanoi[i].A = Sort (Hanoi[i].A) ;
            Hanoi[i].A = Revert (Hanoi[i].A) ;
            Hanoi[i].noDiscs++ ;
            break ;
        }
    }
}

void opShow ( char* culoare, turn_hanoi* Hanoi, FILE* filenameWrite ) // operatia show
{
    int i ;

    for  ( i = 0 ; i < NMAX ; i++ )
    {
        if  ( !strcmp ( Hanoi[i].culoare_hanoi, culoare ) )
        {
            fprintf ( filenameWrite,"A_%s:", culoare ) ;
            Hanoi[i].A = Revert (Hanoi[i].A) ;
            Display ( Hanoi[i].A, filenameWrite ) ;
            Hanoi[i].A = Revert (Hanoi[i].A) ;
            fprintf ( filenameWrite,"B_%s:", culoare ) ;
            Hanoi[i].B = Revert (Hanoi[i].B) ;
            Display ( Hanoi[i].B, filenameWrite ) ;
            Hanoi[i].B = Revert (Hanoi[i].B) ;
            fprintf ( filenameWrite,"C_%s:", culoare ) ;
            Hanoi[i].C = Revert (Hanoi[i].C) ;
            Display ( Hanoi[i].C, filenameWrite ) ;
            Hanoi[i].C = Revert (Hanoi[i].C) ;
            return;
        }
    }

    fprintf ( filenameWrite,"A_%s:\n", culoare ) ;
    fprintf ( filenameWrite,"B_%s:\n", culoare ) ;
    fprintf ( filenameWrite,"C_%s:\n", culoare ) ;

}

void simulateMoves ( char from, char to, char aux, int N, void* movesQueue ) // simularea tuturor mutarilor de rezolvare a unui sistem
{
    size_t len = snprintf ( NULL, 0, "%c->%c", from, to ) ;
    char* text = (char*) malloc ( len + 1 ) ;

    if ( N == 1 )
    {
        snprintf ( text, len + 1, "%c->%c", from, to ) ;
        movesQueue = enQueue ( movesQueue, text ) ;
        return;
    }

    simulateMoves ( from, aux, to, N - 1, movesQueue ) ;

    snprintf ( text, len + 1, "%c->%c", from, to ) ;
    movesQueue = enQueue ( movesQueue, text ) ;

    simulateMoves ( aux, to, from, N - 1, movesQueue ) ;

}

void opShowMoves ( char* culoare, int noMoves, turn_hanoi* Hanoi, char from, char to, char aux, void* movesQueue[NMAX], FILE* fileWrite ) // afisarea a noMoves mutari din rezolvarea sistemului
{
    int i ;

    for ( i = 0 ; i < NMAX ; i++ )
        if ( !strcmp (Hanoi[i].culoare_hanoi, culoare) )
        {
            if ( ((Queue)movesQueue[i])->generated == 0 )
            {
                simulateMoves ( from, to, aux, Hanoi[i].noDiscs, movesQueue[i] ) ;
                ((Queue)movesQueue[i])->generated = 1 ;
            }
            break ;
        }

    ASt temp = (ASt)((Queue)movesQueue[i])->front ;
    fprintf ( fileWrite, "M_%s:", culoare ) ;
    while ( noMoves > 0 && temp != NULL )
    {
        fprintf ( fileWrite, " %s",  (char*)temp->info ) ;
        temp = temp->next ;
        noMoves-- ;
    }

    fprintf ( fileWrite, "\n" ) ;

}

void opPlay ( char* culoare,  int noMoves, turn_hanoi* Hanoi, void* movesQueue[NMAX] ) // efectuarea miscarilor
{
    int i ;
    char from, to, *text ;
    text = (char*) malloc ( NMAX * sizeof(char) ) ;

    for ( i = 0 ; i < NMAX ; i++ )
        if ( !strcmp ( Hanoi[i].culoare_hanoi, culoare ) )
        {
            if ( ((Queue)movesQueue[i])->generated == 0 )
            {
                simulateMoves ( 'A', 'C', 'B', Hanoi[i].noDiscs, movesQueue[i] ) ;
                ((Queue)movesQueue[i])->generated = 1 ;
            }
            break ;
        }

    ASt temp = (ASt)((Queue)movesQueue[i])->front ;

    while ( noMoves > 0 && temp != NULL )
    {
        text = (char*)temp->info ;
        from = text[0] ;
        to = text[3] ;

        if ( from == 'A' && to == 'B' )
        {
            Hanoi[i].B = Push ( Hanoi[i].B, Top (Hanoi[i].A) ) ;
            Hanoi[i].A = Pop (Hanoi[i].A) ;
        }

        if ( from == 'B' && to == 'A' )
        {
            Hanoi[i].A = Push ( Hanoi[i].A, Top (Hanoi[i].B) ) ;
            Hanoi[i].B = Pop (Hanoi[i].B) ;
        }

        if ( from == 'A' && to == 'C' )
        {
            Hanoi[i].C = Push ( Hanoi[i].C, Top (Hanoi[i].A) ) ;
            Hanoi[i].A = Pop (Hanoi[i].A) ;
        }

        if ( from == 'C' && to == 'A' )
        {
            Hanoi[i].A = Push ( Hanoi[i].A, Top (Hanoi[i].C) ) ;
            Hanoi[i].C = Pop (Hanoi[i].C) ;
        }
        if ( from == 'B' && to == 'C' )
        {
            Hanoi[i].C = Push ( Hanoi[i].C, Top (Hanoi[i].B) ) ;
            Hanoi[i].B = Pop (Hanoi[i].B) ;
        }

        if ( from == 'C' && to == 'B' )
        {
            Hanoi[i].B = Push ( Hanoi[i].B, Top (Hanoi[i].C) ) ;
            Hanoi[i].C = Pop (Hanoi[i].C) ;
        }

        temp = temp->next ;
        movesQueue[i] = deQueue(movesQueue[i]) ;
        noMoves-- ;
    }

    free(text) ;
}

void readFromFile ( char* filenameRead, char* filenameWrite, turn_hanoi* Hanoi, void* movesQueue[NMAX] ) // citirea
{
    int i, noMoves, N ;

    char* op =  (char*) malloc ( NMAX * sizeof (char) ) ;
    char* culoare =  (char*) malloc ( NMAX * sizeof (char) ) ;
    char* dimensiune[NMAX] ;
    FILE* fileRead = fopen ( filenameRead, "r" ) ;
    FILE* fileWrite = fopen ( filenameWrite, "w" ) ;

    fscanf ( fileRead, "%d", &N ) ;

    for ( i = 0 ; i < N ; i++ )
    {
        fscanf ( fileRead, "%s", op ) ;
        dimensiune[i] =  (char*) malloc ( NMAX * sizeof (char) ) ;
        if  ( !strcmp ( op, "add" ) )
        {
            fscanf ( fileRead,"%s %s", culoare, dimensiune[i] ) ;
            opAdd ( culoare, dimensiune[i], Hanoi ) ;
        }
        if  ( !strcmp ( op, "show" ) )
        {
            fscanf ( fileRead,"%s", culoare ) ;
            opShow ( culoare, Hanoi, fileWrite ) ;
        }
        if  ( !strcmp ( op, "show_moves" ) )
        {
            fscanf ( fileRead, "%s %d", culoare, &noMoves ) ;
            opShowMoves ( culoare, noMoves, Hanoi, 'A', 'C', 'B', movesQueue, fileWrite ) ;
        }
        if  ( !strcmp ( op, "play" ) )
        {
            fscanf ( fileRead,"%s %d", culoare, &noMoves ) ;
            opPlay ( culoare, noMoves, Hanoi, movesQueue ) ;
        }
    }

    free (op) ;
    free (culoare) ;
    fclose (fileRead) ;
    fclose (fileWrite) ;
}

int main ( int argc, char *argv[] )
{
    turn_hanoi* Hanoi =  (turn_hanoi*) malloc ( NMAX * sizeof (turn_hanoi) ) ; // variabila ce reprezinta totalitatea sistemelor hanoi
    void* movesQueue[NMAX] ; // un vector de cozi ce memoreaza mutarile ce urmeaza a fi facute
    int i ;

    for ( i = 0 ; i < NMAX ; i++)
    {
        Hanoi[i].culoare_hanoi =  (char*) malloc ( NMAX * sizeof (char) ) ;
        strcpy (Hanoi[i].culoare_hanoi, "nothing") ;
        Hanoi[i].noDiscs = 0 ;
        Hanoi[i].A = InitS (Hanoi[i].A) ;
        Hanoi[i].B = InitS (Hanoi[i].B) ;
        Hanoi[i].B = InitS (Hanoi[i].B) ;
        movesQueue[i] = InitQ (movesQueue[i]) ;
    }

    readFromFile ( argv[1], argv[2], Hanoi, movesQueue ) ;

    for ( i = 0 ; i < NMAX ; i++ )
    {
        Free(Hanoi[i].A) ;
        Free(Hanoi[i].B) ;
        Free(Hanoi[i].B) ;
        free(Hanoi[i].culoare_hanoi) ;
        movesQueue[i] = NULL ;
        free(movesQueue[i]) ;
    }

    free(Hanoi) ;
}
