#include <stdio.h>

void reverse(int numbers[], int size);
int main(void){
    int numbers[] = {5,4,3,2,1};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    reverse(numbers, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void reverse(int numbers[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap the elements at start and end
        int temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;

        // Move towards the middle
        start++;
        end--;
    }
}