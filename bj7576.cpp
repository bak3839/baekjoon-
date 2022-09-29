#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int graph[1000][1000];
int res = 0, cnt = 0, M, N;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs() {
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			// �� �� �� �� ������ ����

			int nx = x + mv1[i];
			int ny = y + mv2[i];

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M)) { // ������ �Ѿ�� ����
				if (!graph[nx][ny]) { // ������ �丶���� ����
					graph[nx][ny] = graph[x][y] + 1; // ���� ��ġ�� �ϼ����� +1 �ؼ� �ѱ��
					res = max(res, graph[nx][ny]); // ���ݱ��� ���� �ϼ��� �ִ밪���� ����
					q.push({ nx,ny }); // ������ġ ť�� ����
					--cnt; // ������ �丶�� -1
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) ++cnt; // ������ �丶�� ���� ����

			else if(graph[i][j] == 1) q.push({ i,j }); // ���� �丶�� ��ǥ ť�� ����
		}
	}

	if (cnt == 0) { // �Է� �޾Ҵµ� ������ �丶�䰡 ���ٸ� ������
		cout << 0;
		return 0;
	}

	bfs(); // Ž�� ����

	if(!cnt) cout << res - 1; // ������ �丶�䰡 �������� ������ �ϼ� ���
	else cout << -1; // ������ �丶�䰡 ���Ҵٸ� -1
	return 0;
}