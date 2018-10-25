#include <fstream>

using namespace std ;

ifstream fin ( "sant.in" ) ;
ofstream fout ( "sant.out" ) ;

int st = 0 , V[200] , Price[200] , Category[200] , S , N , C , prt[200] , sol[200] , minim = 99999999 ;
void read()
{
    int value , price ;
    fin >> S >> N >> C ;
    for ( int i = 1 ; i <= C ; i++ )
    {
        fin >> value >> price ;
        V[++st] = value ;
        Price[value] = price ;
        Category[value] = i ;
    }
}

int suma ( int pos )
{
    int value = 0 ;
    for ( int i = 1 ; i <= pos ; i++ )
        value += sol[i] ;
    return value ;
}

int price ( int pos )
{
    int value = 0 ;
    for ( int i = 1 ; i <= pos ; i++ )
        value += Price[sol[i]] ;
    return value ;
}

void bkt ( int pos )
{
    if ( pos == N + 1 )
    {
        int current_price = price(pos-1) ;
        if ( current_price < minim && suma(pos-1) == S )
        {
            minim = current_price ;
            for ( int i = 1 ; i <= N ; i++ )
                prt[i] = sol[i] ;
        }
    }
    else
    {
        for ( int i = 1 ; i <= st ; i++ )
        {
            if ( pos == 1 || suma(pos-1) + V[i] <= S )
            {
                sol[pos] = V[i] ;
                bkt(pos+1) ;
            }
        }
    }
}

int main()
{
    read() ;
    bkt(1) ;
    fout << minim << '\n' ;
    for ( int i = 1 ; i <= N ; i++ )
        fout << Category[prt[i]] << ' ' ;
    return 0;
}
