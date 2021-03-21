#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;







class Tweet {
public:
    int content;
    int time;

    Tweet(int cont, int t) {
        this->content = cont;
        this->time = t;
    }
};


class User {
public:
    int id;
    set<int> followings;
    list<Tweet> tweets;
    
    User(int i) {
        id = i;
    }
};


class Twitter {
    list<Tweet> _tw;
    map<int, User> _ur;
    int _timestamp = 0;

    /** user 发表一条 tweet 动态 */
    void postTweet(int userId, int tweetId) {
        ++_timestamp;
        Tweet t(tweetId, _timestamp);
        _tw.push_back(t);
    }
    
    /** 返回该 user 关注的人（包括他自己）最近的动态 id，
    最多 10 条，而且这些动态必须按从新到旧的时间线顺序排列。*/
    vector<int> getNewsFeed(int userId) {

    }
    
    /** follower 关注 followee，如果 Id 不存在则新建 */
    void follow(int followerId, int followeeId) {
        if (_ur.find(followerId) == _ur.end()) {
            User u(followerId);

        }
    }
    
    /** follower 取关 followee，如果 Id 不存在则什么都不做 */
    void unfollow(int followerId, int followeeId) {}
};

