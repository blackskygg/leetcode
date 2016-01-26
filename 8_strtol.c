int myAtoi(char* str) {
        long int result = strtol(str, NULL, 10);

        if(result > INT_MAX)
                return INT_MAX;
        else if(result < INT_MIN)
                return INT_MIN;
        else
                return result;
}
