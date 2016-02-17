#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> primes;

bool seive[200001] = {0};

int main() {
    for(int lx = 2;lx <= 200000;lx++){
        if(not seive[lx]){
            primes.push_back(lx);
            for(int ly = 2;ly*lx <= 200000;ly++)
                seive[lx*ly] = true;
        }
    }
    int T; scanf("%d", &T);
    while(T--){
        int v; scanf("%d", &v);
        printf("%d\n", primes[v-1]);
    }
    return 0;
}