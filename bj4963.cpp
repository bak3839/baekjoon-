#include <iostream>
#include <vector>

using namespace std;

int w, h;
vector<vector<int>> graph;

void dfs(int x, int y) {
	if ((x >= 0 && x < h) && (y >= 0 && y < w)) {
		if (graph[x][y] == 1) {  // �� �ϳ��� ����� 8���� ��� �湮ó��
			graph[x][y] = 0; 
			dfs(x, y - 1);
			dfs(x, y + 1);
			dfs(x - 1, y);
			dfs(x + 1, y);

			dfs(x - 1, y - 1);
			dfs(x - 1, y + 1);
			dfs(x + 1, y - 1);
			dfs(x + 1, y + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;

	while (1) {
		int cnt = 0;
		vector<int> v;

		cin >> w >> h;

		if (!w && !h) break; // 0 0 �ԷµǸ� ����

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> num;
				v.push_back(num);
			}

			graph.push_back(v);
			v.clear();
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] == 1) { // ���̶�� dfs ���� 8���� �湮ó�� ����
					dfs(i, j); 
					++cnt;
				}
			}
		}
		graph.clear();
		cout << cnt << "\n";
	}
	
	return 0;
}