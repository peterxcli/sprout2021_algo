#include <bits/stdc++.h>

using namespace std;

vector<int> A_order, B_order;

int main() {
    string A = "Hello";
    A.insert(A.begin(), A[A.size()-1]); A.erase(A.size()-1);
    cout << A << endl;
}