#include "common/debugger.h"

int main() {
    int a(21), b(3), c(6);
    // set<pair<char, int>, [](pair<char, int> arg1, pair<char, int> arg2){
    //     return arg1.second > args.second;
    // }> sset;
    set<pair<char, int>, std::less<>> sset;
    rbegin(sset);
    sset
}
