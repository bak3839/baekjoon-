#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> p(N + 1);
	vector<int> dp(N + 1);

	p[0] = 0;
	dp[0] = 0;
	for (int i = 1;i <= N;i++) cin >> p[i];

	for (int i = 1; i <= N;i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[N];
	return 0;
}