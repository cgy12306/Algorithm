// https://www.acmicpc.net/problem/11279
// ÃÖ´ë Èü

#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;

	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (pq.empty()) {
				cout << "0" << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(num);
	}
}