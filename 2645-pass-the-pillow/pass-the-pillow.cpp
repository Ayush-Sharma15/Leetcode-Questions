class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the effective time within one complete cycle
        int cycle_length = 2 * (n - 1);
        int effective_time = time % cycle_length;
        
        // Determine the position of the pillow based on the effective time
        if (effective_time < n) {
            // Moving forward
            return 1 + effective_time;
        } else {
            // Moving backward
            return n - (effective_time - (n - 1));
        }
    }
};
