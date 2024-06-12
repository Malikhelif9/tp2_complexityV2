#include <stdio.h>

// on declare les compteurs globaux
int counter_iter = 0;
int counter_rec = 0;

// on incrémente un compteur
increment_counter(int *counter) {
    (*counter)++;
}

// Fonction merge modifie
merge(int *t, int l, int mid, int r) {
    int n = mid - l + 1;
    int m = r - mid;
    int *c = (int *)malloc((n + m) * sizeof(int));
    int i = 0, j = 0, k = 0;
    int left[n], right[m];

    for (i = 0; i < n; i++)
        left[i] = t[l + i];
    for (j = 0; j < m; j++)
        right[j] = t[mid + 1 + j];

    printf("Merging [%d, %d] and [%d, %d]\n", l, mid, mid + 1, r);

    i = 0, j = 0, k = 0;
    while (k < n + m) {
        increment_counter(&counter_iter);
        if (i < n && j < m) {
            if (left[i] < right[j]) {
                c[k++] = left[i++];
            } else {
                c[k++] = right[j++];
            }
        } else if (i < n) {
            c[k++] = left[i++];
        } else if (j < m) {
            c[k++] = right[j++];
        }
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        t[i] = c[k];
    }

    printf("Merged [%d, %d] and [%d, %d] into {", l, mid, mid + 1, r);
    for (int i = l; i <= r; i++) {
        printf("%d", t[i]);
        if (i < r) {
            printf(" ");
        }
    }
    printf("}\n");

    free(c);
}


// Fonction merge_sort modifie
merge_sort(int *t, int l, int r) {
    if (l < r) {
        printf("Sorting [%d, %d]\n", l, r);
        increment_counter(&counter_rec); // Incrémentation du compteur de récursions
        int mid = l + (r - l) / 2;
        merge_sort(t, l, mid);
        merge_sort(t, mid + 1, r);
        merge(t, l, mid, r);
        printf("Sorted [%d, %d]\n", l, r);
    }
}
 
