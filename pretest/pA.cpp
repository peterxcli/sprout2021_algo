#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0), ios_base::sync_with_stdio(0);
	int a, b, t1, t2;
	cin >> a >> b;
	unordered_map<int, pair<int, int> > num;
	vector<int> ans;
	for (int i = 0; i < a; i++) {
		cin >> t1;
		auto iter = num.find(t1);
		if (iter == num.end())
			num.emplace(make_pair(t1, make_pair(1, 0)));
		else
			iter->second.first++;
	}
	for (int i = 0; i < b; i++) {
		cin >> t1 >> t2;
		auto iter = num.find(t2);
		if (iter == num.end())
			continue;
		if (t1 == 0) {
			if (iter->second.second > 0)
				iter->second.second--;
			else
				iter->second.first--;
		}
		if (t1 == 1)
			iter->second.second++;
	}
	for (auto i = num.begin(); i != num.end(); i++) {
		for (int j = 0; j < i->second.first; j++) {
			ans.emplace_back(i->first);
		}
	}
	cout << ans.size() << endl;
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << " " << ans[i];
	cout << "\n";
	return 0;
}