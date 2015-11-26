#define max(a,b) ((a)>(b)?(a):(b))

int maxProfit(int* prices, int pricesSize) {
        //this array denotes 4 different status
        //namely, +, +-, +-+, +-+-
        //by rearranging the updating order, only one array is needed
        //when update, do it from 3 to 0 so that the dependency won't crash
        int curr[4];
        int result;

        //deal with boundaries, note that maximum can only be 0, +-, +-+-
        curr[0] = -prices[0];
        if(pricesSize <= 1)
                return 0;

        curr[1] = curr[0] + prices[1];
        curr[0] = max(curr[0], -prices[1]);
        if(2 == pricesSize)
                return max(curr[1], 0);

        curr[2] = curr[1] - prices[2];
        curr[1] = max(curr[1], curr[0] + prices[2]);
        curr[0] = max(curr[0], -prices[2]);
        if(3 == pricesSize)
                return max(curr[1], 0);

        curr[3] = curr[2] + prices[3];
        curr[2] = max(curr[2], curr[1] - prices[3]);
        curr[1] = max(curr[1], curr[0] + prices[3]);
        curr[0] = max(curr[0], -prices[3]);
        for(i = 4; i < pricesSize; ++i) {
                curr[3] = max(curr[3], curr[2] + prices[i]);
                curr[2] = max(curr[2], curr[1] - prices[i]);
                curr[1] = max(curr[1], curr[0] + prices[i]);
                curr[0] = max(curr[0], -prices[i]);
        }

        result = max(curr[3], curr[1]);
        return  max(result, 0);
}
