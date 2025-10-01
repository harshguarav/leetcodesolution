class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
         int total = numBottles;
    int empty = numBottles;

    while (empty >= numExchange) {
        int newBottles = empty / numExchange;   // how many new full bottles we can get
        total += newBottles;                   // drink them
        empty = newBottles + (empty % numExchange); // new empty + leftover
    }

    return total;
    }
};