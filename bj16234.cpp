#include <iostream>
#include <algorithm>
#include <queue>
#include  <vector>
#include <cstring>

using namespace std;

short country[50][50];
bool visited[50][50], visited_copy[50][50], pass = false;
int N, L, R;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

// ���ο��� Ž�������� ���� �湮ó���� �ȵȰ��̸� �ǽ���

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector< pair<int, int>> loc; // ���յ� ������ ��ǥ = ���߿� ����� �����ֱ� ����

	int cnt = 0, sum = 0;
	sum += country[x][y];
	
	q.push({ x, y });
	loc.push_back({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			// �� �� �� �� ������ ����

			int nx = x + mv1[i];
			int ny = y + mv2[i];

			int gap = abs(country[x][y] - country[nx][ny]);

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N)) {
				if (!visited[nx][ny] && L <= gap && gap <= R) {
					++cnt; // �̾��� ������ ��
					visited[nx][ny] = true; // �湮ó��
					sum += country[nx][ny]; // �α��� ���ϱ�

					q.push({ nx,ny }); // ������ġ ť�� ����
					loc.push_back({ nx,ny }); // ����ο����� �ٲ��ֱ� ���� ��ġ ����

					pass = true;
				}
			}
		}
	}

	if (cnt != 0) {
		short aver = sum / (cnt + 1);

		for (int i = 0; i < loc.size(); i++) {
			x = loc[i].first;
			y = loc[i].second;

			country[x][y] = aver;
		}
	}

	else loc.pop_back();
	loc.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int day = 0;

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}

	while (1) {
		pass = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) bfs(i, j);
			}
		}

		memset(visited, false, sizeof(visited));

		if (!pass) break;
		++day;
	}

	cout << day;
	return 0;
}