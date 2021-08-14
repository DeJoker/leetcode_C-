// #include <vector>
// #include <algorithm>
// #include <functional>

#include <bits/stdc++.h>
using namespace std;

// 一定是单数 1/3/5/7

int Solution(int n, vector<int>& a, vector<int>& b) {
    int more = n/2+1;
    sort(a.begin(), a.end(), std::less<int>());
    sort(b.begin(), b.end(), std::less<int>());

    int win(0);
    for (int i=0; i<n; i++) {
        if (a[i] > b[i]) {
            ++win;
        }

        int totalComptation = i+1; // 总比赛次数
        if (win >= totalComptation/2+1) {
            return totalComptation;
        }
    }
    return -1;
} 