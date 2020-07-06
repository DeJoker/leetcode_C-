#ifndef _SIMPLE_LOG_H__
#define _SIMPLE_LOG_H__

#include <sstream>
#include <iostream>
#include <functional>
#include <string>
#include <string.h>
#include <stdio.h>

/*
** 日志回调函数原型
** @file 日志所在文件
** @line 日志所在代码行
** @func 日志所在函数
** @severity 日志级别
** @context  日志内容
*/
typedef void(*SLogCallBack)(const char* file, int line, const char* func, int severity, const char* content);


/*
** 用于在头文件内生成全局唯一对象
*/
template<typename T>
class GlobalVar {
public:
    static T VAR;
};

template<typename T> T GlobalVar<T>::VAR = nullptr;

/*
** 日志级别
*/
#define MLOG_DEBUG  0
#define MLOG_INFO   1
#define MLOG_WARN   2
#define MLOG_ERROR  3
#define MLOG_FATAL  4

//仅获取文件名
#if defined(WIN32) && !defined(__CYGWIN32__)
#define just_get_name(x) strrchr(x,'\\') ? strrchr(x,'\\')+1 : x
#else
#define just_get_name(x) strrchr(x,'/') ? strrchr(x,'/')+1 : x
#endif

/*
** slog
*/
namespace slog
{
    class LogMessage;

    /*
    ** 日志回调设置函数
    */
    static void SetLogCallBack(SLogCallBack func) { GlobalVar<SLogCallBack>::VAR = func; }
}

/*
** 日志回调生成类
*/
class slog::LogMessage
{
public:
    LogMessage(const char* file, int line, const char* func, int severity, SLogCallBack callback)
        : _file(file)
        , _line(line)
        , _func(func)
        , _severity(severity)
        , _callback(callback)
    {
    }

    ~LogMessage()
    {
        if (_callback)
        {
            std::string content = _stream.str();
            _callback(_file.c_str(), _line, _func.c_str(), _severity, content.c_str());
        }
    }

    std::ostringstream &stream() { return _stream; }

private:
    std::string _file;
    int _line;
    std::string _func;
    int _severity;

    SLogCallBack _callback;
    std::ostringstream _stream;
};

/*
** 实际使用宏
*/
#define LOG_DEBUG slog::LogMessage(just_get_name(__FILE__), __LINE__, __FUNCTION__, MLOG_DEBUG, GlobalVar<SLogCallBack>::VAR).stream()
#define LOG_INFO  slog::LogMessage(just_get_name(__FILE__), __LINE__, __FUNCTION__, MLOG_INFO,  GlobalVar<SLogCallBack>::VAR).stream()
#define LOG_WARN  slog::LogMessage(just_get_name(__FILE__), __LINE__, __FUNCTION__, MLOG_WARN,  GlobalVar<SLogCallBack>::VAR).stream()
#define LOG_ERROR slog::LogMessage(just_get_name(__FILE__), __LINE__, __FUNCTION__, MLOG_ERROR, GlobalVar<SLogCallBack>::VAR).stream()
#define LOG_FATAL slog::LogMessage(just_get_name(__FILE__), __LINE__, __FUNCTION__, MLOG_FATAL, GlobalVar<SLogCallBack>::VAR).stream()

#endif
