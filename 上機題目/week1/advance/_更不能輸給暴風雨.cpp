#include <bits/stdc++.h>
#define N 5001
using namespace std;

int ST[N], ST2[N], st = 0, st2 = 0;
queue<int> qq;
void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();

void solve(int n,int T[]){
    int t;
    st = t = st2 = 0;
    for(int i=1;i<=n;i++){
        ST[st++]=i;
        push_train();//qq.push(1);
        while(ST[st-1]==T[t]){
            st--;
            t++;
            move_station_1_to_2();//qq.push(2);
            pop_train();//qq.push(4);
            if(st==0)break;
        }
    }
    while(st!=0||st2!=0){
            //if(tmp==st){no_solution();break;}
            //else tmp=st;
            while(st>0){
                ST2[st2++]=ST[--st];
                move_station_1_to_2();//qq.push(2);
                while(ST2[st2-1]==T[t]){
                    st2--;
                    t++;
                    pop_train();//qq.push(4);
                    if(st2==0)break;
                }
                if(st>0)
                    while(ST[st-1]==T[t]){
                    st--;
                    t++;
                    move_station_1_to_2();//qq.push(2);
                    pop_train();//qq.push(4);
                    if(st==0)break;
                    }
            }
            while(st2>0){
                ST[st++]=ST2[--st2];
                move_station_2_to_1();//qq.push(2);
                while(ST[st-1]==T[t]){
                    st--;
                    t++;
                    move_station_1_to_2();
                    pop_train();//qq.push(4);
                    if(st==0)break;
                }
                if(st2>0)
                    while(ST2[st2-1]==T[t]){
                        st2--;
                        t++;
                        pop_train();//qq.push(4);
                        if(st2==0)break;
                    }
            }
    }
}