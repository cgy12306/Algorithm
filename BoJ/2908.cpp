#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	string x, y;

	cin >> a >> b;

	x = to_string(a);
	y = to_string(b);

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	a = stoi(x);
	b = stoi(y);

	if (a > b)cout << a;
	else cout << b;

}