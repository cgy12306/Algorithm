// https://www.acmicpc.net/problem/10816
// 숫자 카드 2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector<int>::iterator up, low;
	vector<int> A, B;

	cin >> N;
	for (int i = 0 ; i < N; i++) {
		cin >> num;
		A.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());

	for (auto iter = B.begin(); iter != B.end(); ++iter) {
		up = upper_bound(A.begin(), A.end(), *iter);
		low = lower_bound(A.begin(), A.end(), *iter);
		cout << up - low << " ";
	}
}