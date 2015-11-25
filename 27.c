int removeElement(int* nums, int numsSize, int val) {
        int pos1, pos2;
        int t;

        pos1 = 0;
        for(;;) {
                while(nums[pos1] != val &&  pos1 < numsSize)
                        pos1++;

                pos2 = pos1 + 1;
                while(nums[pos2] == val && pos2 < numsSize)
                        pos2++;

                if(pos2 >= numsSize) {
                        //the boundary is dangerous
                        if(pos1 < numsSize && nums[pos1] != val)
                                return pos1 + 1;
                        else
                                return pos1;
                }

                t = nums[pos2];
                nums[pos2] = nums[pos1];
                nums[pos1] = t;
        }

}
