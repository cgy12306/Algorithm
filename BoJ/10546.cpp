// https://acmicpc.net/problem/10546
// 배부른 마라토너
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<string> participant;
	vector<string> completion;

	unordered_map<string, int> um;
	string answer = "";
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		participant.push_back(s);
	}

	for (int i = 0; i < N - 1; i++) {
		string s;
		cin >> s;
		completion.push_back(s);
	}

	for (auto p : participant) {
		um[p]++;
	}

	for (auto c : completion) {
		um[c]--;
	}
	for (auto u : um) {
		if (u.second > 0) {
			answer = u.first;
		}
	}
	cout << answer;

	return 0;
}