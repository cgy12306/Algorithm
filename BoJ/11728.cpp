// https://www.acmicpc.net/problem/11728
// 배열 합치기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector<int> v;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter <<" ";
	}
} 