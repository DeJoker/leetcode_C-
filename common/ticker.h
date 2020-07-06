
#include <chrono>
#include <iomanip>  //std::put_time
#include <iostream>
#include <sstream>

class Timer
{
public:
    Timer() : _begin(std::chrono::high_resolution_clock::now()) 
    {}

    ~Timer() {
        std::cout << elapsed() << std::endl;
    }

    void reset() { 
        _begin = std::chrono::high_resolution_clock::now(); 
    }

    //默认输出毫秒
    int64_t elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

    //微秒
    int64_t elapsed_micro() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

    //纳秒
    int64_t elapsed_nano() const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

    //秒
    int64_t elapsed_seconds() const
    {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

    //分
    int64_t elapsed_minutes() const
    {
        return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

    //时
    int64_t elapsed_hours() const
    {
        return std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now() - _begin).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _begin;
};


std::string GetNowString() {
    // %F   YYYY-MM-DD日期的简写，相当于%Y-%m-%d
    // %T  ISO 8601时间格式 (HH:MM:SS)，相当于%H:%M:%S
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
	time_t raw_time = std::chrono::system_clock::to_time_t(tp);
 
	// tm*使用完后不用delete，因为tm*是由localtime创建的，并且每个线程中会有一个
	struct tm  *timeinfo = std::localtime(&raw_time);
 
	std::stringstream ss;
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S.");
 
	// tm只能到秒，毫秒需要另外获取
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
 
	std::string milliseconds_str = std::to_string(ms.count() % 1000);
 
	if (milliseconds_str.length() < 3) {
		milliseconds_str = std::string(3 - milliseconds_str.length(), '0') + milliseconds_str;
	}
 
	return ss.str() + milliseconds_str;
}

// int main()
// {
//     Timer t; //开始计时
//     std::cout << "hello word" << std::endl;
// }

