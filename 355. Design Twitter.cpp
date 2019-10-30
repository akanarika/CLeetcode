class Twitter {
    deque<int> q;
    unordered_map<int, int> usr;
    unordered_map<int, unordered_set<int>> follows;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        q.push_back(tweetId);
        usr[tweetId] = userId;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        stack<int> s;
        vector<int> v;
        while (!q.empty()) {
            int post = q.back();
            q.pop_back();
            s.push(post);
            if (usr[post] == userId || follows[userId].find(usr[post]) != follows[userId].end()) {
                v.push_back(post);
                if (v.size() == 10) break;
            }
        }
        while (!s.empty()) {
            q.push_back(s.top());
            s.pop();
        }
        return v;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
