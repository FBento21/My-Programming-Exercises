#include <stdio.h>

int print_array(int array[]) {
    printf("[");
    for (int i=0; i < 6; ++i) {
       printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;
}

int swap(int array[], int a, int b) {
    int value_a = array[a];
    int value_b = array[b];

    array[a] = value_b;
    array[b] = value_a;

    return 0;
}

int quicksort(int array[], int size_of_array) {
    int left = 0;
    int pivot = 0;
    int right = size_of_array - 1;

    while (left != right) {
        printf("This is the array[left]: %d\n", array[left]);
        printf("This is the array[right]: %d\n", array[right]);
        printf("This is the array[pivot]: %d\n", array[pivot]);
        printf("-------------------------\n");
        if (pivot == left) {
            if (array[pivot] < array[right]) {
                --right;
            }
            else {
                swap(array, pivot, right);
                ++left;
                pivot = right;
                print_array(array);
            }
        }
        else {
            if (array[pivot] > array[left]) {
                ++left;
            }
            else {
                swap(array, pivot, left);
                --right;
                pivot = left;
                print_array(array);
            }
        }
    }

    return 0;
}


int main() {
    int array[] = {24, 9, 29, 14, 19, 27};
    int size_of_array = sizeof(array)/sizeof(array[0]);
    quicksort(array, size_of_array);
    return 0;
}

