class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        v = prices[0] 
        profit = 0
        
        for value in prices:
            if value < v:
                v = value
            else:
                profit = profit + (value - v)
                v = value
        
        return profit 
                
                