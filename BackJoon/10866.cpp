#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string s;
	deque<int> dq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> s;
		if (!s.compare("push_front")) {
			cin >> num;
			dq.push_front(num);
		}
		if (!s.compare("push_back")) {
			cin >> num;
			dq.push_back(num);
		}
		if (!s.compare("pop_front")) {
			if (dq.empty()) cout<< "-1" <<"\n";
			else {
				cout << dq.front() <<"\n";
				dq.pop_front();
			}
		}
		if (!s.compare("pop_back")) {
			if (dq.empty()) cout << "-1" << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		if (!s.compare("size")) {
			cout << dq.size() << "\n";
		}
		if (!s.compare("empty")) {
			if(dq.empty())cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		if (!s.compare("front")) {
			if (!dq.empty()) cout << dq.front() <<"\n";
			else cout << "-1"<<"\n";
		}
		if (!s.compare("back")) {
			if (!dq.empty()) cout << dq.back() << "\n";
			else cout << "-1"<<"\n";
		}
	}

}