#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long int int64;

const int64 P = 1000000007;

int64 bpow(int64 a, int64 n){
    if(!n) return 1;
    int64 val = bpow(a, n>>1);
    val = (val*val)%P;
    if(n&1) return (val*a)%P;
    return val;
}

int64 rev(int64 a){
    return bpow(a, P-2);
}

int64 seqm[1001] = {1, 1};
int64 rseqm[1001];

int main() {
    
    for(int lx = 1;lx <= 1000;lx++)
        seqm[lx] = (seqm[lx-1]*(int64)lx)%P;
    
    for(int lx = 1;lx <= 1000;lx++){
        rseqm[lx] = rev(seqm[lx]);
        assert((rseqm[lx]*seqm[lx])%P == 1);
    }
    
    int T; scanf("%d", &T);
    while(T--){
        int a, b; scanf("%d %d", &a, &b);
        int64 ans = seqm[a+b];
        ans = (ans*rseqm[a])%P;
        ans = (ans*rseqm[b])%P;
        printf("%lld\n", (((seqm[a+b]*rseqm[a])%P)*rseqm[b])%P);
    }
    
    return 0;
}