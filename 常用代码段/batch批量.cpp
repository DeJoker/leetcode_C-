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




void TestBatchAlgo() {
    set<int> cids;
    for(int i=0; i<99; ++i)
    {
        BatchAlgo(cids);
        DumpSeparate();
        cids.insert(i);
    }
    BatchAlgo(cids);
}






template<typename ContainerParam>
//process 需是左开右闭的处理
void GradingRangeProcess(const ContainerParam& container, const std::function<void(typename ContainerParam::iterator&, typename ContainerParam::iterator&)> process, const uint32_t grade)
{
    if (container.empty()) {
        return;
    }
    auto startIter = container.begin();
    auto endIter(startIter);
    int endPos(0);
    do {
        // end再往后挪grade个位置直至到达容器末端
        endPos = std::min(endPos+grade, (uint32_t)container.size());
        endIter = std::next(container.begin(), endPos);
        // 保证process会移动startIter到endIter的位置
        process(startIter, endIter);
        startIter = endIter;
    } while(endPos != container.size());

}

void CheckGradingRangeProcess(set<int>::iterator& begin, set<int>::iterator& end) {
    // cout << *begin << ":" << *(end-1);
    cout << *begin;
    while(begin != end) {
        ++begin;
    }
    auto xx = begin;
    cout << ":" << *(--begin) <<endl;

}

void TestGradingRangeProcess() {
    set<int> cids;
    for(int i=0; i<99; ++i)
    {
        GradingRangeProcess(cids, CheckGradingRangeProcess, 10);
        DumpSeparate();
        cids.insert(i);
    }
    GradingRangeProcess(cids, CheckGradingRangeProcess, 10);
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
}





int main() {
    // stdNextDemo();
    // TestBatchAlgo();
    TestGradingRangeProcess();
}