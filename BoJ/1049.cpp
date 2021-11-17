// https://www.acmicpc.net/problem/1049
// ±‚≈∏¡Ÿ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b, pay = 0;
	vector<int> v1, v2;

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a;
		cin >> b;
		v1.push_back(a);
		v2.push_back(b);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if (N >= 6) {
		if (v1.front() < v2.front() * 6) {
			pay = (N / 6) * v1.front();
		}
		else {
			pay = (v2.front() * 6) * (N / 6);
		}
	}

	if (N % 6 > 0) {
		if (v1.front() < (N % 6) * v2.front()) {
			pay += v1.front();
		}
		else {
			pay += (N % 6) * v2.front();
		}
	}
	
	cout << pay;

	return 0;
}