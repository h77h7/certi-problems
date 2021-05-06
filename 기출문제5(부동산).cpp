#include <iostream>

const int MAX_R = 300;

int map[MAX_R+1][MAX_R+1] = { 0 };
int dp[MAX_R+1][MAX_R+1] = { 0 };

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int r, c, l;
		scanf("%d %d %d", &r, &c, &l);

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				scanf("%d", &map[i][j]);
				map[i][j] -= l;
			}
		}


		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
				if (dp[i][j] < map[i][j]) {
					for (int m = j - 1; m <= c; m++) {
						dp[i - 1][m] = 0;
					}
					for (int m = i - 1; m <= r; m++) {
						dp[m][j - 1] = 0;
					}
					dp[i][j] = map[i][j];
				}
			}
		}



	}
}
