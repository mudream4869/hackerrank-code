#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

class vec{
public:
    int n;
    double val[11];
    vec(int _n):n(_n){
        for(int lx = 0;lx < n;lx++)
            val[lx] = 0;
        return;
    }

    void print() const{
        printf("[");
        for(int lx = 0;lx < n;lx++)
            printf(" %lf%c", val[lx], ",]"[lx == n-1]);
        printf("\n");
        return;
    }
};

vec operator+(const vec& a,const vec& b){
    assert(a.n == b.n);
    vec ret(a.n);
    for(int lx = 0;lx < a.n;lx++)
        ret.val[lx] = a.val[lx] + b.val[lx];
    return ret;
}

vec operator-(const vec& a,const vec& b){
    assert(a.n == b.n);
    vec ret(a.n);
    for(int lx = 0;lx < a.n;lx++)
        ret.val[lx] = a.val[lx] - b.val[lx];
    return ret;
}

double operator*(const vec& a, const vec& b){
    assert(a.n == b.n);
    double ret = 0;
    for(int lx = 0;lx < a.n;lx++)
        ret += a.val[lx]*b.val[lx];
    return ret;
}

vec operator*(const double& v, const vec& a){
    vec ret(a);
    for(int lx = 0;lx < a.n;lx++)
        ret.val[lx] *= v;
    return ret;
}

int main(){
    int f, n; scanf("%d %d", &f, &n);
    vector<vec> vs(n, vec(f+1));
    vector<double> ds(n);
    for(int lx = 0;lx < n;lx++){
        for(int ly = 0;ly < f;ly++)
            scanf("%lf", &vs[lx].val[ly]);
        vs[lx].val[f] = 1;
        scanf("%lf", &ds[lx]);
    }

    vec w(f+1);

    for(int it = 0;it < 10000000;it++){
        int sel = rand()%n;
        double pred = w*vs[sel];
        double err = (ds[sel] - pred);
        double alpha = 1.0/(it + 1);
        w = w + alpha*err*vs[sel];
    }

    int k; scanf("%d", &k);
    while(k--){
        vec inp(f+1);
        for(int lx = 0;lx < f;lx++)
            scanf("%lf", &inp.val[lx]);
        inp.val[f] = 1;
        printf("%f\n", w*inp);
    }
    
    return 0;
}
