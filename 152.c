#define NORMAL 0
#define POS_INV 1
#define NEG_INV 2

int max(int nums[], int numSize, char flags[] ,int filter)
{
        int result = INT_MIN;

        for(int i = 0; i < numSize; ++i) {
                if(flags[i] != filter && nums[i] > result)
                        result = nums[i];
        }

        return result;
}

int maxProduct(int* nums, int numsSize) {
        int max_pos[numsSize], max_neg[numsSize];
        char flags[numsSize];
        char pos_flag;
        int max_product;

        for(int i = 1; i < numsSize; ++i)
                flags[i] = NORMAL;

        if(nums[0] > 0) {
            max_pos[0] = nums[0];
            flags[0] = NEG_INV;
        } else if(nums[0] < 0) {
            max_neg[0] = nums[0];
            flags[0] = POS_INV;
        } else {
            max_neg[0] = max_pos[0] = 0;
        }

        for(int i = 1; i < numsSize; ++i) {
                if(nums[i] > 0) {
                        if(flags[i-1] == POS_INV || max_pos[i-1] == 0)
                                max_pos[i] = nums[i];
                        else
                                max_pos[i] = max_pos[i-1] * nums[i];

                        if(flags[i-1] == NEG_INV)
                                flags[i] = NEG_INV;
                        else
                                max_neg[i] = max_neg[i-1] * nums[i];
                } else if(nums[i] < 0) {
                        if(flags[i-1] == NEG_INV)
                                flags[i] = POS_INV;
                        else
                                max_pos[i] = max_neg[i-1] * nums[i];

                        if(flags[i-1] == POS_INV || max_pos[i-1] == 0)
                                max_neg[i] = nums[i];
                        else
                                max_neg[i] = max_pos[i-1] * nums[i];
                } else {
                        max_neg[i] = max_pos[i] = 0;
                }
        }

        pos_flag = 0; //is positive product possible?
        for(int i = 0; i < numsSize; ++i) {
                if(POS_INV !=  flags[i]) {
                        pos_flag = 1;
                        break;
                }
        }

        if(pos_flag)
                return max(max_pos, numsSize, flags, POS_INV);
        else
                return max(max_neg, numsSize, flags, NEG_INV);
}
