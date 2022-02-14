// https://www.acmicpc.net/problem/14002
// 가장 긴 증가하는 부분 수열 4

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int arr[1001] = { 0, }, dp[1001] = { 0, }, dp2[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	fill(dp, dp + 1000, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	cout << *max_element(dp, dp + n) << "\n";
	
	int idx;

	idx = distance(dp, max_element(dp, dp + sizeof(dp) / sizeof(dp[0])));

	/*for (int i = 0; i <= idx; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i <= idx; i++) {
		cout << dp[i] << " ";
	}*/
	
	memcpy(dp2, dp, sizeof(int) * idx);
	
	for (int i = 0; i <= idx; i++) {
		if (arr[idx] >= arr[i] && dp2[idx] < dp2[i] + 1) {
			//dp2[idx] = dp2[i] + 1;
			v.push_back(arr[idx]);
			//cout << arr[i] <<" ";
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}
	
}