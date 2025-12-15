class Twitter {
    struct Node{
        int time;
        int tweetId;
        int userID;
        int index;
    };
    struct comp{
        bool operator()(const Node& a,const Node &b)const{
             return a.time<b.time;
        }
    };
    unordered_map<int,unordered_set<int>>following;
    unordered_map<int,vector<pair<int,int>>>tweetsOfUser;
    int cnt;
public:
    Twitter() {
        cnt=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsOfUser[userId].push_back({tweetId,cnt});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>newfeed;
        priority_queue<Node,vector<Node>,comp>pq;
        if(!tweetsOfUser[userId].empty()){
            Node tweetObj;
            tweetObj.time=tweetsOfUser[userId].back().second;
            tweetObj.tweetId=tweetsOfUser[userId].back().first;
            tweetObj.userID=userId;
            tweetObj.index=tweetsOfUser[userId].size()-1;
            pq.push(tweetObj);
        }
        for(auto it:following[userId]){
            int tweetsSize=tweetsOfUser[it].size();
            if(tweetsSize==0)continue;
            Node tweetObj;
            tweetObj.time=tweetsOfUser[it].back().second;
            tweetObj.tweetId=tweetsOfUser[it].back().first;
            tweetObj.userID=it;
            tweetObj.index=tweetsSize-1;
            pq.push(tweetObj);
        }
        while(!pq.empty() && newfeed.size()<10){
            Node temp=pq.top();
            newfeed.push_back(temp.tweetId);
            pq.pop();
            if(temp.index!=0){
                temp.index-=1;
                temp.time=tweetsOfUser[temp.userID][temp.index].second;
                temp.tweetId=tweetsOfUser[temp.userID][temp.index].first;
                pq.push(temp);
            }
        }
        return newfeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId)return;
        following[followerId].erase(followeeId);
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