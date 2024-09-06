#include <stdio.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, leftPair, rightPair;
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    int mid = (low + high) / 2;
    leftPair = findMinMax(arr, low, mid);
    rightPair = findMinMax(arr, mid + 1, high);
    minmax.min = (leftPair.min < rightPair.min) ? leftPair.min : rightPair.min;
    minmax.max = (leftPair.max > rightPair.max) ? leftPair.max : rightPair.max;
    return minmax;
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Pair minmax = findMinMax(arr, 0, n - 1);
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    return 0;
}

