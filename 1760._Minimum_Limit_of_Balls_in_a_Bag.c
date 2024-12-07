#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int minimumSize(int* nums, int numsSize, int maxOperations) {

    int penalty = 0;
    int i = 0;

    do {
    
        for (int a = 0; a < numsSize; a ++){
            penalty = (nums[a] > penalty)? nums[a] : penalty;
        }
    
        if (i > maxOperations - 1) {
            break;
        }
    
        i++;
        nums = (int*)relloc(i * sizeof(int));
        
        
    
        
    
    
    
        
    }while (i < maxOperations);
    



    return penalty;
}

int main() {

    int* nums= 0;
    int numsSize = 0;
    int maxOperations = 0;


    printf("Enter the maximum number of operations: \n");
    scanf("%i", &maxOperations);

    printf("Enter the num size: \n");
    scanf("%i", &numsSize);

    for (int i = 0; i < numsSize; i ++) {

        printf("Enter your number %i|%i: ", i, numsSize - 1);
        scanf("%i", &nums[i]);

    }

    int result = minimumSize(nums, numsSize,  maxOperations);

    printf("Result: %i", result);


    return 0;
}