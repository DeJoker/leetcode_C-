#include "../common/debugger.h"

// crash
bool NumStringComp(const string&a, const string& b) {
    if (a == b)
        return false;
    
    if(a.size()<b.size())
        return true;
    return a<b;
}

// this works fine
struct Compare2 {
    bool operator() (const std::string& a, const std::string& b) const{
        if (a == b)
            return false;
        
        if(a.size()<b.size())
            return true;
        return a<b;
    }
};

struct Compare {
    bool operator() (const std::string& a, const std::string& b) const{
        if (a.size() < b.size())
            return true;
        if (a.size() == b.size() && a.compare(b) < 0)
            return true;
        return false;
    }
};

void NewOrder() {
    // set<string, decltype(&NumStringComp)> hset;
    set<string, Compare2> hset;

    hset.insert("3");
    hset.insert("5");
    hset.insert("10");
    hset.insert("10");
    DebugSet(hset);

    set<string> nset;
    nset.insert("3");
    nset.insert("5");
    nset.insert("10");
    nset.insert("10");
    DebugSet(nset);
}

int main() {
    NewOrder();
}
