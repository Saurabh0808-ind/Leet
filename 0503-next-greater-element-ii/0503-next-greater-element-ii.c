int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(numsSize * sizeof(int));
    int* stack = malloc(2 * numsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < numsSize; i++)
        result[i] = -1;

    for (int i = 0; i < 2 * numsSize; i++) {
        int index = i % numsSize;

        while (top >= 0 && nums[index] > nums[stack[top]]) {
            result[stack[top--]] = nums[index];
        }

        if (i < numsSize)
            stack[++top] = index;
    }

    free(stack);
    *returnSize = numsSize;

    return result;
}