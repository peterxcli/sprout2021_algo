#include <bits/stdc++.h>
using namespace std;
int main() {
    bool a, b, c, d;
    for (int i = 0; i < (1<<4)-1; i++) {
        a = i&(1<<3), b = i&(1<<2), c = i&(1<<1), d = i&(1);
        if ( (a | ~d) & (~a | b) & (~b | c) & (~a | ~b | ~c) & (a | ~c | d) == true) {
            printf("%b\n", i);
        }
    }
    return 0;
}