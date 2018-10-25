#include <fstream>

#define MOD 1999999973

using namespace std;

ifstream cin ("lgput.in");
ofstream cout ("lgput.out");

long long n, p, current, ans, pow_sum;

void read()
{
    cin >> n >> p;
}

long long lgput(long long n, long long p)
{
    current = n;
    ans = 1;
    for(int i = 0; i < 32 and pow_sum < p; ++i)
    {
        if( (1 << i) & p)
        {
            pow_sum += (1 << i);
            ans *= current;
            ans %= MOD;
        }
        current *= current;
        current %= MOD;
    }
    return ans;
}

int main()
{
    read();
    cout << lgput(n, p) << '\n';
    return 0;
}
