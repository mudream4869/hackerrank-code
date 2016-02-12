#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long int int64;

int main(){
    int n, m, c[100];
    scanf("%d %d", &n, &m);
    for(int lx = 0;lx < m;lx++)
        scanf("%d", c + lx);

    int64 dp[251] = {1};
    for(int lx = 0;lx < m;lx++){
        int64 tmp[251] = {0};
        for(int lc = 0;lc <= n;lc++)
            if(dp[lc])
                for(int ly = 1;ly*c[lx]+lc <= n;ly++)
                    tmp[lc + ly*c[lx]] += dp[lc];

        for(int ly = 0;ly <= n;ly++)
            dp[ly] += tmp[ly];
    }

    printf("%lld\n", dp[n]);
    return 0;
}
