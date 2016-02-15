#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int main() {
    int n; scanf("%d", &n);
    int64 a = 10000000, b = 10000000;
    while(n--){
        int64 c, d; scanf("%lld %lld", &c, &d);
        a = min(c, a), b = min(d, b);
    }
    printf("%lld\n", a*b);
    return 0;
}

