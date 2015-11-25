void merge(int* nums1, int m, int* nums2, int n) {
        int cur;
        int pos1, pos2;

        cur = m + n - 1;
        pos1 = m - 1;
        pos2 = n - 1;

        while(pos1 >= 0 && pos2 >= 0) {
                if(nums1[pos1] >= nums2[pos2])
                        nums1[cur--] = nums1[pos1--];
                else
                        nums1[cur--] = nums2[pos2--];
        }

        //just leave the rest the nums1 alone, they are already sorted
        while(pos2 >= 0)
                nums1[cur--] = nums2[pos2--];
}
