#include<iostream>
#include<string>

using namespace std;
int arr[123];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C, mul;
	string s;

	cin >> A >> B >> C;
	mul = A * B * C;
	s = to_string(mul);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') arr[s[i]]++;
		else if (s[i] == '1') arr[s[i]]++;
		else if (s[i] == '2') arr[s[i]]++;
		else if (s[i] == '3') arr[s[i]]++;
		else if (s[i] == '4') arr[s[i]]++;
		else if (s[i] == '5') arr[s[i]]++;
		else if (s[i] == '6') arr[s[i]]++;
		else if (s[i] == '7') arr[s[i]]++;
		else if (s[i] == '8') arr[s[i]]++;
		else if (s[i] == '9') arr[s[i]]++;
	}
	for (int i = '0'; i <= '9'; i++) {
		cout << arr[i] << "\n";
	}
}