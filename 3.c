#include <stdio.h>

int cost[4+1][5+1];

int knapsack(int n, int W, int wm[], int vm[]) {
  int w, i;
  for(w=0; w<=W; w++) {
    cost[0][w] = 0;
  }

  for(i=0; i<=n; i++) {
    cost[i][0] = 0;
  }

  for(i=1; i<=n; i++) {
    for(w=1; w<=W; w++) {
      if(wm[i] > w) {
        cost[i][w] = cost[i-1][w];
      }
      else {
        if (vm[i]+cost[i-1][w-wm[i]] > cost[i-1][w]) {
          cost[i][w] = vm[i] + cost[i-1][w-wm[i]];
        }
        else {
          cost[i][w] = cost[i-1][w];
        }
      }
    }
  }
  return cost[n][W];
}

int main() {
  // element at index 0 is fake. matrix starting from 1.
  int wm[] = {0, 3, 2, 4, 1};
  int vm[] = {0, 8, 3, 9, 6};
  printf("%d\n", knapsack(4, 5, wm, vm));
  return 0;
}
