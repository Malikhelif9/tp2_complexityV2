#include <stdio.h>
#include <stdlib.h>



increment_counter(int *counter);
merge(int *t, int l, int mid, int r);
merge_sort(int *t, int l, int r);


int main() {

    int t[] =  {5, 4, 3, 2, 1};
    int size = sizeof(t) / sizeof(t[0]);

    printf("Original array : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    merge_sort(t, 0, size - 1);

    printf("Sorted array : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}
