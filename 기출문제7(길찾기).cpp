/***********
��ã��
N : 2<= N <= 1,000
M : 1 <= M <= 1,000
NXN �� �̷ΰ� �����Ѵ�.
�����¿�� �̵��� �� �ְ� �̵��Ϸ��� ���� ���� 0 �̸� �̵� ���� 1 �̸� �̵� �Ұ��� ��
M ���� A, B, C, D �� �־����µ� (A, B)���� (C, D)�� �̵� �����ϸ� 1 �� ���, �̵�
�Ұ����ϸ� 0 �� ����϶�.
(A, B), (C, D)�� ��ǥ ���� 0 ���� �����Ѵ�.
�׽�Ʈ���̽�
2
3 3 �� N M
0 1 0
0 0 1
1 0 0
1 1 3 3
1 1 1 3
2 2 3 2
5 7
1 0 0 0 0
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 0 0 0
1 2 2 2
1 2 2 4
4 1 5 55 1 1 5
1 3 2 5
4 4 5 5
4 5 1 2
���
#1 1 0 1
#2 1 1 1 0 1 1 0
*************/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

short map[MAX_N + 1][MAX_N + 1] = { 0 };
bool visit[MAX_N + 1][MAX_N + 1] = { false };
queue<int> q;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
				map[i][j] = map[i][j] ? 0 : 1;
			}
		}

		printf("#%d ", t);
		int sx, sy, ex, ey;
		for (int i = 0; i < m; i++) {
			bool flag = false;

			scanf("%d %d", &sy,&sx);
			scanf("%d %d", &ey,&ex);

			q.push(sx);
			q.push(sy);
			visit[sy][sx] = true;

			while (!q.empty()) {
				int cx = q.front();	q.pop();
				int cy = q.front(); q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx == ex && ny == ey) {
						printf("1 ");
						while (!q.empty()) q.pop();
						flag = true;
						break;
					}
					if (map[ny][nx] && !visit[ny][nx]) {
						q.push(nx);
						q.push(ny);
						visit[ny][nx] = true;
					}
				}
			}
			if (!flag) {
				printf("0 ");
			}
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					visit[i][j] = false;
				}
			}
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				map[i][j] = 0;
			}
		}
		printf("\n");
	}
}