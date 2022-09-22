#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

char graph[20][20];
bool alpha[26];
int res = 0, r, c;

int mv1[4] = { -1, 1, 0, 0 };
int mv2[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int cnt) {

	res = max(res, cnt); // �ִ밪 ��ȯ

    for (int i = 0; i < 4; i++) {
        // �� �� �� �� ������ ����

        int nx = x + mv1[i];
        int ny = y + mv2[i];

        if ((nx >= 0 && nx < r) && (ny >= 0 && ny < c)) { // ������ �Ѿ�� ����
			if (alpha[graph[nx][ny] - 'A']) {
				alpha[graph[nx][ny] - 'A'] = false; // dfs ���� �湮ó�� 
				dfs(nx, ny, cnt + 1); // ī��Ʈ ���ָ鼭 �Ѿ��
				alpha[graph[nx][ny] - 'A'] = true; // �ٵ��� �湮ó�� Ǯ��
			} 
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
			alpha[graph[i][j] - 65] = true;
		}
	}

	alpha[graph[0][0] - 'A'] = false; // �湮ó��
	dfs(0, 0, 1);

	cout << res;
	return 0;
}