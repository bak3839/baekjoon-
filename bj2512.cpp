#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> req; // ��û�ݾ��� ���� �迭
	int N, num, sum, budget, res = 0, low, high = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		req.push_back(num);
		high = max(num, high); // ���� ū ��û �׼�
	}

	cin >> budget; // �� �����

	low = budget / N;
	int mid;

	while (low <= high) {
		sum = 0;
		mid = (low + high) / 2;

		for (int i = 0; i < req.size(); i++) { 
			sum += min(mid, req[i]); // ���Ѿװ� ��û�׼��� ���Ͽ� �ּҰ� sum�� ���ϱ�
		}

		if (sum > budget) high = mid - 1; // ���꺸�� �ջ���� ũ�� high�� ���߱�

		else { // ���꺸�� �ջ���� ������ low����
			low = mid + 1;
			res = max(mid, res); // res�� mid�� ���Ͽ� �� ū ���Ѿ� ����
		}
	}

	cout << res;
	return 0;
}