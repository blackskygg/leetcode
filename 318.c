int maxProduct(char** words, int wordsSize) {
        unsigned int bitmap[wordsSize];
        unsigned int bitmask[26];
        size_t lens[wordsSize];
        size_t max;
        char *curr;

        /* initialize the bitmask array */
        bitmask[0] = 1;
        for(int i = 1; i < 26; ++i)
                bitmask[i] = bitmask[i - 1] << 1;

        for(int i = 0; i < wordsSize; ++i) {
                bitmap[i]  = 0;
                for(curr = words[i]; '\0' != *curr; ++curr) {
                        bitmap[i] |= bitmask[*curr - 'a'];
                }
                lens[i] = curr - words[i];
        }

        max = 0;
        for(int i = 0; i < wordsSize; ++i) {
                for(int j = i + 1; j <wordsSize; ++j) {
                        if(!(bitmap[i] & bitmap[j]) && lens[i] * lens[j] > max)
                                max = lens[i] * lens[j];
                }
        }

        return max;
}
