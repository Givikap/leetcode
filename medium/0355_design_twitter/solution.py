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
        feeds = []

        if user_id in self.tweets:
            feeds.append((user_id, -1))

        if user_id in self.follows:
            feeds.extend(
                [
                    (followee_id, -1)
                    for followee_id in self.follows[user_id]
                    if followee_id in self.tweets
                ]
            )

        tweets = []

        heap = [
            (*self.tweets[user_id][ri], user_id, ri) for user_id, ri in feeds
        ]
        heapq.heapify(heap)

        for _ in range(10):
            if not heap:
                break

            _, tweet_id, user_id, ri = heapq.heappop(heap)

            tweets.append(tweet_id)

            if len(self.tweets[user_id]) > -ri:
                heapq.heappush(
                    heap, (*self.tweets[user_id][ri - 1], user_id, ri - 1)
                )

        return tweets

    def follow(self, follower_id: int, followee_id: int) -> None:
        if follower_id not in self.follows:
            self.follows[follower_id] = set()

        self.follows[follower_id].add(followee_id)

    def unfollow(self, follower_id: int, followee_id: int) -> None:
        if follower_id in self.follows:
            self.follows[follower_id].remove(followee_id)
