class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int currentEmpty = numBottles;
        while (currentEmpty >= numExchange) {
            ans += currentEmpty / numExchange;
            currentEmpty = currentEmpty / numExchange + currentEmpty % numExchange;
        }
        return ans;
    }
};