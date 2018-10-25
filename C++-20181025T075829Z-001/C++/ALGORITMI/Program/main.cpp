#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include <cmath>
#include <iomanip>

using namespace std ;

ifstream in("quest.in") ;
ifstream r1("answer.in") ;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
VOID WINAPI SetConsoleColors(WORD attribs);
HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_FONT_INFOEX font;
COORD coord ;

int culoare, i, j ;
char Rebus[1000][1000], c ;
char Corect[1000][1000] ;
int x, k, gresit ;
bool ok ;

VOID WINAPI SetConsoleColors(WORD attribs)
{
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFOEX cbi;
    cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hOutput, &cbi);
    cbi.wAttributes = attribs;
    SetConsoleScreenBufferInfoEx(hOutput, &cbi);
}

void wait( int ms )
{
    int st = clock() ;
    while (clock() - st < ms) ;
}

void SetColor(unsigned int culoare)
{
    SetConsoleTextAttribute( hConsole,  culoare ) ;
}

void print_questions()
{
    cout << endl ;
    cout<< "1.Ce echipa a castigat meciul de aseara din Champions League ?" << endl ;
    cout << endl ;
    cout<< "2.Din ce tara este jucatorul Sneijder ?" << endl ;
    cout << endl ;
    cout<< "3.Cine este cel mai tanar jucatori din echipa FC Barcelona ?" << endl ;
    cout << endl ;
    cout<< "4.Cum se numeste ultima etapa dintr-o cupa ?" << endl ;
    cout << endl ;
    cout<< "5.De ce echipa a fost eliminata Borussia Dortmund in Europa League ?" << endl ;
    cout << endl ;
    cout<< "6.Din ce tara vine echipa FC Copenhaga ?" << endl ;
    cout << endl ;
    cout<< "7.Unde stau fanii in timpul unui meci ?" << endl ;
    cout << endl ;
    cout<< "8.Ce fel de teren este folosit pentru construirea stadioanelor ?" << endl ;
    cout << endl ;
    cout<< "9.Din ce motiv o echipa foarte buna poate pierde un meci ?" << endl ;
    cout << endl ;
    cout<< "10.Ce tara scandinava nu a castigat niciodata campionatul mondial ?" << endl ;
    cout << endl ;
}

void print()
{
    SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY) ;
    cout << endl ;
    for( i = 0 ; i < 12 ; i++ )
    {
        for ( int k = 0 ; k <= 70 ; k++ )
            cout << ' '  ;
        for( j = 0 ; j < 27 ; j++ )
            cout << Rebus[i][j] ;
        cout<< "\n" ;
    }
}

int  is_quest_full()
{
    for ( int i = 0 ; i < 12 ; i++ )
        for ( int j = 0 ; j < 27 ; j++ )
            if (Rebus[i][j] == '_' )
                return 0 ;
    return 1 ;
}

void space()
{
    for ( k = 0 ; k < 20 ; k++ )
        cout << '\n' ;
    for ( int k = 0 ; k < 60 ; k++ )
        cout << ' ' ;
}

BOOL SetConsoleFontSize(COORD dwFontSize)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX info{sizeof(CONSOLE_FONT_INFOEX)};
    if (!GetCurrentConsoleFontEx(output, false, &info))
        return false;
    info.dwFontSize = dwFontSize;
    return SetCurrentConsoleFontEx(output, false, &info);
}

void set_text_size()
{
    coord.X = 10 ;
    coord.Y = 16 ;
    SetConsoleFontSize(coord) ;
}

int main()
{
    set_text_size() ;
    for( i = 0 ; i < 12 ; i++ )
    {
        for( j = 0 ; j < 27 ; j++ )
        {
            r1.get(c) ;
            Corect[i][j] = c ;
        }
        r1.get() ;
    }
    char answer[10] ;
    SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    space() ;
    cout << "Esti pregatit sa rezolvi un rebus ?" << '\n' ;
    cin.getline( answer, 10 ) ;
    if ( strstr( answer, "DA") || strstr ( answer, "Da" ) || strstr ( answer, "da" ) || strstr( answer, "dA" ) ) ;

    else
    {
        system ("cls") ;
        space() ;
        cout << "Ai pierdut cel mai tare rebus :(" ;
        exit(0) ;
    }
    system("cls") ;
    srand(time(NULL)) ;
    SetConsoleColors(BACKGROUND_BLUE) ;
    for ( i = 0 ; i < 12 ; i++ )
    {
        for( j = 0 ; j < 27 ; j++ )
        {
            in.get(c) ;
            Rebus[i][j] = c ;
        }
        in.get() ;
    }

    print() ;
    print_questions() ;
    int tryed_spaces = 0 ;
    int wrong_spaces = 0 ;
    int good_spaces = 0 ;
    int free_spaces = 18 ;
    while ( !is_quest_full() )
    {
        ok = false ;
        cout << "  INTRODUCETI O LITERA:  " ;
        c = getch() ;
        tryed_spaces++ ;
        cout << c << ' ' ;
        wait(400) ;
        for( i = 0 ; i < 12 ; i++ )
        {
            for( j = 0 ; j < 27 ; j++ )
                if( Rebus[i][j] == '_' && Corect[i][j] == c )
                {
                    Rebus[i][j] = c ;
                    ok = true ;
                }
        }
        if(ok == true)
        {
            cout << "Corect!" ;
            wait(400) ;
            system("cls") ;
            print() ;
            print_questions() ;
            good_spaces++ ;
        }
        else
        {
            cout << "Gresit!" ;
            wait(400) ;
            wrong_spaces++ ;
            system("cls") ;
            print() ;
            print_questions() ;
        }
    }
    system("cls") ;
    space() ;
    cout << " Ati avut " << tryed_spaces << " incercari, dintre care " << good_spaces << " au fost corecte, iar " << wrong_spaces << " gresite." ;
    wait(5000) ;
    system("cls") ;
    space() ;
    cout << " Rata de succes este " << double ((double)good_spaces / (double)tryed_spaces) * 100 << '%'  ;
    wait(5000) ;
    system("cls") ;
    space() ;
    cout << " Ati primit nota " << round( (double) 10 * free_spaces / (double) tryed_spaces ) ;
    wait(5000) ;
    return 0 ;
}
