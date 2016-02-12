#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 mpow(int64 a, int n, int64 p){
    if(n == 0) return 1;
    int64 rr = mpow(a, n>>1, p);
    rr = (rr*rr)%p;
    if(n&1) return (rr*a)%p;
    return rr;
}

int main() {
    const char ans[][5] = {"NO", "YES"};
    int T; scanf("%d", &T);
    while(T--){
        int64 a, p; scanf("%lld %lld", &a, &p);
        puts(ans[mpow(a, (p-1)/2, p) <= 1]);
    }
    
    return 0;
}