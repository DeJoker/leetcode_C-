/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
#include "../common/debugger.h"


// @lc code=start


// 改造为不使用指针并不容易
class Tweet {
private:
    // id为推文内容，time为发文时间
    int content;
    int time;
public:
    Tweet *next;
    bool operator<(const Tweet& b) const {
        return this->time < b.time;
    }

    Tweet() {}
    Tweet(int content, int time) {
        this->content = content;
        this->time = time;
        next = nullptr;
    }
    int getContent() const {
        return this->content;
    }
    int getTime() const {
        return this->time;
    }
};

class User {
private:
    static int timestamp;
    int id;
public:
    list<Tweet> list;  // 发布的Twitter，用链表表示
    unordered_set<int> followed;  // 用户关注了那些人

    bool operator<(const User& b) const {
        return this->id < b.id;
    }
    User() {}

    User(int userId) {
        this->id = userId;
        // 要先把自己关注了
        followed.insert(id);
    }
    void follow(int userId) {
        followed.insert(userId);
    }
    void unfollow(int userId) {
        // 不可以取关自己
        if (userId != this->id)
            followed.erase(userId);
    }
    void post(int contentId) {
        Tweet twt(contentId, timestamp);
        timestamp++;
        // 将新建的推文插入链表头
        // 越靠前的推文 timestamp 值越大
        list.push_front(twt);
    }
};
int User::timestamp = 0;


class Twitter {
private:
    // 映射将 userId 和 User 对象对应起来
    unordered_map<int, User> userMap;
    // 判断该用户存不存在系统中,即userMap中存不存在id
    inline bool contain(int id) {
        return userMap.find(id) != userMap.end();
    }
public:
    Twitter() {
    }

    // user 发表一条 tweet 动态
    void postTweet(int userId, int tweetId) {
        if (!contain(userId))
            userMap[userId] = User(userId);
        userMap[userId].post(tweetId);
    }

    // 返回该 user 关注的人（包括他自己）最近的动态 id，
    // 最多 10 条，而且这些动态必须按从新到旧的时间线顺序排列。
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        if (!contain(userId)) return ret;
        auto cmp = [](list<Tweet>::iterator a, list<Tweet>::iterator b){ return a->getTime()<b->getTime(); };
        priority_queue<list<Tweet>::iterator, vector<list<Tweet>::iterator>, decltype(&cmp)> pq(cmp);
        // 关注列表的用户Id
        unordered_set<int> &users = userMap[userId].followed;
        
        // 先将所有链表头节点插入优先级队列
        for (int id : users) {
            if (!contain(id)) continue;
            if (userMap[id].list.empty()) continue;
            Tweet twt = userMap[id].list.front();
            pq.push(twt);
        }
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            // it.
            ret.push_back(it->getContent());
            if (ret.size() == 10) return ret;  // 最多返回 10 条就够了
            if (++it != )
                pq.push(t->next);
        }
        return ret;
    }

    // follower 关注 followee 
    void follow(int followerId, int followeeId) {
        if (!contain(followerId))
            userMap[followerId] = User(followerId);

        if (!contain(followeeId))
            userMap[followeeId] = User(followeeId);
        
        userMap[followerId].follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (contain(followerId))
            userMap[followerId].unfollow(followeeId);
    }
};



/*

class Tweet {
private:
    // id为推文内容，time为发文时间
    int id;
    int time;
public:
    Tweet *next;
    bool operator<(const Tweet& b) const {
        return this->time < b.time;
    }

    Tweet() {}
    Tweet(int id, int time) {
        this->id = id;
        this->time = time;
        next = nullptr;
    }
    int getId() const {
        return this->id;
    }
    int getTime() const {
        return this->time;
    }
};

class User {
private:
    static int timestamp;
    int id;
public:
    Tweet *head;  // 发布的Twitter，用链表表示
    unordered_set<int> followed;  // 用户关注了那些人

    bool operator<(const User& b) const {
        return this->id < b.id;
    }
    User() {}

    User(int userId) {
        this->id = userId;
        head = nullptr;
        // 要先把自己关注了
        followed.insert(id);
    }
    void follow(int userId) {
        followed.insert(userId);
    }
    void unfollow(int userId) {
        // 不可以取关自己
        if (userId != this->id)
            followed.erase(userId);
    }
    void post(int contentId) {
        Tweet *twt = new Tweet(contentId, timestamp);
        timestamp++;
        // 将新建的推文插入链表头
        // 越靠前的推文 timestamp 值越大
        twt->next = head;
        head = twt;
    }
};
int User::timestamp = 0;


class Twitter {
private:
    // 映射将 userId 和 User 对象对应起来
    unordered_map<int, User> userMap;
    // 判断该用户存不存在系统中,即userMap中存不存在id
    inline bool contain(int id) {
        return userMap.find(id) != userMap.end();
    }
public:
    Twitter() {
    }

    // user 发表一条 tweet 动态
    void postTweet(int userId, int tweetId) {
        if (!contain(userId))
            userMap[userId] = User(userId);
        userMap[userId].post(tweetId);
    }

    //  返回该 user 关注的人（包括他自己）最近的动态 id，
    // 最多 10 条，而且这些动态必须按从新到旧的时间线顺序排列。
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        if (!contain(userId)) return ret;
        priority_queue<Tweet*, vector<Tweet*>> q;
        // 关注列表的用户Id
        unordered_set<int> &users = userMap[userId].followed;
        
        // 先将所有链表头节点插入优先级队列
        for (int id : users) {
            if (!contain(id)) continue;
            Tweet *twt = userMap[id].head;
            if (twt == nullptr) continue;
            q.push(twt);
        }
        while (!q.empty()) {
            Tweet *t = q.top(); q.pop();
            ret.push_back(t->getId());
            if (ret.size() == 10) return ret;  // 最多返回 10 条就够了
            if (t->next)
                q.push(t->next);
        }
        return ret;
    }

    //  follower 关注 followee 
    void follow(int followerId, int followeeId) {
        if (!contain(followerId))
            userMap[followerId] = User(followerId);

        if (!contain(followeeId))
            userMap[followeeId] = User(followeeId);
        
        userMap[followerId].follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (contain(followerId))
            userMap[followerId].unfollow(followeeId);
    }
};

*/
// @lc code=end


int main() 
{
    vector<int> tws;

    Twitter twitter;

    // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    twitter.postTweet(1, 5);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    tws = twitter.getNewsFeed(1);
    DebugVector(tws);

    // 用户1关注了用户2.
    twitter.follow(1, 2);

    // 用户2发送了一个新推文 (推文id = 6).
    twitter.postTweet(2, 6);

    // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
    // 推文id6应当在推文id5之前，因为它是在5之后发送的.
    tws = twitter.getNewsFeed(1);
    DebugVector(tws);

    // 用户1取消关注了用户2.
    twitter.unfollow(1, 2);

    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    // 因为用户1已经不再关注用户2.
    tws = twitter.getNewsFeed(1);
    DebugVector(tws);
}
