#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        int ans[10000] = {1}; int dig = 1;
        for(int lx = 0;lx < n;){
            int mval = 2;
            if(n-lx>= 3)
                lx += 3, mval = 8;
            else
                lx++;
            for(int ld = 0;ld < dig;ld++)
                ans[ld] *= mval;
            for(int ld = 0;ld < dig;ld++){
                ans[ld+1] += ans[ld]/10;
                ans[ld] %= 10;
            }
            dig += ans[dig] > 0;
        }
        int val = 0;
        for(int lx = 0;lx < dig;lx++)
            val += ans[lx];
        printf("%d\n", val);
    }
    return 0;
}