// Source : https://leetcode.com/problems/shuffle-the-array/
// Author : Vinícius Brum
// Date   : 30-01-2021

#include <stdio.h>
#include <stdlib.h>

//Embaralha os elementos do array nums
//Ex.: nums = [x1,x2,x3,y1,y2,y3] -> nums embaralhado = [x1,y1,x2,y2,x3,y3]
//Obs.: A função só admite array com um número par de elementos
int* shuffle(int *nums, int numsSize, int n, int *returnSize){
    int *shuffledArray;
    int i,j,k;

    if(numsSize & 1){
        *returnSize = 0;
        return NULL;
    }

    shuffledArray = (int*) malloc(numsSize * sizeof(int));
    if(!shuffledArray){
        printf("Cannot allocate memory.\n");
        *returnSize = 0;
        return NULL;
    }

    j = 0;
    k = n;
    for(i = 0; i < numsSize; i++){
        if(i & 1)   shuffledArray[i] = nums[k++];
        else        shuffledArray[i] = nums[j++];
    }
    *returnSize = numsSize;

    return shuffledArray;
}

void printArray(int *array, int arraySize){
    int i;
    for(i = 0; i < arraySize; i++)  printf("%d ", array[i]);
    printf("\n");
}

void printArrayComparison(int *originalArray, int originalSize, int *shuffledArray, int shuffledSize){
    printf("%20s", "Unshuffled array -> ");
    printArray(originalArray, originalSize);
    printf("%20s", "Shuffled array -> ");
    printArray(shuffledArray, shuffledSize);
    printf("\n");
}


int main(){
    int nums1[] = {1,3,5,2,4,6};
    int nums2[] = {1,2,3,4,4,3,2,1};
    int nums3[] = {1,1,2,2};
    int *result;
    int resultSize;

    printf("First array:\n");
    result = shuffle(nums1, 6, 3, &resultSize);
    printArrayComparison(nums2, 6, result, resultSize);
    free(result);

    printf("Second array:\n");
    result = shuffle(nums2, 8, 4, &resultSize);
    printArrayComparison(nums2, 8, result, resultSize);
    free(result);

    printf("Third array:\n");
    result = shuffle(nums3, 4, 2, &resultSize);
    printArrayComparison(nums2, 4, result, resultSize);
    free(result);

    return 0;
}
