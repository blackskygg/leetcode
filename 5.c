char* longestPalindrome(char* s) {
        char *left, *right, *mid;
        char *max_left, *max_right;
        char *result;
        int max, len;;

        max = 0;
        for(mid = s; *mid; ++mid) {
                left = mid - 1;
                right = mid + 1;
                len = 1;
                while(left >= s && *right && *right == *left) {
                        left--;
                        right++;
                        len += 2;
                }

                if(len > max) {
                        max = len;
                        max_left = left + 1;
                        max_right = right - 1;
                }

                left = mid;
                right = mid + 1;
                len = 0;
                while(left >= s && *right && *right == *left) {
                        left--;
                        right++;
                        len += 2;
                }

                if(len > max) {
                        max = len;
                        max_left = left + 1;
                        max_right = right - 1;
                }
        }

        *(max_right+1) = 0;
        return max_left;
}
