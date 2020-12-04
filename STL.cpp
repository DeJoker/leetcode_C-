
#include "common/debugger.h"


void Transform()
{
    vector<int> v1 = {1,3,5,7,9};
    std::transform(v1.begin(), v1.end(), v1.begin(), [](int v) { return ++v; });
    DebugVector(v1);
}


int main()
{
    Transform();
}
