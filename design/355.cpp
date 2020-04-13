#include "../common/debugger.h"

class Twitter {
    map<int, set<int>> _toFollowers;
    map<int, set<int>> _toFollowees;
    map<int, deque<int>> _msgs;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto listens = _toFollowers[userId];
        for(auto& followee : listens) {
            auto& msgQueue = _msgs[followee];
            if (msgQueue.size() == 10)
                msgQueue.pop_front();
            msgQueue.push_back(tweetId);
        }
        auto& msgSelf = _msgs[userId];
        if (msgSelf.size() == 10)
            msgSelf.pop_front();
        msgSelf.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        auto& feed = _msgs[userId];
        vector<int> ret = { feed.begin(), feed.end() };
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
    Twitter tw;
    tw.postTweet(1, 2);
    DebugVecor(tw.getNewsFeed(1));
    return 0;
}