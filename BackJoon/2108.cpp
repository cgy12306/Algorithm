// https://www.acmicpc.net/problem/2108
// ≈Î∞Ë«–

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	long long sum = 0;
	vector<int> v;
	vector<int> v2(8001, 0);
	cin >> N;
	int Max = 0, Max_num;
	vector<int> many;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		v2[4000 + x]++;
		if (Max < v2[4000 + x]) {
			Max = v2[4000 + x];
			Max_num = x;
		}
		sum += x;
	}

	for (int i = 0; i < 8001; i++) {
		if (v2[i] == Max) {
			many.push_back(i-4000);
		}
	}

	sort(v.begin(), v.end());

	cout << round((float)sum / (float)N) << "\n";
	cout << v[N / 2] << "\n";
	if (many.size() > 1) cout << many[1]<<"\n";
	else cout << many[0] <<"\n";

	cout <<  v[v.size()-1] - v[0] << "\n";
}