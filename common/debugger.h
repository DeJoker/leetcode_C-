#ifndef __DEBUGGER_H__
#define __DEBUGGER_H__

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <limits.h>

#include <unordered_map>
#include <unordered_set>

#include <future>

#include <functional>
#include <algorithm>
#include "ticker.h"

#include "../util/list_util.h"
#include "../util/create_tree.h"


#include <sstream>
#ifdef __linux
#include <unistd.h>
#include <sys/syscall.h> // gettid().
typedef pid_t thread_id_t;
#else
typedef unsigned int thread_id_t; // MSVC
#endif

thread_local thread_id_t t_tid = 0;
thread_id_t gettid()
{
    if (t_tid == 0)
    {
#ifdef __linux
        t_tid = syscall(__NR_gettid);
#else
        std::stringstream ss;
        // ss << std::this_thread::get_id();
        // ss >> t_tid;
#endif
    }
    return t_tid;
}

// 日志格式
//  +------+-----------+-------+------+------+----------+------+
//  | level | time | thread id | file | line | function | logs |
//  +------+-----------+-------+------+------+----------+------+
#include "simplelog.hpp"
void PrintLogCallback(const char* file, int line, const char* func, int severity, const char* content)
{
    static std::string severityStr[5] = {"Debug", "Info", "Warn", "Error", "Fatal"};
    fprintf(stdout, "[%s %s %d %s(%d) %s] %s \n",
            // severityStr[severity].c_str(), GetUString().c_str(), std::this_thread::get_id(), file, line, func, content); // get_id() 用ld
            severityStr[severity].c_str(), GetUString().c_str(), gettid(), file, line, func, content);
}
static bool callonce = (slog::SetLogCallBack(PrintLogCallback), true);

using namespace std;

#include <cmath>

template<typename Ty>
void DebugVector(const vector<Ty>& mm)
{
    stringstream output;
    for (auto& data : mm)
    {
        output << data << " ";
    }
    LOG_DEBUG << output.str();
}

inline void DumpSeparate() {
    string output;
    output += "----------Separate-----------";
}

template<typename Ty>
void DebugDeque(const deque<Ty>& mm)
{
    stringstream output;
    for (auto it = mm.begin(); it != mm.end(); ++it) {
        output << *it + " ";
    }
    LOG_DEBUG << output.str();

    string out;
    for (auto it = mm.begin(); it != mm.end(); ++it) {
        out += *it + " ";
    }
    LOG_DEBUG << out;
}

template<typename Ty>
void DebugPlanarVector(const vector<vector<Ty>>& data)
{
    string output;
    for (auto& parallel : data)
    {
        output += "[";
        for (auto val : parallel)
        {
            output += to_string(val) + ",";
        }
        output += "]";
    }
    LOG_DEBUG << output;
}

template<typename Frist, typename Second>
void DebugPair(const pair<Frist, Second>& data)
{
    stringstream output;
    output << data.first << " : " << data.second;
    LOG_DEBUG << output.str();
}


template<typename Ty1, typename Ty2>
void DebugMap(const map<Ty1, Ty2>& mm)
{
    stringstream output;
    for (auto& data : mm)
    {
        output << data.first << " : " << data.second;
    }
    LOG_DEBUG << output.str();
}

template<typename Ty>
void DebugSet(const set<Ty>& mm)
{
    stringstream output;
    for (auto& data : mm)
    {
        output << data << " ";
    }
    LOG_DEBUG << output.str();
}

template<typename Ty1, typename Ty2>
void DebugSet(const set<Ty1, Ty2>& mm)
{
    stringstream output;
    for (auto& data : mm)
    {
        output << data + " ";
    }
    LOG_DEBUG << output.str();
}

#endif
