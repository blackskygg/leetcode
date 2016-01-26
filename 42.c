int trap(int* height, int heightSize) {
        int sum, curr;
        int i, j;

        i = 0;
        j = heightSize - 1;
        sum = 0;
        while(i < j) {
                if(height[j] > height[i]) {
                        curr = height[i];
                        while(curr >= height[i] && i < j)
                                sum += curr - height[i++];
                } else {
                        curr = height[j];
                        while(curr >= height[j] && i < j)
                                sum += curr - height[j--];

                }
        }

        return sum;
}
