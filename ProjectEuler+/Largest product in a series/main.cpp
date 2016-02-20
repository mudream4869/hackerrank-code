#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; scanf("%d", &T);
    while(T--){
        int n, k; scanf("%d %d", &n, &k);
        char str[1010]; scanf("%s", str);
        int ans = 0;
        for(int lx = 0;lx+k < n;lx++){
            int val = 1;
            for(int ly = 0;ly < k;ly++)
                val *= (int)(str[lx+ly] - '0');
            ans = max(ans, val);
        }
        printf("%d\n", ans);
    }
    return 0;
}