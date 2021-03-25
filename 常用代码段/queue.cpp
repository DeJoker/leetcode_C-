#include <queue>
using namespace std;


void QueueDemo()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.pop();
    q.push(9);
}

int main()
{
    QueueDemo();
    return 0;
}
