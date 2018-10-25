#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std ;

fstream fout ( "passwords.out" ) ;

vector < string > dictionary, basicDictionary ;
set < string > finalDictionary ;
string word ;

void basicKeyWords()
{
    basicDictionary.push_back("123") ;
    basicDictionary.push_back("12345678") ;
    basicDictionary.push_back("123456789") ;
    basicDictionary.push_back("1") ;
    basicDictionary.push_back("12") ;
}

void combineWords()
{
    for ( vector < string > :: iterator it = dictionary.begin() ; it != dictionary.end() ; ++it )
        for ( vector < string > :: iterator iq = basicDictionary.begin() ; iq != basicDictionary.end() ; ++iq )
        {
            string combined = *it + *iq ;
            finalDictionary.insert(combined) ;
        }
    for ( vector < string > :: iterator it = dictionary.begin() ; it != dictionary.end() ; ++it )
        for ( vector < string > :: iterator iq = dictionary.begin() ; iq != dictionary.end() ; ++iq )
            for ( vector < string > :: iterator im = basicDictionary.begin() ; im != basicDictionary.end() ; ++im )
                if ( *it != *iq )
                {
                    string combined = *it + *iq ;
                    finalDictionary.insert(combined) ;
                    combined = *it + *iq + *im ;
                    finalDictionary.insert(combined) ;
                }
}

int main()
{
    basicKeyWords() ;
    string word ;
    cout << " Introdu cuvintele cheie :" << '\n' ;
    cin >> word ;

    while ( word != "end" )
    {
        dictionary.push_back(word) ;
        cin >> word ;
    }

    combineWords() ;
    for ( set < string > :: iterator it = finalDictionary.begin() ; it != finalDictionary.end() ; ++it )
        fout << *it << '\n' ;

    return 0;
}
