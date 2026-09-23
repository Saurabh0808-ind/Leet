int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    int j = 0;

    for (int i = 0; i < n; i++) {
        result[j++] = nums[i];
        result[j++] = nums[i + n];
    }

    return result;
}