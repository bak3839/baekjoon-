#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> item(101);
vector<int> d(101, 16); // �ִ� �Ÿ� ���̺� �����
vector<vector<pair<int, int>>> graph(101, vector<pair<int, int>>(101));
int n, m, r, res = 0;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq; // �Ÿ�, ��� �ε���

    pq.push({ 0,start }); //���� ���� �������� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //���� �������� ���
        int now = pq.top().second; // ���� ���
        pq.pop();

        if (d[now] < dist || dist > m) continue;

        for (int i = 0; i < graph[now].size(); i++) // �ش� ��忡�� ����� ������ �켱���� ť�� ����
        {
            int cost = dist + graph[now][i].second; // ���ļ� ���� ����� ����� ���
            
            if (cost < d[graph[now][i].first]) // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost, graph[now][i].first });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, start, end, cost;
    cin >> n >> m >> r;

    for (int i = 1;i <= n;i++) cin >> item[i];

    for (int i = 0;i < r;i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
        graph[end].push_back({ start, cost });
    }

    for (int i = 1;i <= n;i++) {
        int sum = 0;
        dijkstra(i);
        for (int j = 1;j <= n;j++) {
            if (d[j] <= m) sum += item[j];
        }
        res = max(res, sum);
        fill(d.begin(), d.end(), 16);
    }

    cout << res;
    return 0;
}