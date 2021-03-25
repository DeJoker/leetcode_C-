
#include "../common/debugger.h"

class A {
public:
    int k;
    string pp;
};



int main() {
    A a;
    a.k=100; a.pp="nimade";

    A b = A(std::move(a));
    return 0;
}
