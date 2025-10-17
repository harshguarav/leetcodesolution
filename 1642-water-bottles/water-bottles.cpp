class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;  // bottles you can get
            int rem = empty % numExchange;         // remaining empty bottles

            total += newBottles;                   // drink new bottles
            empty = newBottles + rem;              // update empties
        }

        return total;
    }
};
