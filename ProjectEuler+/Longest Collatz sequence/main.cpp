#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

int step[5000001] = {1, 1};

int getstep(int64 a){
    if(a <= 5000000 and step[a]) return step[a];
    int val = (a&1) ? getstep(a*3+1) : getstep(a>>1);
    val++;
    if(a <= 5000000) step[a] = val;
    return val;
}

int ans[5000001] = {1, 1};

int main() {
    
    for(int lx = 2;lx <= 5000000;lx++)
        ans[lx] = (getstep(ans[lx-1]) > getstep(lx)) ? ans[lx-1]: lx;
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}

