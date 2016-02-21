#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000000;

typedef long long int int64;

int64 divi[N+10] = {0};
int64 tri_div[N+10] = {0};
int ans[2001] = {0};

int main() {
    
    for(int pp = 1;pp <= N;pp++)
        for(int ly = 1;ly*pp <= N;ly++)
            divi[pp*ly]++;
    
    int ptr = 1;
    for(int lx = 1;lx <= N;lx++){
        int64 val;
        if(lx&1)
            val = divi[lx]*divi[lx/2+1];
        else
            val = divi[lx/2]*divi[lx+1];
      
        if(val > 2000) continue;
        
        while(ptr <= min(2000LL, val) and ans[ptr] == 0)
            ans[ptr++] = lx;
        
        //printf("%lld\n", val);
        
    }
    
    for(int lx = 1999;lx >= 0;lx--)
        if(!ans[lx])
            ans[lx] = ans[lx+1];
        
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        int64 aa = ans[n+1];
        printf("%lld\n",(aa)*(aa+1)/2);
    }
   
    return 0;
}