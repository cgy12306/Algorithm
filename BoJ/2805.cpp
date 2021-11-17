// https://www.acmicpc.net/problem/2805
// 나무 자르기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<long long> wood;
	for (int i = 0; i < N; i++) {
		long long height;
		cin >> height;
		wood.push_back(height);
	}
	sort(wood.begin(), wood.end());

	long long left = 0, right = wood[N-1];
	
	long long result = 0;
	while (left <= right) {
		long long sum = 0;
		long long mid = (left + right) / 2;

		for (int next = 0; next < wood.size(); next++) {
			if (mid < wood[next]) {
				sum += wood[next] - mid;
			}
		}
		if (sum >= M) {
			if (result < mid) {
				result = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
}