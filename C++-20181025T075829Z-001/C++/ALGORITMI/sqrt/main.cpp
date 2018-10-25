#include <bits/stdc++.h>
using namespace std;
double a, x0, x1 ;
int main()
{
    cin >> a ;
    x0 = x1 = a ;
    do
    {
        x0 = x1 ;
        x1 = 0.5 * ( x0 + a / x0 ) ;
            printf("%0.5lf\n",x1);
    }
    while ( abs(x1-x0) > 0.00001 );
    printf("%0.5lf\n",x1);
    return 0;
}
