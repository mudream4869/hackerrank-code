#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;

int p10[10] = {1};

int numat(int n, int a){return (n/p10[a])%10;}

bool check(int a){
    for(int lx = 0;lx < 3;lx++)
        if(numat(a, lx) != numat(a, 5-lx))
            return false;
    return true;
}

void init(){
    for(int lx = 1;lx <= 9;lx++)
        p10[lx] = p10[lx-1]*10;
    for(int lx = 100;lx <= 999;lx++)
        for(int ly = lx+1;ly <= 999;ly++)
            if(check(lx*ly))
                v.push_back(lx*ly);
    sort(v.begin(), v.end()); 
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end()); 
    return;
}

int main() {
    init();
    int T; scanf("%d", &T);
    while(T--){
        int a; scanf("%d", &a);
        auto tt = lower_bound(v.begin(), v.end(), a);
        tt--;
        printf("%d\n", *tt);
    }
    return 0;
}