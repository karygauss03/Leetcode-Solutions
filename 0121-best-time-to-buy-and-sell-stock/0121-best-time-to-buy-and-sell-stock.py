class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        min_price = prices[0]
        max_profit = 0

        for price in prices[1:]:
            profit = price - min_price
            if profit > max_profit:
                max_profit = profit
            if price < min_price:
                min_price = price

        return max_profit
