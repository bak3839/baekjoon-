#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<ll> dp(N + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N;i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N];
	return 0;
}