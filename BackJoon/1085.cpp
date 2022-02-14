#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int wclose, hclose;

	hclose = h - y;
	wclose = w - x;

	if (hclose < 0) hclose *= -1;
	if (wclose < 0) wclose *= -1;
	cout << min({ x, y, wclose, hclose });

}