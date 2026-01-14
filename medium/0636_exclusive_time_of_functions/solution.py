from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        stack = []
        times = {}

        for log in logs:
            fid, action, ts = log.split(":")

            fid = int(fid)
            ts = int(ts)

            if fid not in times:
                times[fid] = 0

            if action == "start":
                if stack:
                    top = stack[-1]
                    times[top[0]] += ts - top[1]

                stack.append([fid, ts])
            else:
                fid, start_ts = stack.pop()
                times[fid] += ts - start_ts + 1

                if stack:
                    stack[-1][1] = ts + 1

        return [time for _, time in sorted(times.items())]
