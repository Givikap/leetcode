import heapq
from typing import List


class Twitter:
    def __init__(self):
        self.tweets: dict[int, list[tuple[int, int]]] = {}
        self.follows: dict[int, set] = {}
        self.time = 0

    def postTweet(self, user_id: int, tweet_id: int) -> None:
        if user_id not in self.tweets:
            self.tweets[user_id] = []

        self.tweets[user_id].append((self.time, tweet_id))
        self.time += 1

    def getNewsFeed(self, user_id: int) -> List[int]:
        tweets = []

        if user_id in self.tweets:
            tweets.extend(self.tweets[user_id])

        if user_id in self.follows:
            for followee_id in self.follows[user_id]:
                if followee_id in self.tweets:
                    tweets.extend(self.tweets[followee_id])

        return [tweet_id for _, tweet_id in heapq.nlargest(10, tweets)]

    def follow(self, follower_id: int, followee_id: int) -> None:
        if follower_id not in self.follows:
            self.follows[follower_id] = set()

        self.follows[follower_id].add(followee_id)

    def unfollow(self, follower_id: int, followee_id: int) -> None:
        if follower_id in self.follows:
            self.follows[follower_id].remove(followee_id)
