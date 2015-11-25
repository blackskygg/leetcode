#define max(a,b) ((a)>(b)?(a):(b))

int maxProfit(int* prices, int pricesSize) {
        int prev_0, prev_1;
        int curr_0, curr_1;

        prev_0 = 0;
        prev_1 = -prices[0];

        for(int i = 1; i < pricesSize; ++i) {
                curr_0 = max(prev_0, prev_1 + prices[i]);
                curr_1 = max(prev_1, prev_0 - prices[i]);

                prev_0 = curr_0;
                prev_1 = curr_1;
        }

        return curr_0;
}
