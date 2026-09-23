int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * numsSize * sizeof(int));

    *returnSize = 2 * numsSize;

    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
        result[i + numsSize] = nums[i];
    }

    return result;
}