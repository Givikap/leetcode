import heapq
from collections import defaultdict
from typing import List


class Twitter:
    def __init__(self):
        self.tweets = defaultdict(list)
        self.follows = defaultdict(set)
        self.time = 0

    def postTweet(self, user_id: int, tweet_id: int) -> None:
        self.tweets[user_id].append((-self.time, tweet_id))
        self.time += 1

    def getNewsFeed(self, user_id: int) -> List[int]:
        heap = []

        if self.tweets[user_id]:
            heap.append(
                (
                    *self.tweets[user_id][-1],
                    user_id,
                    len(self.tweets[user_id]) - 1,
                )
            )

        for followee in self.follows[user_id]:
            if self.tweets[followee]:
                heap.append(
                    (
                        *self.tweets[followee][-1],
                        followee,
                        len(self.tweets[followee]) - 1,
                    )
                )

        heapq.heapify(heap)
        news_feed = []

        while heap and len(news_feed) < 10:
            _, tweet_id, user_id, i = heapq.heappop(heap)
            news_feed.append(tweet_id)

            if i > 0:
                heapq.heappush(
                    heap, (*self.tweets[user_id][i - 1], user_id, i - 1)
                )

        return news_feed

    def follow(self, follower_id: int, followee_id: int) -> None:
        self.follows[follower_id].add(followee_id)

    def unfollow(self, follower_id: int, followee_id: int) -> None:
        self.follows[follower_id].discard(followee_id)
