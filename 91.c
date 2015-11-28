int numDecodings(char* s) {
        int prev_len[2] = {1, 1};
        int curr_len[2];
        int t;

        //""
        if(s[0] == '\0')
                return 0;
        //"0", "x"
        if(s[1] == '\0')
                return s[0] == '0' ? 0 : 1;
        //"0x"
        if(s[0] == '0')
                return 0;

        for(int i = 1; s[i] != '\0'; ++i) {
                t = (s[i-1]-'0')*10 + (s[i]-'0');

                //0 is dangerous "...50", "...00"
                if(s[i] == '0' && (t > 20 || t < 10))
                        return 0;

                if(s[i] == '0')
                        curr_len[1] = prev_len[0];
                else if(t > 10 && t <= 26)
                        curr_len[1] = prev_len[1] + prev_len[0];
                else
                        curr_len[1] = prev_len[1];

                curr_len[0] = prev_len[1];

                prev_len[0] = curr_len[0];
                prev_len[1] = curr_len[1];
        }

        return curr_len[1];
}
