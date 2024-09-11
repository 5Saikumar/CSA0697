#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value, weight;
};
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}
double knapsack(struct Item arr[], int n, int capacity) {
    qsort(arr, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= capacity) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = knapsack(arr, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}

