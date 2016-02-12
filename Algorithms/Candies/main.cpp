#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int dp[100000] = {0};
int val[100000];

int main(){
    int n; scanf("%d", &n);
    for(int lx = 0;lx < n;lx++)
        scanf("%d", val + lx);
    
    queue<int> que;
    for(int lx = 0;lx < n;lx++)
        if(lx == 0 or lx == n-1 or (val[lx-1] >= val[lx] and val[lx] <= val[lx+1]))
            que.push(lx);
    
    while(que.size()){
        int g = que.front(); que.pop();
        int v = 0;
        if(g-1 >= 0 and val[g] > val[g-1])
            v = max(v, dp[g-1]);

        if(g+1 < n and val[g] > val[g+1])
            v = max(v, dp[g+1]);

        if(g+1 < n and val[g] < val[g+1])
            que.push(g+1);

        if(g-1 >= 0 and val[g] < val[g-1])
            que.push(g-1);

        dp[g] = v+1;
//        printf("dp[%d] = %d\n", g, v+1);
    }
    long long int sum = 0;
    for(int lx = 0;lx < n;lx++)
        sum += (long long int)dp[lx];
    printf("%lld\n", sum);

    return 0;
}

