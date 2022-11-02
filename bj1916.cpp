#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> d(1001, 2000000002); // �ִ� �Ÿ� ���̺� �����
vector<vector<pair<int, int>>> graph(1001, vector<pair<int, int>>(1001));

void dijkstra(int start, int end){
    priority_queue<pair<int, int>> pq; // �Ÿ�, ��� �ε���
    bool pass = false;

    pq.push({ 0,start }); //���� ���� �������� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����.
    d[start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first; //���� �������� ���
        int now = pq.top().second; // ���� ���
        pq.pop();

        //if (d[now] < dist && now == end) break;

        if (d[now] < dist) continue; // �̹� �ִܰ�θ� üũ�� ����� ��� �н�  

        for (int i = 0; i < graph[now].size(); i++) // �ش� ��忡�� ����� ������ �켱���� ť�� ����
        {
            int cost = dist + graph[now][i].second; // ���ļ� ���� ����� ����� ���
                                                   // ��������� ��� + ���� ��� ���

            if (cost < d[graph[now][i].first]) // ����� �� �۴ٸ� �ִܰ�� ���̺� ���� ����.
            {
                d[graph[now][i].first] = cost;
                pq.push({ -cost, graph[now][i].first });
                if (graph[now][i].first == end) {
                    pass = true;
                    break;
                }
            }
        }
        if(pass) break;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int N, M, start, end, cost;;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        graph[start].push_back({ end, cost });
    }

    cin >> start >> end;

    dijkstra(start, end);

    cout << d[end];

	return 0;
}