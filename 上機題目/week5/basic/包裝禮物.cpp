#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[7];
    while (1) {
        for(int i = 1; i <= 6; i++) cin >> a[i];
        if(accumulate(a+1, a+7, 0) == 0) return 0;
        int ans = 0;
        ans += a[4] + a[5] + a[6];
        //case 5
        a[1] -= a[5] * 11;
        //case 4
        if(a[4] * 5 > a[2]){
            a[1] -= (a[4]*5 - a[2])*4;
            a[2] = 0;
        }
        else {
            a[2] -= a[4]*5;
        }
        //case 3
        ans += a[3]/4 ;
        a[3] %= 4;
        if(a[3] != 0) ans++, a[3] = 4-a[3];
        //case 3 special case
        if (a[3] == 3) {
            if(a[2] < 5){
                a[1] -= (5-a[2]) * 4 + 7;
                a[2] = 0;
            }
            else{
                a[2] -= 5;
                a[1] -= 7;
            }
        }
        else if(a[3] == 2) {
            if(a[2] < 3){
                a[1] -= (3-a[2])*4+6;
                a[2] = 0;
            }
            else{
                a[2]-=3;
                a[1]-=6;
            }
        }
        else if(a[3] == 1) {
            if(a[2] > 0) a[2]--, a[1]-=5;
            else a[1] -= 9;
        }
        //case 2;
        if(a[2] > 0) {
            ans += a[2]/9;
            a[2] %= 9;
            if(a[2] != 0) ans++;
            a[1] -= (9-a[2]) * 4;
        }
        if(a[1] > 0){
            ans += a[1]/36;
            if(a[1]%36 != 0) ans++; 
        }
        cout << ans << "\n";
    }
    return 0;
}

// 較大面積的產品先裝箱，若有裝完還有剩餘空間也是用剩下面積越大越好的產品填滿空隙。

// 6*6的產品一個只能放一箱
// 5*5的產品一個也只能放一箱，然後可以再多塞11個1*1的產品
// 4*4的產品一個只能放一箱，剩下的空間可以多塞5個2*2的產品，若2*2的沒了就用1*1的塞
// 3*3的產品4個可以裝一箱，如3*3裝不滿一箱則用2*2與1*1塞
// 2*2的產品9個可以裝一箱，同樣的若裝不滿則用1*1塞
// 剩下的1*1每36個可以裝一箱，最後不滿36個的自己一箱