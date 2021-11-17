// https://www.acmicpc.net/problem/1181
// 단어 정렬 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool size_compare(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cin.tie(NULL);

	int N;
	string s;
	vector <string> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), size_compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i <<"\n";
	}
}