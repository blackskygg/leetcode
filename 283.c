void moveZeroes(int* nums, int numsSize) {
        int pos1, pos2;
        int t;

        pos1 = 0;
        for(;;) {
                while(nums[pos1] != 0 &&  pos1 < numsSize)
                        pos1++;

                pos2 = pos1 + 1;
                while(nums[pos2] == 0 && pos2 < numsSize)
                        pos2++;

                if(pos2 >= numsSize)
                        break;

                t = nums[pos2];
                nums[pos2] = nums[pos1];
                nums[pos1] = t;
        }
}
