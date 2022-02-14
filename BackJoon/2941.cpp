#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin >> s;

	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj","s=","z=" };
	
	for (auto idx : v) {
		while (1) {
			int it = s.find(idx);
			if (it == string::npos) break;
			s.replace(it, idx.length(), "1");
		}
	}

	cout << s.length();
	
}