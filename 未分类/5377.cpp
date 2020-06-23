#include "../common/debugger.h"


class Solution {
public:
    int numSteps(string s) {
        int dec = std::stoi(s, nullptr, 2);
        int step(0);
        while(dec != 1) {
            if (dec%2 == 0) {
                dec /= 2;
            } else {
                ++dec;
            }
            ++step;
        }
        return step;
    }
};

int main() {
    Solution sol;
    cout << sol.numSteps("1101");
}
