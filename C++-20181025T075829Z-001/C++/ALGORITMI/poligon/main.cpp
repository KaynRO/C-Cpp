#include<fstream>
#include<vector>

using namespace std;
typedef int var;

ifstream f("poligon.in");
ofstream g("poligon.out");

struct punct {
    double x, y;
    punct(double a, double b) {
        x = a;
        y = b;
    }
};

vector<punct> poligon;

bool check(punct P) {
    var n = poligon.size();
    bool isinside = 0;
    for(var i=1; i<n; i++) {

        punct A = poligon[i-1],
              B = poligon[i];

        if(A.x > B.x) swap(A, B);

        if(P.x <= A.x || P.x > B.x)
            continue;

        if((P.y-A.y)*(B.x-A.x) <= (P.x-A.x)*(B.y-A.y)) {
            isinside ^= 1;
        }

    }
    return isinside;
}

int main() {
    var n, m;
    var x, y;

    f >> n >> m;
    for(var i=1; i<=n; i++) {
        f>>x>>y;
        poligon.push_back(punct(x, y));
    }
    poligon.push_back(poligon[0]);

    int sum = 0;

    while(m--) {
        f >> x >> y;
        punct P(x, y);
        sum += check(P);
    }

    g<< sum;

    return 0;
}
