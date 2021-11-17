// https://www.acmicpc.net/problem/5430
// AC

#include<iostream>
#include<algorithm>
#include<string>
#include<deque>

using namespace std;

bool rev, errflag;
int T, n;
string p, arr, ch;
deque<int> dq;
char bracket, comma = ',';

void input() {
	cin >> arr;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '[') continue;
		else if (arr[i] >= '0' && arr[i] <= '9') ch += arr[i];
		else if (arr[i] == ']' || arr[i] == ',') {
			if (!ch.empty()) {
				dq.push_back(stoi(ch));
				ch.clear();
			}
		}
	}
}

void del() {

	if (rev) {
		dq.pop_back();
	}
	else {
		dq.pop_front();
	}
}

void output() {	
	cout << "[";
	while (!dq.empty()) {
		if (rev) {
			cout << dq.back();
			dq.pop_back();
		}
		else {
			cout << dq.front();
			dq.pop_front();
		}
		if (!dq.empty()) cout << comma;
	}
	cout << "]" << "\n";
}

void init() {
	while (!dq.empty()) dq.pop_back();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		init();
		rev = false;
		cin >> p >> n;
		int Dcnt = 0;
		for (int i = 0; i < p.size(); i++) {
			if(p[i] == 'D') Dcnt++;
		}

		input();

		if (Dcnt > n) {
			cout << "error" << "\n";
			continue;
		}

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				rev = !rev;
			}
			else if (p[i] == 'D') {
				del();
			}
		}
		output();
	}
}