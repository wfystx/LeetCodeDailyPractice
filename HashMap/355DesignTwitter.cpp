class Tweet{
public:  
    int id, time;
    Tweet* next;
    Tweet(int i, int t): id(i), time(t), next(NULL){}
};
class User{
public:
    int id;
    unordered_set<int> follows;
    Tweet* tweets;
    
    User(){}
    User(int i){
        id = i;
        tweets = NULL;
        follow(i);
    }
    
    void follow(int i){
        follows.insert(i);
    }
    void unfollow(int i){
        follows.erase(i);
    }
    void post(int i, int t){
        Tweets *cur = tweets;
        tweets = new Tweet(i, t);
        tweets->next = cur;
    }
};
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(users.find(userId) == users.end()){
            users[userId] = User(userId);
        }
        users[userId].post(tweetId, time++);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        if (users.find(userId) == users.end()) {
            return feed;
        }
        unordered_set<int> userIds = users[userId].follows;
        priority_queue<Tweet*, vector<Tweet*>, compare> pq;
        for (int userId : userIds) {
            Tweet* tweets = users[userId].tweets;
            if (tweets) {
                pq.push(tweets);
            }
        }        
        int i = 0;
        while (!pq.empty() && i++ < 10) {
            Tweet* tweets = pq.top();
            pq.pop();
            feed.push_back(tweets -> id);
            if (tweets -> next) {
                pq.push(tweets -> next);
            }
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (users.find(followerId) == users.end()) {
            users[followerId] = User(followerId);
        }
        if (users.find(followeeId) == users.end()) {
            users[followeeId] = User(followeeId);
        }
        users[followerId].follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId)!=users.end() && followerId!=followeeId){
            users[followerId].unfollow(followeeId);
        }
    }
private:
    int time = 0;
    unordered_map<int, User> users;
    struct compare {
        bool operator()(const Tweet* l, const Tweet* r) {
            return l -> time < r -> time;
        }
    };
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */