#include "../common/debugger.h"


class UnionFind {
private:
    vector<int>  paraent;
    int count;
    // 以索引为 i 的元素为根结点的树的深度（最深的那个深度）
    vector<int> rank;
public:
    UnionFind(int n) : paraent(n), rank(n) {
        for(int i=0; i<n; ++i) {
            paraent[i] = i;
             // 初始化时，所有的元素只包含它自己，只有一个元素
            rank[i] = 1;
        }
    }
    
    // 返回索引为 p 的元素的根结点
    int Find_RankOptimize(int p) {
        // 跟随链接找到根结点
        while(p != paraent[p]) {
            p = paraent[p];
        }
        return p;
    }
    
    int Find_RankCompress(int p) {
        while(p != paraent[p]) {
            // 整棵树的高度就在一次 find 的过程中被压缩了
            // 其实，一步一跳，两步一跳，甚至三步一跳都没有关系
            paraent[p] = paraent[paraent[p]];
            p = paraent[p];
        }
        return p;
    }

    int Find(int p) {
        return Find_RankCompress(p);
    }
    
    bool IsConnect(int p, int q) {
        int pRoot = Find(p);
        int qRoot = Find(q);
        return pRoot==qRoot;
    }
    
    void Union(int p, int q) {
        int pRoot = Find(p);
        int qRoot = Find(q);
        if (pRoot == qRoot) {
            return;
        }
        
        if(rank[pRoot] > rank[qRoot]) {
            paraent[qRoot] = pRoot;
        } else if (rank[pRoot] < rank[qRoot]) {
            paraent[pRoot] = qRoot;
        } else {
            paraent[qRoot] = pRoot;
            rank[pRoot]++;
        }
        // 每次 union 以后，连通分量减 1
        count--;
    }
};

int main() {
    UnionFind f(3);
}
