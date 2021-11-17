// https://www.acmicpc.net/problem/1541
// ÀÒ¾î¹ö¸° °ýÈ£

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int num = 0;
	bool minus = false;
	string s, snum;
	queue<int> que;
	cin >> s;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			snum += s[i];
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (minus) num -= stoi(snum);
			else num += stoi(snum);
			
			if (s[i] == '-') minus = true;
			snum.clear();
			continue;
		}
	}

	cout << num;

}