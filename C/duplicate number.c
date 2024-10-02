//To find duplicate number:

#include<stdio.h>

int findDuplicate(int* num, int numSize) {
    int count[numSize];
    for (int i = 0; i < numSize; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < numSize; i++) {
        count[num[i]]++;
        if (count[num[i]] > 1) {
            return num[i];
        }
    }
    return -1;
}

int main() {
    int num[] = {1, 3, 4, 2, 2};
    int size = sizeof(num) / sizeof(num[0]);

    int duplicate = findDuplicate(num, size);
    printf("The duplicate number is: %d\n", duplicate);

    return 0;
}
