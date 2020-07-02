#include "../common/debugger.h"

void BatchAlgo(set<int>& cids, uint32_t aggregation = 10)
{
    if (cids.empty()) {
        return;
    }
    vector<int> batch;
    auto startIter = cids.begin();
    auto endIter(startIter);
    int endPos(0);
    do {
        // end再往后挪aggregation个位置直至到达容器末端
        endPos = std::min(endPos+aggregation, (uint32_t)cids.size());
        endIter = std::next(cids.begin(), endPos);
        while(startIter != endIter) {
            batch.push_back(*startIter);
            ++startIter;
        }
        cout << batch.front() <<":"<< batch.back() <<endl;
        batch.clear();
    } while(endPos != cids.size());

}


int stdNextDemo() {
    set<int> cids;
    for(int i=0; i<99; ++i)
    {
        cids.insert(i);
    }
    // BatchAlgo(cids);
    auto xx = std::next(cids.begin(), 507);
    if (xx == cids.end()) {
        cout << "nimade" <<endl;
    } else {
        cout << "valid," << *xx << endl;
    }

    xx = std::next(cids.begin(), 1099);
    if (xx == cids.end()) {
        cout << "nimade" <<endl;
    } else {
        cout << "valid," << *xx << endl;
    }

    xx = std::next(cids.begin(), 1010); // 这个为什么是合法的。。。
    if (xx == cids.end()) {
        cout << "nimade" <<endl;
    } else {
        cout << "valid," << *xx << endl;
    }

    xx = std::next(cids.begin(), cids.size());
    if (xx == cids.end()) {
        cout << "nimade" <<endl;
    } else {
        cout << "valid," << *xx << endl;
    }

    xx = std::next(cids.begin(), cids.size()-1);
    if (xx == cids.end()) {
        cout << "nimade" <<endl;
    } else {
        cout << "valid," << *xx << endl;
    }

    BatchAlgo(cids);
}





int main() {
    stdNextDemo();
}