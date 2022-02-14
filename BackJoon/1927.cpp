// https://www.acmicpc.net/problem/1927
// �ּ� ��

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;

	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << pq.top()<< "\n";
				pq.pop();
			}
		}
		else pq.push(num);
	}
}