/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include "../common/debugger.h"

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int exp = 1;
        vector<int> buf(n);
        int maxVal = *max_element(nums.begin(), nums.end());

        // 基数排序
        while (maxVal >= exp) {
            vector<int> cnt(10);
            // 当前位的值
            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
};

// @lc code=end


// 注意的一点是桶是count，单次排序后数组是buf
// 第一步是统计每个桶内元素的数量，count存进制该位个数
// 第二步：count就是累加个数的数组，为了下一步给buf赋值，需要累加桶中元素数
// 此时count桶内的值变成buf的下标索引
// 第三步：填一个位置把对应桶的数量缩减一，

// 带注释
class Solution33 {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        //如果数组元素个数小于 2，则返回 0
        if(n < 2)
        {
            return 0;
        }
        vector<int> buf(n);             //buf为临时顺组，用于存储每次排完序的数组
        int maxVal = *max_element(nums.begin(), nums.end());
        int time = maxBit(maxVal);      //计算出需要最高位数，即需要排多少次
        int dev = 1;

        //开始从低位到高位基数排序
        for(int i = 0; i < time; i++){
            vector<int> count(10);      //桶
            //统计每个桶中有多少个数
            for(int j = 0; j < n; j++){
                int digit = (nums[j] / dev) % 10;     //digit 为nums[j]的第i位数
                count[digit] ++;
            }
            //此步是将count[j]由原本表示每个桶的数量，变为表示在数组中的索引
            for(int j = 1; j < 10; j++){
                count[j] += count[j - 1];
            }
            //此步对nums按照低位大小进行排序，(count[digit] - 1)表示排序后nums[j]应该在的位置
            for(int j = n - 1; j >= 0; j--){
                int digit = (nums[j] / dev) % 10;
                buf[count[digit] - 1] = nums[j];
                count[digit] --;
            }
            //将临时数组拷贝给nums
            copy(buf.begin(),buf.end(), nums.begin());
            dev *= 10;
        }
        //找到相邻元素最大差值
        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
    int maxBit(int maxVal){
        int p = 10;
        int d = 1;
        while(maxVal >= p){
            p *= 10;
            d++;
        }
        return d;
    }
};

// 链接：https://leetcode-cn.com/problems/maximum-gap/solution/c-ji-shu-pai-xu-guan-fang-dai-ma-zhu-shi-by-lljj54/



