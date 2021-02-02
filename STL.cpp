
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

    // DiffDemo();

    // Transform();
    // NthElement();

    vector<int> xx{1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(xx, 3);
}




vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size());
    // 这里放元素索引，而不是元素
    stack<int> s; 
    /* 单调栈模板 */
    for (int i = T.size() - 1; i >= 0; i--) {
        while (!s.empty() && T[s.top()] <= T[i]) {
            s.pop();
        }
        // 得到索引间距
        res[i] = s.empty() ? 0 : (s.top() - i); 
        // 将索引入栈，而不是元素
        s.push(i); 
    }
    return res;
}
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;
    // 假装这个数组长度翻倍了
    for (int i = 2 * n - 1; i >= 0; i--) {
        // 索引要求模，其他的和模板一样
        while (!s.empty() && s.top() <= nums[i % n])
            s.pop();
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    return res;
}


vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size()); // 存放答案的数组
    stack<int> s;
    // 倒着往栈里放
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 判定个子高矮
        while (!s.empty() && s.top() <= nums[i]) {
            // 矮个起开，反正也被挡着了
            s.pop();
        }
        // nums[i] 身后的 next great number
        res[i] = s.empty() ? -1 : s.top();

        s.push(nums[i]);
    }
    return res;
}





class MonotonicQueue {
private:
public:
    deque<int> data;
    void push(int n) {
        // 队尾添加元素，但是要把前面比新元素小的元素都删掉
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }

    int max() { return data.front(); }

    void pop(int n) {
        // 
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先把窗口的前 k - 1 填满
            window.push(nums[i]);
        } else { // 窗口开始向前滑动
            DebugDeque(window.data);

            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
            // nums[i - k + 1] 就是窗口最后的元素
        }
    }
    return res;
}

