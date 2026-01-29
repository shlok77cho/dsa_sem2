#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        
        
            int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == x) {
            return mid; // Element found, return the index
        }
        // If the target is greater than the middle element, ignore the left half
        if (arr[mid] < x) {
            left = mid + 1;
        }
        // If the target is smaller than the middle element, ignore the right half
        else {
            right = mid - 1;
		}
    }
    
    return -1;
}

int main() {
    int n, x;
    
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &x);
    
    int result = binarySearch(arr, n, x);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}