#include <stdio.h>

int print_array(int array[], int length) {
    printf("[");
    for (int i=0; i < length; ++i) {
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

int * quicksort(int array[], int size_of_array) {
    int left = 0;
    int pivot = 0;
    int right = size_of_array - 1;

    if (size_of_array == 1) {
        printf("This is just an element!\n");
        print_array(array, 1);

        return 0;
    }

    else if (size_of_array == 2) {
        if (array[0] > array[1]) {
            swap(array, 0, 1);
        }
        printf("This is a simple, ordered subarray!\n");
        print_array(array, 2);

        return 0;
    }
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
                print_array(array, size_of_array);
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
                print_array(array, size_of_array);
            }
        }
    }

    int sub_left_array_size = pivot;
    int sub_right_array_size = size_of_array - pivot - 1;
    printf("This is the size of the sub array left: %d\n", sub_left_array_size);
    printf("This is the size of the sub array right: %d\n", sub_right_array_size);

    int sub_array_left[sub_left_array_size];
    int sub_array_right[sub_right_array_size];

    for (int i = 0; i < sub_left_array_size; ++i) {
        int value = array[i];
        sub_array_left[i] = value;
    }

    for (int i = 0; i < sub_right_array_size; ++i) {
        int value = array[i + pivot + 1];
        sub_array_right[i] = value;
    }

    printf("This is the sub left array: \n");
    print_array(sub_array_left, sub_left_array_size);

    printf("This is the sub right array: \n");
    print_array(sub_array_right, sub_right_array_size);

    if (sub_left_array_size > 0) {
        quicksort(sub_array_left, sub_left_array_size);
    }

    if (sub_right_array_size > 0) {
        quicksort(sub_array_right, sub_right_array_size);
    }
}


int main() {
    int array[] = {24, 9, 29, 14, 19, 27};
    int size_of_array = sizeof(array)/sizeof(array[0]);
    quicksort(array, size_of_array);
    return 0;
}

