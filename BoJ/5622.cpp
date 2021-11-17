#include<iostream>
#include<string>
using namespace std;

int alp[144];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	alp['A'] = 3; alp['B'] = 3; alp['C'] = 3;
	alp['D'] = 4; alp['E'] = 4; alp['F'] = 4;
	alp['G'] = 5; alp['H'] = 5; alp['I'] = 5;
	alp['J'] = 6; alp['K'] = 6; alp['L'] = 6;
	alp['M'] = 7; alp['N'] = 7; alp['O'] = 7;
	alp['P'] = 8; alp['Q'] = 8; alp['R'] = 8; alp['S'] = 8;
	alp['T'] = 9; alp['U'] = 9; alp['V'] = 9;
	alp['W'] = 10; alp['X'] = 10; alp['Y'] = 10; alp['Z'] = 10;

	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		sum += alp[s[i]];
	}
	cout << sum;
}