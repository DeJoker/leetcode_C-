#include "../common/debugger.h"





int main()
{
    vector<int> p, r;
    p={1,3,-1,-3,5,3,6,7};
    // r = maxSlidingWindow(p, 3);
    DebugVector(r);

    p={1,3,1,2,0,5};
    r = maxSlidingWindow(p, 3); // debugqueue 3.    3 1.    2.   2 0
    DebugVector(r);
}

