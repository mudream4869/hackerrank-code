#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int int64;

const int N = 1000000;

vector<int64> prime;
vector<int64> sprime;

bool seive[N+1] = {0};

int main() {
    
    for(int lx = 2;lx <= N;lx++){
        if(seive[lx] == 0){
            prime.push_back(lx);
            for(int ly = 2;ly*lx <= N;ly++)
                seive[ly*lx] = 1;
        }
    }
    
    sprime = prime;
    for(int lx = 1;lx < sprime.size();lx++)
        sprime[lx] += sprime[lx-1];
    
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        int ptr = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
        printf("%lld\n", sprime[ptr-1]);
    }
    
    return 0;
}