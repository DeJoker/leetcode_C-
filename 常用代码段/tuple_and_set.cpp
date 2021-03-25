#include "../common/debugger.h"


bool edge_compare(const tuple<int, int>& t1, const tuple<int, int>& t2)
{
    // remove the repeated
    if (get<0>(t1) == get<1>(t2) && get<1>(t1) == get<0>(t2)) {
        // (1, 2) == (2, 1)
        return false;
    }
 
    // sort by ascend
    if (get<0>(t1) == get<0>(t2)) {
        // (1, 1), (1, 2), (1, 3)
        return get<1>(t1) < get<1>(t2);
    }
    // (1, 2), (3, 2), (5, 9)
    return get<0>(t1) < get<0>(t2);
}
 
void myfunc(tuple<int, int> i)
{
    std::cout << ' ' << get<0>(i) << ' ' << get<1>(i) << std::endl;
}
 
int main()
{
    set<tuple<int, int>, decltype(&edge_compare)> edge_set(&edge_compare);
    edge_set.insert(make_tuple(2, 3));
 
    edge_set.insert(make_tuple(1, 2));
    edge_set.insert(make_tuple(2, 1));
    cout << (edge_set.insert(make_tuple(2, 1)).second ? "true" : "false") << endl;
 
    edge_set.insert(make_tuple(2, 3));

    for_each(edge_set.begin(), edge_set.end(), myfunc);
    return 0;
}
