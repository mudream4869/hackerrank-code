#include <cstdio>
#include <cstdlib>
using namespace std;

void pn(int k, const char* str){
    while(k--)
        puts(str);
    return;
}

int main() {
    int n; scanf("%d", &n);
    
    int x1, y1, x2, y2;
    
    for(int i=0; i<n; i++) {
        char str[1000]; scanf("%s", str);
        for(int lx = 0;lx < n;lx++)
            if(str[lx] == 'm')
                x1 = lx, y1 = i;
            else if(str[lx] == 'p')
                x2 = lx, y2 = i;
    }
    
    if(x1 < x2)
        pn(x2 - x1, "RIGHT");
    else
        pn(x1 - x2, "LEFT");
    if(y1 < y2)
        pn(y2 - y1, "DOWN");
    else
        pn(y1 - y2, "UP");


    return 0;
}