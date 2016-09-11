int findDuplicate(int* nums, int numsSize) {
    int fast, slow;
    
    fast = slow = 0;
    do {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);
    
    fast = 0;
    do {
        fast = nums[fast];
        slow = nums[slow];
    } while (fast != slow);
    
    return fast;
}
