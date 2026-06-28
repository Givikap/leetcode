class Solution {
  public int earliestFinishTime(
      int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
    int earliestLandFinishTime = Integer.MAX_VALUE;
    for (int i = 0; i < landStartTime.length; ++i) {
      earliestLandFinishTime = Math.min(earliestLandFinishTime, landStartTime[i] + landDuration[i]);
    }

    int earliestWaterFinishTime = Integer.MAX_VALUE;
    int earliestFinishTime = Integer.MAX_VALUE;

    for (int i = 0; i < waterStartTime.length; ++i) {
      earliestWaterFinishTime =
          Math.min(earliestWaterFinishTime, waterStartTime[i] + waterDuration[i]);
      earliestFinishTime =
          Math.min(
              earliestFinishTime,
              Math.max(earliestLandFinishTime, waterStartTime[i]) + waterDuration[i]);
    }

    for (int i = 0; i < landStartTime.length; ++i) {
      earliestFinishTime =
          Math.min(
              earliestFinishTime,
              Math.max(earliestWaterFinishTime, landStartTime[i]) + landDuration[i]);
    }

    return earliestFinishTime;
  }
}
