#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#define NMAX 1000
#define MAX 65536

typedef struct node // elementul dintr hashtable
{
    char* key ;
    char* value ;
    struct node* next ;
} arbNode ;

typedef struct hashList // hashtable
{
    int size ;
    arbNode** table ;
} hashTable ;

typedef struct tree // un nod din arbore
{
    char* info ;
    struct tree* left ;
    struct tree* right ;
} treeNode ;

treeNode* makeNode ( treeNode* left, treeNode* right, char* info ) // alocam un nou nod
{
    treeNode* aux = malloc ( sizeof(treeNode) ) ;

    aux->left = left ;
    aux->right = right ;
    aux->info = info ;

    return aux ;
}

hashTable* htCreate ( int size ) // alogam hashtable
{
    int i = 0 ;
    hashTable *hTable = NULL ;
    hTable = malloc ( sizeof(hashTable) ) ;
    hTable->table = malloc ( sizeof(arbNode*) * size ) ;

    for ( i = 0 ; i < size ; i++ )
        hTable->table[i] = NULL ;

    hTable->size = size ;

    return hTable ;
}

int htHash ( hashTable* hTable, char* key ) // calculam hashul pentru o cheie anume
{
    unsigned long int hashVal = 0 ;
    int i = 0 ;

    while ( hashVal < ULONG_MAX && i < strlen(key) )
    {
        hashVal = hashVal << 8 ;
        hashVal += key[i] ;
        i++ ;
    }

    return hashVal % hTable->size ;
}

arbNode* htNewPair ( char* key, char* value ) // cream un element din hashtable
{
    arbNode* newPair ;
    newPair = malloc ( sizeof(arbNode) ) ;

    newPair->key = key ;
    newPair->value = value ;
    newPair->next = NULL ;

    return newPair ;
}

void htSet( hashTable* hTable, char* key, char* value ) // inseram o noua valoare, daca este deja o updatam, altfel o adaugam
{
    int bin = 0 ;
    arbNode* newPair = NULL ;
    arbNode* next = NULL ;
    arbNode* last = NULL ;

    bin = htHash ( hTable, key ) ;
    next = hTable->table[bin] ;

    while ( next != NULL && next->key != NULL && strcmp ( key, next->key ) > 0 )
    {
        last = next ;
        next = next->next ;
    }

    if ( next != NULL && next->key != NULL && strcmp ( key, next->key ) == 0 )
    {
        free (next->value) ;
        next->value = value ;
    }
    else
    {
        newPair = htNewPair ( key, value ) ;

        if ( next == hTable->table[bin] )
        {
            newPair->next = next ;
            hTable->table[bin] = newPair ;
        }
        else if ( next == NULL )
            last->next = newPair ;
        else
        {
            newPair->next = next ;
            last->next = newPair ;
        }
    }
}

char* htGet ( hashTable* hTable, char* key ) // cautam elementul cu o cheie anume
{
    int bin = 0 ;
    arbNode* pair = NULL ;

    bin = htHash ( hTable, key ) ;

    pair = hTable->table[bin] ;
    while ( pair != NULL && pair->key != NULL && strcmp ( key, pair->key ) > 0 )
        pair = pair->next ;

    if ( pair == NULL || pair->key == NULL || strcmp ( key, pair->key ) != 0 )
        return NULL ;
    else
        return pair->value ;

}

int isOperator ( char* info ) // e operator
{
    if ( strcmp ( info, "+" ) == 0
            || strcmp ( info, "-" ) == 0
            || strcmp ( info, "*" ) == 0
            || strcmp ( info, "/" ) == 0
            || strcmp ( info, "sqrt" ) == 0
            || strcmp ( info, "^" ) == 0 )
        return 1 ;
    return 0 ;
}

int isNumber ( char* info ) // e numar, pozitiv sau negativ
{
    int i = 0 ;
    if ( !( ( info[i] <= '9' && info[i] >= '0' ) || info[i] == '-' ) )
        return 0 ;
    for ( i = 1 ; i < strlen(info) ; i++ )
        if ( info[i] > '9' || info[i] < '0' )
            return 0 ;
    return 1 ;
}

treeNode* makeBinaryTree ( char* variables[NMAX], int* index ) // construim arborele de expresie
{

    if ( !isOperator(variables[*index]) )
        return  makeNode ( NULL, NULL, variables[*index] ) ;
    else
    {
        int aux = *index ;
        treeNode *left = NULL, *right = NULL ;

        if ( strcmp ( variables[*index], "sqrt" ) == 0 )
        {
            *index = *index + 1 ;
            left = makeBinaryTree ( variables, index ) ;
            right = NULL ;
        }
        else
        {
            *index = *index + 1 ;
            left = makeBinaryTree ( variables, index ) ;
            *index = *index + 1 ;
            right = makeBinaryTree ( variables, index ) ;
        }
        return makeNode ( left, right, variables[aux] ) ;
    }
}

