#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#define MOD 100000007
#define R size
#define C at(0).size
using namespace std;

#define int long long
typedef long long ll;
typedef vector<ll> v1d;
typedef vector<v1d> v2d;

inline v2d matrix_multi(const v2d &a, const v2d &b) {
    v1d tmp(b.C(), 0);
    v2d ret(a.R(), tmp);
    int a_R = a.R(), b_C = b.C(), a_C = a.C();
    for (int i = 0; i < a_R; i++) {
        for (int j = 0; j < b_C; j++) {
            for (int k = 0; k < a_C; k++){
                int temp = a[i][k] * b[k][j] % MOD;
                ret[i][j] = (temp + ret[i][j])%MOD;
            }
        }
    }
    return ret;
}

inline void print(const v2d &matrix) {
    int row = matrix.R(), column = matrix.C(); 
    for (int i = 0; i < row; i++){
        cout << matrix[i][0];
        for (int j = 1; j < column; j++){
            cout << " " << matrix[i][j] ;
        }
        cout << "\n";
    }
}

int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int Ra, Ca, Rb, Cb;
    cin >> Ra >> Ca; 
    v1d tmp(Ca, 0);
    v2d a(Ra, tmp);
    for(int i = 0; i < a.R(); i++) {
        for (int j = 0; j < a.C(); j++) {
            ll tmp;
            cin >> tmp;
            a[i][j] = ((tmp%MOD)+MOD)%MOD;
        }
    }
    cin >> Rb >> Cb;
    tmp.resize(Cb, 0);
    v2d b(Rb, tmp);
    for(ll i = 0; i < b.R(); i++) {
        for (ll j = 0; j < b.C(); j++) {
            ll tmp;
            cin >> tmp;
            b[i][j] = ((tmp%MOD)+MOD)%MOD;
        }
    }
    if (a.C() != b.R() && a.R() != b.C()) cout << "unmultipliable!" << "\n";
    else if(a.C() != b.R() && a.R() == b.C()) cout << "incommutable!" << "\n";
    else print(matrix_multi(a, b));
}

