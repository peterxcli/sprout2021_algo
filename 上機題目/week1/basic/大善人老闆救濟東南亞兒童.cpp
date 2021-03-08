#include<bits/stdc++.h>

using namespace std;

bool judge(int N);

int Permutations[100000];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> Permutations[i];
        }
        if(judge(N))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

bool judge(int N){
    stack<int> station;
    int index = 0, counter = 1;
    while(index != N) {
        if(!station.empty() && (Permutations[index] == station.top())){
            index ++;
            station.pop();
        }
        else{
            if(counter > N) break;
            station.push(counter++);//1 2 3 4 5
        }
    }
    if(index == N) return true;
    else return false;
}

