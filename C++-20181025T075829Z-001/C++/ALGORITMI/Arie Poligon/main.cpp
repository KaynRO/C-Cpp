#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define NMAX 100002
using namespace std;

int n;
double arie;

struct punct
{
    double x,y;
} v[NMAX];

ifstream f("aria.in");
ofstream g("aria.out");

int main()
{
    f >> n;
    for(int i=1; i<=n; i++)
    {
        f >> v[i].x >> v[i].y;
    }
    v[n+1] = v[1];

    for(int i=1; i<=n; i++)
    {
        arie = arie + (v[i].x * v[i+1].y - v[i+1].x * v[i].y);
    }

    g << fixed << setprecision(5) << arie/2;

    return 0;
}
