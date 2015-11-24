int bits[64];

void do_bit(unsigned int n)
{   
        for(int i = 0; i < 64; ++i) {
                bits[i] = ((n & 0x01) + bits[i]) % 3;
                n = n >> 1;
        }
        
}

int get_int()
{
        unsigned int n = 0;
        for(int i = 0; i < 64; ++i) {
                if(bits[i])
                        n |= (1UL<<i);
        }
        return n;
}

int singleNumber(int* nums, int numsSize)
{
        for(int i =0; i < 64; ++i) {
            bits[i] = 0;
        }
        for(int i = 0; i < numsSize; ++i) {
                do_bit(nums[i]);
        }

        return get_int();
}