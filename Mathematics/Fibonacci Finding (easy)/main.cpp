#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int64 P = 1000000007;

struct vec2{int64 x, y;};
struct Met{vec2 a, b;};

int operator*(vec2 v1, vec2 v2){
    return ((v1.x*v2.x)%P + (v1.y*v2.y)%P)%P;
}

Met operator*(Met m1, Met m2){
    int tmp = m2.b.x; m2.b.x = m2.a.y; m2.a.y = tmp;
    Met ret;
    ret.a.x = m1.a*m2.a;
    ret.a.y = m1.a*m2.b;
    ret.b.x = m1.b*m2.a;
    ret.b.y = m1.b*m2.b;
    return ret;
}

Met pow(Met a, int n){
    if(n == 0){
        Met I; I.a.x = 1, I.a.y = 0, I.b.x = 0, I.b.y = 1;
        return I;
    }
    Met ret = pow(a, n>>1);
    ret = ret*ret;
    if(n&1) return ret*a;
    return ret;
}

int main() {
    int T; scanf("%d", &T);
    Met M0;
    M0.a.x = 1, M0.a.y = 1, M0.b.x = 1, M0.b.y = 0;
    while(T--){
        int64 a, b, n; scanf("%lld %lld %lld", &a, &b, &n);
        vec2 a0 = {b, a};
        Met MM = pow(M0, n);
        printf("%lld\n", MM.b*a0);
    }
    return 0;
}