#include <cstdio>
#include <vector>
using namespace std;

bool vis[500001];
int nums[500001];
vector<int> ans[250000];

int main(void) {
  int N, cnt = 0;
  scanf("%d", &N);
  for (int i=1; i<=N; i++) {
    scanf("%d", &nums[i]);
  } 
  for (int i=1; i<=N; i++) {
    if (!vis[i]) {
      vis[i] = true;
      ans[cnt].push_back(i);
      while (!vis[nums[ans[cnt].back()]]) {
        vis[nums[ans[cnt].back()]] = true;
        ans[cnt].push_back(nums[ans[cnt].back()]);
      }
      cnt++;
    }
  }
  printf("%d\n", cnt);
  for (int i=0; i<250000; i++) {
    if (!ans[i].empty()) {
      for (int o=ans[i].size()-1; o>=0; o--) {
        printf("%d ", ans[i][o]);
      }
      printf("\n");
    }
    else break;
  }
  
  return 0;
}