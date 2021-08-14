

#include "../common/debugger.h"


// 单数从下面开始； 双数从上面开始
vector<int> Fertilizer2(int ground, int count) {
    int mean = count/ground;
    vector<int> res(ground, mean); // ground个mean的数组

    int remain = count - mean*ground;
    int i, direct(0);
    if (mean%2 == 1) {
        i = ground-2;
        direct = -1;
    } else {
        i = 1;
        direct = 1;
    }

    while(remain) {
        res[i]++;
        i += direct;
        --remain;
    }
    return res;
}


vector<int> Fertilizer(int ground, int count) {
    int mean = count/ground;
    vector<int> res(ground, mean); // ground个mean的数组

    int remain = count - mean*ground;
    int i, direct(0);

    // 1是倒，2是顺
    int loop = (count - ground)/(ground-1);
    if (loop%2 == 1) {
        i = ground-2;
        direct = -1;
    } else {
        i = 1;
        direct = 1;
    }

    while(remain) {
        res[i]++;
        i += direct;
        --remain;
    }
    return res;
}

    // vector<int> kk (2, 5); // 两个5
    // DebugVector(kk);

    // res = Fertilizer2(2, 5);  // 有误
    // DebugVector(res);

int main() {
    vector<int> res;

    // 样例
    res = Fertilizer(2, 5);
    DebugVector(res);
    res = Fertilizer(4, 6);
    DebugVector(res);

    // 自测
    res = Fertilizer(2, 7);
    DebugVector(res);
    res = Fertilizer(2, 9);
    DebugVector(res);
    res = Fertilizer(3, 5);
    DebugVector(res);


}

