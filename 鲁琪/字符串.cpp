
#include "../common/debugger.h"



string Convert(string a, int del) {
    map<char, int> mapCnt;
    for(int i=0; i<a.size(); i++) {
        mapCnt[a[i]]++;
    }

    while(del) {
        if (mapCnt.empty()) {
            return "";
        } 
        mapCnt.erase(mapCnt.begin());
        --del;
    }

    string ret;
    for(int i=0; i<a.size(); i++) {
        if (mapCnt.find(a[i]) != mapCnt.end()) {
            ret.push_back(a[i]);
        }
    }
    return ret;
}

int main() {
    cout << Convert("caabeefa", 2) << endl;
    cout << Convert("caabeefa", 100) << endl;
}


