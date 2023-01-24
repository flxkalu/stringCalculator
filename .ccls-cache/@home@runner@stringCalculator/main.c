#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Add(const char* numbers) {
    int sum = 0, i = 0, num = 0;
    int negative_numbers[100] = {0};
    int negative_count = 0;
    while(numbers[i] != '\0') {
        if(numbers[i] >= '0' && numbers[i] <= '9') {
            num = (num * 10) + (numbers[i] - '0');
        }
        else if(numbers[i] == ',' || numbers[i] == '\0') {
            if(num < 0) {
                negative_numbers[negative_count] = num;
                negative_count++;
            }
            else if(num <= 1000) {
                sum += num;
            }
            num = 0;
        }
        i++;
    }
    if(negative_count > 0) {
        printf("Negative numbers not allowed : ");
        for(i = 0; i < negative_count; i++) {
            printf("%d ", negative_numbers[i]);
        }
        printf("\n");
        return -1;
    }
    return sum;
}