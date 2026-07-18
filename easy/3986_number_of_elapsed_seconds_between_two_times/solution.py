class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        startHours = int(startTime[:2])
        startMinutes = int(startTime[3:5])
        startSeconds = int(startTime[6:])

        endHours = int(endTime[:2])
        endMinutes = int(endTime[3:5])
        endSeconds = int(endTime[6:])

        return (
            3600 * (endHours - startHours)
            + 60 * (endMinutes - startMinutes)
            + (endSeconds - startSeconds)
        )
