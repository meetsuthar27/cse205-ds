class Twitter {
public:

    map<int,map<int,int>> user_follow;
    map<int,map<int,int>> posts;
    int post_cnt = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId][post_cnt++] = tweetId;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for(auto it = posts[userId].begin(); it != posts[userId].end(); it++)
        {
            pq.push(make_pair(it->first,it->second));
        }


        for(auto it = user_follow[userId].begin(); it != user_follow[userId].end(); it++)
        {
            for(auto it2 = posts[it->first].begin(); it2 != posts[it->first].end(); it2++)
            {
                pq.push(make_pair(it2->first,it2->second));
            }
        }

        vector<int> ans;

        int i = 0;

        while(i < 10 && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(user_follow[followerId][followeeId] == 1) return;

        user_follow[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        user_follow[followerId].erase(followeeId);
    }
};