int evaluateTree ( treeNode* root, hashTable* hTable, int* ok, FILE* output ) // calculam valoarea arborelui
{
    if (!root)
        return 0 ;

    if ( root->left == NULL && root->right == NULL )
    {
        if ( isNumber(root->info) )
            return atoi(root->info) ;
        else
        {
            if ( htGet ( hTable, root->info ) == NULL )
            {
                if ( *ok == 1 )
                    fprintf ( output, "Variable %s undeclared\n", root->info ) ;
                *ok = 0 ;
            }
            else
                return atoi(htGet ( hTable, root->info ) ) ;
        }
    }

    if ( strcmp ( root->info, "sqrt" ) == 0 && root->left != NULL )
    {
        int leftValue = evaluateTree ( root->left, hTable, ok, output ) ;
        if ( leftValue < 0 )
        {
            if ( *ok == 1 )
                fprintf ( output, "Invalid expression\n" ) ;
            *ok = 0 ;
        }
        else
            return sqrt(leftValue) ;
    }

    else
    {
        int leftValue = evaluateTree ( root->left, hTable, ok, output ) ;
        int rightValue = evaluateTree ( root->right, hTable, ok, output ) ;

        if ( strcmp ( root->info, "+" ) == 0 )
            return leftValue + rightValue ;

        if ( strcmp ( root->info, "-" ) == 0 )
            return leftValue - rightValue ;

        if ( strcmp ( root->info,"*" ) == 0 )
            return leftValue * rightValue ;

        if ( strcmp ( root->info,"/" ) == 0 )
        {
            if ( rightValue == 0 )
            {
                if ( *ok == 1 )
                    fprintf ( output, "Invalid expression\n" ) ;
                *ok = 0 ;

            }
            else
                return leftValue / rightValue ;
        }
        return pow ( leftValue, rightValue ) ;
    }
}

void solve ( hashTable* hTable, char* equation, FILE* output ) // rezolvam pentru o ecuatie anume
{
    char* variables[NMAX] ;
    int i = 0, ok = 1, position = 0 ;
    for ( i = 0 ;  i < NMAX ; i++ )
        variables[i] = NULL ;

    i = 0 ;
    variables[i] = strtok ( equation, " " ) ;

    while ( variables[i] != NULL )
        variables[++i] = strtok ( NULL, " " ) ;

    char* pos ;
    if ( ( pos = strchr ( variables[i - 1], '\n' ) ) != NULL )
        *pos = '\0' ;

    treeNode* root = makeBinaryTree ( variables, &position ) ;
    int result = evaluateTree ( root, hTable, &ok, output ) ;
    if ( ok )
        fprintf ( output, "%d\n", result ) ;
}

void freeSpace ( char** varName, char* aux, char** varValue ) // eliberam ce am alocat
{
    int i = 0 ;

    free(aux) ;
    for ( i = 0 ; i < NMAX ; i++ )
    {
        free(varName[i]) ;
        free(varValue[i]) ;
    }
    free(varName) ;
    free(varValue);
}

void read ( char* inputFile, char* outputFile, hashTable* hTable )
{
    int i = 0, nrVar, nrEq ;
    char **varName, *aux = NULL, **varValue, **equation ;

    FILE* input = fopen ( inputFile, "r" ) ;
    FILE* output = fopen ( outputFile, "w" ) ;
    aux = (char*) malloc ( NMAX * sizeof(char) ) ;
    equation = (char**) malloc ( NMAX * sizeof(char*) ) ;
    varName = (char**) malloc ( NMAX * sizeof(char*) ) ;
    varValue = (char**) malloc ( NMAX * sizeof(char*) ) ;

    for ( i = 0 ; i < NMAX ; i++ )
    {
        varName[i] = (char*) malloc ( NMAX * sizeof(char) ) ;
        varValue[i] = (char*) malloc ( NMAX * sizeof(char) ) ;
        equation[i] = (char*) malloc ( NMAX * sizeof(char) ) ;
    }

    fscanf ( input, "%d", &nrVar ) ;

    for ( i = 1 ; i <= nrVar ; i++ )
    {
        fscanf ( input, "%s", varName[i] ) ;
        fscanf ( input, "%s", aux ) ;
        fscanf ( input, "%s", varValue[i] ) ;
        htSet ( hTable, varName[i], varValue[i] ) ;
    }

    fscanf ( input, "%d", &nrEq ) ;
    fgets ( equation[0], 1000, input) ;

    for ( i = 1 ; i <= nrEq ; i++ )
    {
        fgets ( equation[i], 1000, input ) ;
        solve ( hTable, equation[i], output ) ;
        free(equation[i]) ;
    }

    free(equation[0]) ;
    freeSpace ( varName, aux, varValue ) ;
    fclose(input) ;
    fclose(output) ;
}

int main ( int argc, char* argv[] )
{
    hashTable* hTable = htCreate(MAX) ;

    read ( argv[1], argv[2], hTable ) ;

    return 0 ;
}
