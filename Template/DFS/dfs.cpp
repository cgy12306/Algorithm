#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> Edges;
int V, E, S;
bool visited[1002];

void DFS(int current) {
	visited[current] = true;

	cout << "visit : " << current << "\n";

	for (auto next : Edges[current]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> V >> E >> S;

	Edges.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int from, to;
		cin >> from >> to;
		Edges[from].push_back(to);
	}

	DFS(S);

}
