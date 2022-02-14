#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	queue<int> q, p;

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		for (int i = 0; i < K-1; i++) {
			q.push(q.front());
			q.pop();
		}
		p.push(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < N-1; i++) {
		cout << p.front() << ", ";
		p.pop();
	}
	cout << p.front() << ">";
}