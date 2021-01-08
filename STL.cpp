
#include "common/debugger.h"


void Transform()
{
    vector<int> v1 = {1,3,5,7,9};
    // 记得transform不是引用、是返回值确定当前位置
    std::transform(v1.begin(), v1.end(), v1.begin(), [](int v) { return v+1; });
    DebugVector(v1);

    std::string s("Hello");
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::toupper(c); });

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	LOG_DEBUG << s; // hello
}


void NthElement()
{
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
 
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    LOG_DEBUG << "The median is " << v[v.size()/2];
 
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
    LOG_DEBUG << "The second largest element is " << v[1];
}

void MaxElement()
{
    std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
    std::vector<int>::iterator result;
 
    result = std::max_element(v.begin(), v.end());
    LOG_DEBUG << "max element at: " << std::distance(v.begin(), result);
 
    result = std::max_element(v.begin(), v.end(), [](int a, int b)
        {
            return (std::abs(a) < std::abs(b));
        });
    LOG_DEBUG << "max element (absolute) at: " << std::distance(v.begin(), result);
}


void DiffDemo()
{
    set<string> regDevice{"123","789"};
    set<string> pushDevice{"789", "456"};
    set<string> diffDevice;
    vector<string> diffDevice22;
    set_difference(regDevice.begin(), regDevice.end(), 
        pushDevice.begin(), pushDevice.end(), 
        std::inserter(diffDevice, diffDevice.begin())
    );

    DebugSet(diffDevice);
}


int main()
{
    // MaxElement();

    // string bb("fwefawef");
    // string aa(bb, 0, 1);
    // LOG_DEBUG << aa;
    // aa.pop_back();


    int dp[100][100];
    LOG_DEBUG << sizeof(int);
    LOG_DEBUG << sizeof(dp);

    DiffDemo();

    // Transform();
    // NthElement();
}
