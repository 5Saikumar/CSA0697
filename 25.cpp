#include <stdio.h>
#include <limits.h>
#define MAX 20
#define INF 999999
int n;
int dist[MAX][MAX];
int dp[MAX][1 << MAX]; 
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];  

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If the city is not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Minimum cost of travelling is: %d\n", tsp(1, 0));
    return 0;
}

