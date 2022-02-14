// https://www.acmicpc.net/problem/17219
// 비밀번호 찾기

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string id, pw;

	map<string, string> account;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> id >> pw;
		account[id] = pw;
	}

	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;
		cout << account[site] << "\n";
	}
}