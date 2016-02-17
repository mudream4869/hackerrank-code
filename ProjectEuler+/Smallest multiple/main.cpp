#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 lcm(int64 a, int64 b){
    return a/__gcd(a, b)*b;
}

int64 ans[41];

int main() {
    ans[1] = 1;
    for(int lx = 2;lx <= 40;lx++)
        ans[lx] = lcm(lx, ans[lx-1]);
    int T; scanf("%d", &T);
    while(T--){
        int a; scanf("%d", &a);
        printf("%lld\n", ans[a]);
    }
    return 0;
}