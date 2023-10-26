#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, m;
vvi adj;

int dfs(int x) {
	auto visit = vb(n + 1, false);

	auto st = stack<int>{};
	st.push(x);
	visit[x] = true;

	auto ret = 0;

	while (!st.empty()) {
		auto f = st.top();
		st.pop();
		++ret;

		for (const auto& y : adj[f]) {
			if (visit[y]) {
				continue;
			}

			st.push(y);
			visit[y] = true;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;

	adj = vvi(n + 1, vi{});

	while (0 < (m--)) {
		int a, b;
		cin >> a >> b;

		adj[b].push_back(a);
	}

	auto maxAns = int{ 0 };
	vi ans(n + 1, 0);

	for (auto i = 1; i <= n; ++i) {
		const auto val = dfs(i);
		ans[i] = val;

		if (maxAns < val) {
			maxAns = val;
		}
	}

	for (auto i = 1; i <= n; ++i) {
		if (ans[i] == maxAns) {
			cout << i << ' ';
		}
	}

	return 0;
}