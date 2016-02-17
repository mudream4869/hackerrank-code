#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int main() {
    int T; scanf("%d", &T);
    while(T--){
        int64 a; scanf("%lld", &a);
        printf("%lld\n", (a*a*(a+1)*(a+1))/4 - a*(a+1)*(2*a+1)/6);
    }
    return 0;
}