// https://www.acmicpc.net/problem/14675
// 단절점과 단절선
#include<iostream>
#include<vector>
using namespace std;

int N, question;

vector<int> tree[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cin >> question;

	for (int q = 0; q < question; q++) {
		int t, k;
		cin >> t >> k;
		if (t == 1) {
			if (tree[k].size() > 1) cout << "yes\n";
			else cout << "no\n";
		}
		else if (t == 2) {
			cout << "yes\n";
		}
	}

}