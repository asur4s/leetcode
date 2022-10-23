// 设计题，比较脏，抄的。
class Twitter {
public:
    unordered_map<int,unordered_map<int,int>> follow_list;
    vector<pair<int,int>> tweets;
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
        follow_list[userId][userId]=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        for(int i=tweets.size()-1;i>=0;i--){
            if(follow_list[userId].find(tweets[i].first)!=follow_list[userId].end()){
                v.push_back(tweets[i].second);
                if(v.size()>=10) return v;
            }
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        follow_list[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_list[followerId].erase(followeeId);
    }
};