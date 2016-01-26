int reverse(int x) {
        char str[32];
        char *beg, *end, c;
        size_t len;
        long int result;

        len = sprintf(str, "%d", x);
        beg = isdigit(*str) ? str : str + 1;
        end = isdigit(*str) ? beg + len - 1 : beg + len - 2;

        while(beg < end) {
                c = *beg;
                *beg = *end;
                *end = c;
                ++beg;
                --end;
        }

        result = strtol(str, &end, 10);
        if(result > INT_MAX || result < INT_MIN)
                return 0;
        else
                return result;

}

