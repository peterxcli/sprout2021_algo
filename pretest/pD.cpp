#include <bits/stdc++.h>
#define MOD 100000007
#define R size
#define C at(0).size
using namespace std;

typedef long long ll;
typedef vector<ll> v1d;
typedef vector<v1d> v2d;

v2d matrix_multi(const v2d &a, const v2d &b) {
    v1d tmp(b.C(), 0);
    v2d ret(a.R(), tmp);
    int a_R = a.R(), b_C = b.C(), a_C = a.C();
    for (int i = 0; i < a_R; i++) {
        for (int j = 0; j < b_C; j++) {
            for (int k = 0; k < a_C; k++){
                int temp = ( (ll)(a[i][k]%MOD) * (ll)(b[k][j]%MOD) )%(ll)MOD;
                ret[i][j] = ( (ll)temp + (ll)(ret[i][j]%MOD) )%(ll)MOD;
            }
        }
    }
    return ret;
}

void print(const v2d &matrix) {
    int row = matrix.R(), column = matrix.C(); 
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            cout << matrix[i][j] << " ";
        }
    cout << "\n";
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int Ra, Ca, Rb, Cb;
    cin >> Ra >> Ca; 
    v1d tmp(Ca, 0);
    v2d a(Ra, tmp);
    for(int i = 0; i < a.R(); i++) {
        for (int j = 0; j < a.C(); j++) {
            ll tmp;
            cin >> tmp;
            a[i][j] = ((tmp%(ll)MOD)+(ll)MOD)%(ll)MOD;
        }
    }
    cin >> Rb >> Cb;
    tmp.resize(Cb, 0);
    v2d b(Rb, tmp);
    for(ll i = 0; i < b.R(); i++) {
        for (ll j = 0; j < b.C(); j++) {
            ll tmp;
            cin >> tmp;
            b[i][j] = ((tmp%(ll)MOD)+(ll)MOD)%(ll)MOD;
        }
    }
    if (a.C() != b.R() && a.R() != b.C()) cout << "unmultipliable!" << "\n";
    else if(a.C() != b.R() && a.R() == b.C()) cout << "incommutable!" << "\n";
    else print(matrix_multi(a, b));
}

