#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long int int64;

int64 val[50000];
int64 ptr[50000];
int64 sum[50000];

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        for(int lx = 0;lx < n;lx++)
            scanf("%lld", val+lx);
        
        ptr[n-1] = n-1;
        for(int lx = n-2;lx>=0;lx--)
            ptr[lx] = (val[ptr[lx+1]] > val[lx]) ? ptr[lx+1] : lx;
        
        sum[0] = val[0];
        for(int lx = 1;lx < n;lx++)
            sum[lx] = sum[lx-1] + val[lx];

        int nptr = ptr[0];
        int64 ans = 0;
        if(ptr[0])
            ans += val[ptr[0]]*(ptr[0]) - sum[ptr[0]-1];

        while(nptr < n-1){
            int xptr = ptr[nptr+1];
            ans += val[xptr]*(xptr - nptr - 1) - (sum[xptr-1] - sum[nptr]);
            nptr = xptr;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
