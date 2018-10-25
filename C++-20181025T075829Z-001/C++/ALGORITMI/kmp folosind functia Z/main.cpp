#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void calc_z (string &s, vector<int> & z)
{
    int len = s.size();
    z.resize (len);

    int l = 0, r = 0;
    for (int i=1; i<len; ++i)
        if (z[i-l]+i <= r)
            z[i] = z[i-l];
        else
        {
            l = i;
            if (i > r) r = i;
            for (z[i] = r-i; r<len; ++r, ++z[i])
                if (s[r] != s[z[i]])
                    break;
            --r;
        }
}
int main()
{
    string A , B ;
    cin >> A >> B ;
    string working_string = A + B ;
    vector<int> z ;
    vector<int> matches ;
    calc_z( working_string , z ) ;
    for(int i = A.size(); i < working_string.size(); ++i)
        if(z[i] >=A.size())
            matches.push_back( i - A.size() ) ;
    cout << matches.size() << '\n' ;
    for ( vector<int> :: iterator it = matches.begin() ; it != matches.end() ; ++it )
        cout << *it << ' ' ;
}
