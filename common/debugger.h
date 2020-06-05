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

#include <algorithm>
using namespace std;

#include <cmath>

template<typename Ty>
void DebugVector(vector<Ty>& mm)
{
    cout << "Vector ";
    for (auto& data : mm)
    {
        cout << data << " ";
    }
    cout << endl;
}

template<typename Ty>
void DebugDeque(deque<Ty>& mm)
{
    cout << "Deque ";
    for (auto& data : mm)
    {
        cout << data->val << " ";
    }
    cout << endl;
}

template<typename Ty>
void DebugPlanarVector(vector<vector<Ty>>& data)
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
void DebugPair(pair<Frist, Second>& data)
{
    cout << data.first << " : " << data.second << endl;
}


template<typename Ty1, typename Ty2>
void DebugMap(map<Ty1, Ty2>& mm)
{
    cout << "Debug Map ";
    for (auto& data : mm)
    {
        cout << data.first << " : " << data.second << endl;
    }
}

template<typename Ty>
void DebugSet(set<Ty>& mm)
{
    cout << "Debug Set ";
    for (auto& data : mm)
    {
        cout << data << " " << endl;
    }
}

template<typename Ty1, typename Ty2>
void DebugSet(set<Ty1, Ty2>& mm)
{
    cout << "Debug Set ";
    for (auto& data : mm)
    {
        cout << data << " " << endl;
    }
}

#endif
