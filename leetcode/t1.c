#include <stddef.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 0; //�޸�ָ���ֵ

    //todo �쳣���
    if (result == NULL || nums == NULL || numsSize <=1){
        return NULL;
    }

    //todo hash�㷨
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}