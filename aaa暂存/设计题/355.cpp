#include "../common/debugger.h"

// 有一点没有考虑到，取关就不能看到消息了
// 倒叙看推文
// 自己发的也能看到
// 关注前发的也要能看到

// 
// 基于当前设计，queue要存储全部消息，用关注者做过滤器
// queue维护全部
// 


// Bug:
class Twitter {
    map<int, set<int>> _toFollowers;
    map<int, set<int>> _toFollowees;
    map<int, deque<pair<int, int>>> _msgs;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        _toFollowers[userId].insert(userId);
        _toFollowees[userId].insert(userId);
        auto listens = _toFollowers[userId];
        auto msg = make_pair(userId, tweetId);
        for(auto& followee : listens) {
            auto& msgQueue = _msgs[followee];
            // if (msgQueue.size() == 10)
            //     msgQueue.pop_front();
            msgQueue.push_back(msg);
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto& feed = _msgs[userId];
        // 要使用倒叙的，跟时间相关
        vector<int> ret;
        for(auto it=feed.rbegin(); it != feed.rend(); ++it) {
            if (_toFollowees[userId].find(it->first) != _toFollowees[userId].end())
                ret.push_back(it->second);
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        _toFollowees[followerId].insert(followeeId);
        _toFollowers[followeeId].insert(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        _toFollowees[followerId].erase(followeeId);
        _toFollowers[followeeId].erase(followerId);
    }
};


int main()
{
    // Twitter tw;
    // tw.postTweet(1, 2);
    // tw.follow(1, 2);
    // tw.postTweet(2, 6);
    // DebugVecor(tw.getNewsFeed(1));

    // vector<int> ret;
    // cout << *ret.begin() << endl;
    // stack<int> st;
    // cout << st.top() << endl;
    queue<int> one;
    // one.front
    return 0;
}