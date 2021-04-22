#include<algorithm>
using namespace std;
int magic[1500];
void initialize(int n){
    for(int i=0;i<n;i++)
        magic[i]=n-i-1;
}
int hasEdge(int a, int b){
    if(a>b)swap(a,b);
    magic[a]-=1;
    if(magic[a]<=0){
        return 1;
    }
    else {
        return 0;
    }
}