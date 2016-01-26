int lengthOfLongestSubstring(char* s) {
        char *p1, *p2, *ptrs[128];
        int result;

        if(!(*s))
            return 0;

        memset(ptrs, 0, sizeof(ptrs));
        result = 1;
        for(p1 = p2 = s; *p2; ++p2){
                if(ptrs[*p2]) {
                        if(p2 - p1 > result)
                                result = p2 - p1;
                        p2 = p1 = ptrs[*p2] + 1;
                        memset(ptrs, 0, sizeof(ptrs));
                }
                ptrs[*p2] = p2;
        }
        if(p2 - p1 > result)
            result = p2 - p1;
        
        return result;
}
