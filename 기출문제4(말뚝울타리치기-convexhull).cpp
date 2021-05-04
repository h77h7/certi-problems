/*************************
n개의 점들로 convexhull만들고
q개의 점에 대해 convexhull안에 포함되는지 판단 (ccw이용)
*************************/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector<pair<int, int>> points;
stack<pair<int, int>> s;
deque<pair<pair<int, int>,int>> q;

int sx, sy = 9999999999;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	long long m = a.first*b.second + b.first*c.second + c.first*a.second;
	long long n = b.first*a.second + c.first*b.second + a.first*c.second;

	return m - n;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	long long m = 1LL * (a.second - sy) * (b.first - sx);
	long long n = 1LL * (b.second - sy) * (a.first - sx);

	if (m != n) return m < n;
	else {
		return a.second > b.second;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);

		int x, y;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			if (sy > y) {
				sy = y;
				sx = x;
			}
			points.push_back(make_pair(x, y));
		}

		int Q;
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &x, &y);
			q.push_back(make_pair(make_pair(x, y),0));
		}

		sort(points.begin(), points.end(), cmp);

		s.push(points[n-1]);
		s.push(points[0]);
		for (int i = 1; i < n-1; i++) {
			pair<int, int> p2 = s.top();	s.pop();
			pair<int, int> p1 = s.top();
			while (ccw(p1, p2, points[i]) <= 0) {
				p2 = p1;
				s.pop();
				p1 = s.top();
			}
			s.push(p2);
			s.push(points[i]);
		}

		pair<int, int> startPoint;
		startPoint = s.top();
		pair<int, int> cur1;
		pair<int, int> cur2;
		pair<pair<int, int>,int> tmp;
		while (!s.empty()) {
			cur2 = s.top();	s.pop();
			if (s.empty()) {
				cur1 = startPoint;
			}
			else cur1 = s.top();
			tmp = q.front();	q.pop_front();
			int stage = tmp.second;
			while (tmp.second == stage) {
				if (ccw(cur1, cur2, tmp.first) >= 0) q.push_back(make_pair(tmp.first,tmp.second+1));
				tmp = q.front();	q.pop_front();
			}
			q.push_front(tmp);
		}


		printf("#%d %d\n", t, Q - q.size());
	}

	return 0;
}
