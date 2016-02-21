#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool inRange(int x, int y){
    return x >= 0 and x < 20 and y >= 0 and y < 20;
}

int main() {
    int tab[20][20];
    for(int lx = 0;lx < 20;lx++)
        for(int ly = 0;ly < 20;ly++)
            scanf("%d", &tab[lx][ly]);
    int ans = 0;
    int dir[][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    
    for(int lx = 0;lx < 20;lx++){
        for(int ly = 0;ly < 20;ly++){
            for(int d = 0;d < 4;d++){
                int dx = dir[d][0], dy = dir[d][1];
                if(not inRange(lx + dx*3, ly + dy*3)) continue;
                int val = 1;
                for(int ld = 0;ld < 4;ld++)
                    val *= tab[lx + dx*ld][ly + dy*ld];
                ans = max(val, ans);
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}