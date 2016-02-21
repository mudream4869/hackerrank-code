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
        int tab[20][20];
        int ans[20][20];
        for(int lx = 0;lx < n;lx++)
            for(int ly = 0;ly <= lx;ly++)
                scanf("%d", &tab[lx][ly]);
        ans[0][0] = tab[0][0];
        for(int lx = 1;lx < n;lx++){
            for(int ly = 0;ly <= lx;ly++){
                int t = 0;
                if(lx > ly) t = max(t, ans[lx-1][ly]);
                if(ly > 0)  t = max(t, ans[lx-1][ly-1]); 
                ans[lx][ly] = t + tab[lx][ly];
            }
        }
        
        /*for(int lx = 0;lx < n;lx++)
            for(int ly = 0;ly <= lx;ly++)
                printf("%d%c", ans[lx][ly], " \n"[ly == lx]);
        */
        int val = 0;
        for(int lx = 0;lx < n;lx++)
            val = max(val, ans[n-1][lx]);
        
        printf("%d\n", val);
    }
    return 0;
}