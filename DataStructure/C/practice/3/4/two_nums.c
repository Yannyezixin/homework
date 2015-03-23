#include "two_nums.h"
#include <stdio.h>

enum status two_nums(int arr[], int size, int sum, pair *p)
{
    int i, hash[SIZE];
    if (0 == size) return P_FALSE;

    for (i = 0; i < size; i++) hash[arr[i]] = 1;

    for (i = 0; i < size; i++) {
        if (hash[sum - arr[i]] == 1 && arr[i] != sum - arr[i]) {
            p->x = arr[i];
            p->y = sum - arr[i];
            return P_OK;
        }
    }

    return P_FALSE;
}

