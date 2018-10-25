#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define NMAX 20

using namespace std ;

int Dist[NMAX][NMAX], factoryCount ;
bool action ;

struct factory
{
    int owner ;
    int troops ;
    int production ;
} Factory[NMAX] ;

struct troop
{
    int owner ;
    int troops ;
    int turns ;
} Troop[NMAX] ;

struct comparer
{
    bool operator() ( const int& x, const int& y )
    {
        if ( Factory[x].troops != Factory[y].troops )
            return Factory[x].troops < Factory[y].troops ;
        else
            return Factory[x].production > Factory[y].production ;
    }
};

set < int, comparer > S ;

void capture_neutral()
{
    while ( !S.empty() )
    {
        int target = *S.begin() ;
        S.erase(S.begin()) ;
        for ( int j = 0 ; j <= factoryCount - 1 ; j++ )
            if ( Factory[j].troops > Factory[target].troops && Factory[j].owner == 1 )
            {
                if ( action )
                    cout << ";" ;
                cout << "MOVE" << ' ' << j << ' ' << target << ' ' << Factory[target].troops + 1 ;
                Factory[j].troops = Factory[j].troops - Factory[target].troops - 1 ;
                action = true ;
                break ;
            }
    }
}

int main()
{
    cin >> factoryCount;
    cin.ignore();
    int linkCount; // the number of links between factories
    cin >> linkCount;
    cin.ignore();
    for (int i = 0; i < linkCount; i++)
    {
        int factory1;
        int factory2;
        int distance;
        cin >> factory1 >> factory2 >> distance;
        cin.ignore();
        Dist[factory1][factory2] = distance ;
        Dist[factory2][factory1] = distance ;
    }

    while (1)
    {
        int entityCount;
        action = false ;
        S.clear() ;
        cin >> entityCount;
        cin.ignore();
        for (int i = 0; i < entityCount; i++)
        {
            int entityId;
            string entityType;
            int arg1;
            int arg2;
            int arg3;
            int arg4;
            int arg5;
            cin >> entityId >> entityType >> arg1 >> arg2 >> arg3 >> arg4 >> arg5;
            cin.ignore();
            if ( entityType == "FACTORY" )
            {
                Factory[entityId] = { arg1, arg2, arg3 } ;
                if ( arg1 != 1 )
                    S.insert(entityId) ;
            }
            else Troop[arg3] = { arg1, arg4, arg5 } ;
        }
        capture_neutral() ;
        if ( action ) cout << endl ;
        else
            cout << "WAIT" << endl ;

    }
}
