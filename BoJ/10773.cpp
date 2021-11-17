#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	stack<int> s;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (!num)s.pop();
		else s.push(num);
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}