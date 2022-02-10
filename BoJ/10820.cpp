#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	while (getline(cin, s)) {
		int space = 0, upper = 0, lower = 0, number = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') space++;
			else if (s[i] >= 'A' && s[i] <= 'Z') upper++;
			else if (s[i] >= 'a' && s[i] <= 'z') lower++;
			else if (s[i] >= '0' && s[i] <= '9') number++;
		}
		cout << lower << " "<< upper << " " << number <<" " << space <<"\n";
	}


}