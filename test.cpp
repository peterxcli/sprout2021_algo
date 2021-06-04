using namespace std;
#include <iostream>
int main() {
    int a, c, d = 0, e;
    cin >> a;
    int b[a];
    cin >> b[a];
    for (c = 0; c <= a; c++) {
        if (d < b[a]) {
            e = a;
            d = b[a];
        } else
            d = d;
    }
    cout << a + 1 << " " << d;
}