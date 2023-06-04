#include <bits/stdc++.h>
using namespace std;

/*

------------------

5 8
1 420 69 1434 2023

1 2 3 ->
1 6 15 1434 2023

1 2 5 ->
1 6 6 12 7

------------------

*/

int digit_sum(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

void test_case(int& tc) {
	int n, q;
	cin >> n >> q;
	int a[n];
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 9)
			s.insert(i);
	}
	for (int i = 0; i < q; i++) {
		int choice;
		cin >> choice;
		if (choice == 1) {
			int l, r;
			cin >> l >> r; --l; --r;
			int active = l;
			while (!s.empty()) {
				auto it = s.lower_bound(active);
				if (it == s.end() || *it > r)
					break;
				a[*it] = digit_sum(a[*it]);
				int index = *it;
				s.erase(it);
				if (a[index] > 9)
					s.insert(index);
				active = index + 1;
			}
		} else {
			int x;
			cin >> x; --x;
			cout << a[x] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
