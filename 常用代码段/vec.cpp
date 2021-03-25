#include "../common/debugger.h"

string convertToBase7(int num) {
    string a;
    bool sign(true);
    if (num < 0) {
        num =-num;
        sign = false;
    }
    for(; num; num/=7) {
        int i = num%7;
        a += '0'+i;
    }
    if (!sign)
        a+="-";
    reverse(a.begin(), a.end());
    return a;
}

void Demo() {
    vector<int> ret(100);
    ret.insert(ret.begin()+1, 10);
}

int main() {
    Demo();
    cout << convertToBase7(-32) << endl;
    cout << convertToBase7(101) << endl;
    return 0;
}