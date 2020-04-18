#include <iostream>
#include <stack>
#include <queue>
#include <map>
using namespace std;

template<typename Ty1, typename Ty2>
void DebugMap(map<Ty1, Ty2>& mm)
{
    cout << "Debug Map ";
    for (auto data : mm)
    {
        cout << data.first << " : " << data.second << endl;
    }
}

template<typename Frist, typename Second>
void DebugPair(pair<Frist, Second>& data)
{
    cout << "Debug Pair ";
    cout << data.first << " : " << data.second << endl;
}


map<int, int> mmm;
int MakeMap()
{
    mmm[-1] = 1;
    mmm[2] = 5;
    mmm[3] = 1;
    mmm[1] = 6;
    auto iter = mmm.rbegin();
    DebugPair(*iter);
}


int main()
{
    MakeMap();
    
}
