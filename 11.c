
#define MIN(a,b) ((a)<(b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
        int max, curr;
        int i, j;

        i = 0;
        j = heightSize - 1;
        max = MIN(height[i], height[j]) * j;
        while(i < j) {
                if(height[i] > height[j])
                        j--;
                else
                        i++;

                curr =  MIN(height[i], height[j]) * (j - i);
                if(curr > max)
                        max = curr;
        }

        return max;
}
