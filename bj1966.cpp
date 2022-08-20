#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int index; // ����
	int imp;   // �߿䵵
}element;

int max_rank(int rank[]) { // ���� ���� �߿䵵 ��ȯ
	for (int i = 9; i > 0; i--) {
		if (rank[i] != 0) {
			rank[i]--;
			return i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue<element> q;
	element tmp;

	int test_case, N, M, num;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int rank[10] = { 0, };
		int index = 0, count = 0;

		cin >> N; // ����� ����
		cin >> M; // ���ϴ� ��ġ
		while (index < N) {
			cin >> num;
			rank[num]++;
			tmp.index = index++;
			tmp.imp = num;
			q.push(tmp);
		}

		while (1) {
			int max = max_rank(rank); // ���� ���� �߿䵵 ��ȯ
			while (q.front().imp != max) { // �� �տ� imp�� max�� �ƴϸ� �ڷ� �̵�
				q.push(q.front());
				q.pop();
			}
			count++; // max�� ��������Ƿ� +1 ���ְ� ���� ���ϴ� ��ġ�� ���̿����� count ���
			if (q.front().index == M) {
				cout << count << "\n";
				break;
			}
			q.pop();
		}
		while (!q.empty()) q.pop();
	}
	return 0;
}