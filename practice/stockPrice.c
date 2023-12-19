// Input array of integers representing daily stock prices of a company.
// create function that return max profit obtained from buying and selling one piece of shares.
// buying n selling not on the same day.
#include <stdio.h>

int maxProfit(int prices[], int n) {
    if (n <= 1) {
        return 0; // If there are fewer than two prices, no profit can be obtained.
    }

    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < n; i++) {
        int currentProfit = prices[i] - minPrice;

        // Update maxProfit if the current profit is greater
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }

        // Update minPrice if the current price is smaller
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
    }

    return maxProfit;
}

int main() {
    // Example usage
    int prices[] = {7, 1, 5, 3, 10, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n);

    printf("Maximum profit: %d\n", result);

    return 0;
}
