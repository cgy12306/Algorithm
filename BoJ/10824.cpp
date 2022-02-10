#include<iostream>
#include<string>

using namespace std;
int main() {

	int A, B, C, D;
	long long ans;
	cin >> A >> B >> C >> D;
	string s1 = to_string(A) + to_string(B);
	string s2 = to_string(C) + to_string(D);

	ans = stoll(s1) + stoll(s2);
	
	cout << ans;

}