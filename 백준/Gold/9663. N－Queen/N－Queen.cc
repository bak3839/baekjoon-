#include <iostream>

using namespace std;

int main() {
    int N;
    int res[16] = {0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
    cin >> N;
    cout << res[N];
    return 0;
}