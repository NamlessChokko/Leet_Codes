#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

	int diff = 0;
	int* index_numbers = 0;
	int* value_numbers = 0;
    int* return_value = (int* )malloc(2 * sizeof(int));

	for (int i = 0; i < numsSize; i++) {

		printf("Loop i started: i = %i...\n", i);

		diff = target - *(nums + i);

		printf("Diff gets (target - nums[%i])...\n", i);

		// El actual valor de la diferencia se almacena en index y se crea otro espacio de memoria
		index_numbers = (int*)realloc(index_numbers, (i + 1) * sizeof(int));
		*(index_numbers + i) = diff;
		printf("Diff in index hash map: %i\n", *(index_numbers + i));

		// Se guarda el indice actual de num y se crea otro espacio en memoria
		value_numbers = (int*)realloc(value_numbers, (i + 1) * sizeof(int));
		*(value_numbers + i) = nums[i];
		printf("nums[] value in value hash map: %i\n", *(value_numbers + i));

		printf("Values added correctly to hashmap...\n");


		// Verifica si la diferencia es un key o el current value es un valor en el hashmap
		for (int j = 0; j <= i; j++) {

			printf("Loop j started: j = %i...\n\n", j);
			printf("Diff: %i\n", diff);
			printf("Actual index: %i, compared value: %i\n", *(index_numbers + j), *(nums + i));
			printf("Actual value: %i, compared diff: %i\n\n", *(value_numbers + j), diff);

			/*
			El codigo retornara los indexes actuales si:
			    -El numero del array es igual a alguna diferencia
			    -La diferencia actual (target - nums[i]) es igual a algun numero
			*/

			if ( (index_numbers[j] == nums[i] || value_numbers[j] == diff) && j != i) {

				printf("Verification passed: j = %i...\n", j);

				*return_value = i;
				*(return_value + 1) = j;
                printf("Return values: (%i, %i)\n", *(return_value), *(return_value + 1));
				return return_value;

			}

		}

		printf("Loop ended: i = %i\n\n", i);

	}

	for (int i = 0; i < numsSize; i++) {

		printf("[%i] - Index value: %i, Array value: %i\n", i, *(index_numbers + i), *(value_numbers + i));

	}

	// Si no se encuentra solucion, retorna NULL y ajusta returnSize
	*returnSize = 0;
	return NULL;

}



int main (){
    
    int numsSize = 0, target = 0;
    int returnSize[2] = {0};
    int* result = 0;
    

    printf("Enter your target: ");
    scanf("%i", &target);
    
    printf("Enter your array size: ");
    scanf("%i", &numsSize);

    int* numberArray = (int*)malloc(numsSize * sizeof(int)); // Se crea un espacio en memoria para el array de tipo entero

    for (int i = 0; i < numsSize; i++){
        
        printf("Enter your number (%i|%i): ", i, numsSize - 1);
        scanf("%i", &numberArray[i]);
        
    }
    
    result = twoSum(numberArray, numsSize, target, returnSize);
    
    
    printf("\n");
    printf("Result is: (%i, %i)", result[0], result[1]);
    
    
    return 0;
}