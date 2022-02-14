#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int arr[123];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	memset(arr, -1, sizeof(arr));
	cin >> s;

	for (int i = s.size()-1; i >= 0; i--) {
		arr[s[i]] = i;
	}
	for (int i = 'a'; i <='z'; i++) {
		cout << arr[i] <<" ";
	}
}