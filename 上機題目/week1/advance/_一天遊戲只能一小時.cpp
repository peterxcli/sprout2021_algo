#include <bits/stdc++.h>

using namespace std;

#define N 1000001
#define M 101
using namespace std;
int L[M][2]={0},O[N]={0};

int main(int argc,char *argv[])
{
    int n,m,a,b;
    char c[10];
    scanf("%d %d",&n,&m);
    while(m){
             scanf("%s",c);
             if(c[0]=='A'){
                   scanf("%d %d",&a,&b);
                   if(L[a][0]==0) L[a][0]=L[a][1]=b;
                   else           L[a][1]=O[L[a][1]]=b;
                   O[b]=0;
                   m--;
             }else if(c[0]=='L'){
                   scanf("%d",&a);
                   if(L[a][0]==0)printf("queue %d is empty!\n",a);
                   else  L[a][0]=O[L[a][0]];
                   if(!L[a][0])L[a][1]=0;
                   m--;
             }else if(c[0]=='J'){
                   scanf("%d %d",&a,&b);
                   if(L[b][0]){
                           O[L[b][1]]=L[a][0];
                           if(L[a][1])L[b][1]=L[a][1];
                   }else{
                           L[b][0]=L[a][0];
                           L[b][1]=L[a][1];
                   }
                   L[a][0]=L[a][1]=0;
                   m--;
             }
    }
    for(int i=1;i<=n;i++){
            printf("queue %d:",i);
            if(!L[i][0])printf(" empty");
            else for(int j=L[i][0];j!=0;j=O[j])printf(" %d",j);
            puts("");
    }
    system("pause");
    return 0;
}