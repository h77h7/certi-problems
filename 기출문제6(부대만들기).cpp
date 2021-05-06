#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;

vector<int> g[MAX_N];
int weights[MAX_N] = { 0 };
int heap[MAX_N] = { 0 };
int heapCount = 0;

void push(int i) {
	heap[++heapCount] = i;
	int child = heapCount;
	int parent = child >> 1;

	while (parent > 0 && weights[heap[parent]] > weights[heap[child]]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}

int pop() {
	int parent = 1;
	int ret = heap[parent];
	heap[parent] = heap[heapCount--];

	int child = parent << 1;
	if (child + 1 <= heapCount) child = weights[heap[child]] < weights[heap[child + 1]] ? child : child + 1;

	while (child <= heapCount && weights[heap[parent]] > weights[heap[child]]) {
		int tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapCount) child = weights[heap[child]] < weights[heap[child + 1]] ? child : child + 1;
	}

	return ret;
}

bool cmp(int a, int b) {
	return weights[a] < weights[b];
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		heapCount = 0;

		int n;
		scanf("%d", &n);
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &weights[i]);
			sum += weights[i];
			if(weights[i] < 0) push(i);
		}

		int a, b;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}

		if (heapCount == 0) {
			printf("#%d %lld\n", t, sum);
			continue;
		}
		
		int idx = pop();
		sum -= weights[idx];
		for (int i = 0; i < g[idx].size(); i++) {
			auto it = find(g[g[idx][i]].begin(), g[g[idx][i]].end(), idx);
			g[g[idx][i]].erase(it);
		}

		while (heapCount) {
			
		}

		return 0;
	}
}
