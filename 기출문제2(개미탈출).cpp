/*******************
map을 사용해서 충돌하는 개미 체크
********************/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;
const int dx[5] = { 0,0,0,-1,1 };
const int dy[5] = { 0,1,-1,0,0 };

int ants[MAX_N + 1][3] = { 0 };
int outAnts[MAX_N] = { 0 };

bool cmp(int i, int j) {
	return ants[i][1] < ants[j][1];
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &ants[i][0], &ants[i][1], &ants[i][2]);
		}
		int cnt = 0;
		int time = 0;
		while (cnt < k) {
			time++;
			int outIdx = 0;
			map<unsigned long long, int> antMap;
			for (int i = 1; i <= n; i++) {
				if (ants[i][0] <= m && ants[i][1] <= m && ants[i][0] > 0 && ants[i][1] > 0) {
					ants[i][0] += dx[ants[i][2]];
					ants[i][1] += dy[ants[i][2]];
					unsigned long long grid = (unsigned long long)ants[i][0] * 1000000000 + ants[i][1];

					if (ants[i][0] == m) {	//탈출하는 개미 체크
						outAnts[outIdx++] = i;
					}
					else if (antMap[grid]) {
						int tmp = ants[i][2];
						ants[i][2] = ants[antMap[grid]][2];
						ants[antMap[grid]][2] = tmp;
					}
					else {
						antMap[grid] = i;
					}
				}
			}
			sort(outAnts, outAnts + outIdx, cmp);
			for (int i = 0; i < outIdx; i++) {
				cnt++;
				if (cnt == k) {
					printf("#%d %d %d\n", t, time, outAnts[i]);
					return 0;
				}
			}
		}
	}
	return 0;
}
