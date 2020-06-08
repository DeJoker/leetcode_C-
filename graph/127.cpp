#include "../common/debugger.h"


class Solution {
public:
    bool IsConnected(string& s1, string& s2) {
        int n=s1.size(), diff(0);
        for(int i=0; i<n && diff<2; ++i) {
            if (s1[i] != s2[i])
                ++diff;
        }
        // return diff < 2;
        return diff == 1;
    }

    void ConstructGragh(map<string, vector<string>>& gragh, vector<string>& wordList) {
        for(int i=0; i<wordList.size(); ++i) {
            for(int j=i+1; j<wordList.size(); ++j) {
                if(IsConnected(wordList[i], wordList[j])) {
                    gragh[wordList[i]].push_back(wordList[j]);
                    gragh[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        // 不同于以往我们vector<vector<int>> 当做图，这次是用string去找位置，其实用之前方式也行，i，j下标代表wordList的位置也未尝不可
        map<string, vector<string>> gragh;
        ConstructGragh(gragh, wordList);

        queue<string> Q;
        Q.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);
        int res(1);
        while(!Q.empty()) {
            int n = Q.size();
            // 这里巧妙的一点是不用queue记录当前跳数，而是一次直接把这层的全部弹出，然后++res
            for(int i=0; i<n; ++i) {
                string cur = Q.front(); Q.pop();
                vector<string> neighbors = gragh[cur];
                for(int j=0; j<neighbors.size(); ++j) {
                    if (visited.find(neighbors[j]) == visited.end()) {
                        Q.push(neighbors[j]);
                        visited.insert(neighbors[j]);
                    }
                }
                if (neighbors[i] == endWord)
                    return res+1;
            }
            ++res;
        }
        return 0;
    }
};






class Solution2 {
public:
	bool connect(const string& word1,const string &word2)//判断两个单词是否仅一个字母不同
	{
		int dif=0; //不同的字母数量
		for(int i=0;i<word1.length();i++)
		{
			if(word1[i]!=word2[i]) 
				dif++;
			if(dif>1)
				return false;
		}
		return dif==1;
	 } 
	//构建图,graph必须为引用 
	void construct_graph(string &beginWord,vector<string> &wordList,unordered_map<string,vector<string> > &graph)
	{
		wordList.push_back(beginWord);
		for(int i=0;i<wordList.size();i++)
		for(int j=i+1;j<wordList.size();j++)//避免重复
		{
			if(connect(wordList[i],wordList[j])==true)
			{
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		} 	
	} 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
    	unordered_map<string,vector<string> > graph;
    	construct_graph(beginWord,wordList,graph);
        queue<string> Q;
        unordered_set<string> visit;//记录已经访问过的元素
		Q.push(beginWord); 
		visit.insert(beginWord);
		int result=1;
		while(!Q.empty())
		{
			int size=Q.size();
			for(int i=0;i<size;i++) //每一次循环代表宽度增1 
			{
				string tmp=Q.front();
				Q.pop();
				vector<string> neighbors=graph[tmp]; //邻居们
				for(int i=0;i<neighbors.size();i++)
				{
					if(visit.find(neighbors[i])==visit.end())  //还没加入 
					{
						Q.push(neighbors[i]);
						visit.insert(neighbors[i]);
					}
                    if(neighbors[i]==endWord) return result+1;
				 }			
			} 
            result++;  //遍历一层则+1		
		} 
		return 0;
		 
    }
};



int main() {
    vector<string> vec = {"hot","dot","dog","lot","log","cog"};
    // cout << Solution2().ladderLength("hit", "cog", vec);
    cout << Solution().ladderLength("hit", "cog", vec);
}