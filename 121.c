int maxProfit(int* prices, int pricesSize) {
        int min, max;

        min = -1;
        max = 0;
        for(int i = 0; i < pricesSize; ++i) {
                if(min != -1 && prices[i] - min > max)
                        max = prices[i] - min;

                if(min == -1 || prices[i] < min)
                        min = prices[i];
        }

        return max;
}
