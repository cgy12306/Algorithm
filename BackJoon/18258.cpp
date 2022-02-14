#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	queue<int> q;
	for (int n = 0; n < N; n++) {
		string cmd;
		int num;
		cin >> cmd;

		if (!cmd.compare("push")) {
			cin >> num;
			q.push(num);
		}
		else if (!cmd.compare("pop")) {
			if (q.empty()) cout << "-1\n";
			else {
				num = q.front();
				cout << num << "\n";
				q.pop();
			}
		}
		else if (!cmd.compare("size")) {
			cout << q.size() << "\n";
		}
		else if (!cmd.compare("empty")) {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (!cmd.compare("front")) {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() <<"\n";
		}
		else if (!cmd.compare("back")) {
			if (q.empty()) cout << "-1\n";
			else cout << q.back()<< "\n";
		}
	}
}
