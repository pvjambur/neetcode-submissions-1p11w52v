class Twitter {
private:
    int time = 0;

    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            this->next = nullptr;
        }
    };

    unordered_map<int, Tweet*> userTweets;
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(tweetId, time++);
        newTweet->next = userTweets[userId];
        userTweets[userId] = newTweet;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;

    
        auto cmp = [](Tweet* a, Tweet* b) {
            return a->time < b->time;
        };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        follows[userId].insert(userId);

        for (int followee : follows[userId]) {
            if (userTweets.count(followee)) {
                pq.push(userTweets[followee]);
            }
        }

        while (!pq.empty() && result.size() < 10) {
            Tweet* top = pq.top();
            pq.pop();

            result.push_back(top->id);

            if (top->next) {
                pq.push(top->next);
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};