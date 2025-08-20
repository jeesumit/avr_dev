# avr_dev
#include <stdio.h>
#include <stdlib.h> // Required for qsort()

// Custom comparison function for floats
int compareFloats(const void *a, const void *b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;

    if (fa < fb) {
        return -1; // a is less than b
    } else if (fa > fb) {
        return 1;  // a is greater than b
    } else {
        return 0;  // a and b are equal
    }
}

int main() {
    float val = 0.0;
    float arr[] = {0.50, 1.50, 3.0,1.0,2.5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using qsort()
    // Arguments: base address of the array, number of elements, size of each element, comparison function
    qsort(arr, n, sizeof(float), compareFloats);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        if(i == n - 1){
            continue;
        }
        printf("%.3f | diff: %.2f |", arr[i],arr[i+1]-arr[i]);
        val += (arr[i+1] - arr[i]);
        printf("add: %.2f \n",val);
    }
    printf("\n");

  
