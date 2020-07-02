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

#include <algorithm>
using namespace std;

#include <cmath>

template<typename Ty>
void DebugVector(const vector<Ty>& mm)
{
    cout << "Vector ";
    for (auto& data : mm)
    {
        cout << data << " ";
    }
    cout << endl;
}

inline void DumpSeparate() {
    cout << "----------Separate-----------" << endl;
}

template<typename Ty>
void DebugDeque(const deque<Ty>& mm)
{
    cout << "Deque ";
    for (auto& data : mm)
    {
        cout << data->val << " ";
    }
    cout << endl;
}

template<typename Ty>
void DebugPlanarVector(const vector<vector<Ty>>& data)
{
    for (auto& parallel : data)
    {
        cout << "[";
        for (auto& val : parallel)
        {
            cout << val << ",";
        }
        cout << "]" << endl;
    }
}

template<typename Frist, typename Second>
void DebugPair(const pair<Frist, Second>& data)
{
    cout << data.first << " : " << data.second << endl;
}


template<typename Ty1, typename Ty2>
void DebugMap(const map<Ty1, Ty2>& mm)
{
    cout << "Debug Map ";
    for (auto& data : mm)
    {
        cout << data.first << " : " << data.second << endl;
    }
}

template<typename Ty>
void DebugSet(const set<Ty>& mm)
{
    cout << "Debug Set ";
    for (auto& data : mm)
    {
        cout << data << " " << endl;
    }
}

template<typename Ty1, typename Ty2>
void DebugSet(const set<Ty1, Ty2>& mm)
{
    cout << "Debug Set ";
    for (auto& data : mm)
    {
        cout << data << " " << endl;
    }
}

#endif
