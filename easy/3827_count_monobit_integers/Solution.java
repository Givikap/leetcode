class Solution {
  public int countMonobit(int n) {
    return (int) Math.floor(Math.log(n + 1) / Math.log(2) + 1);
  }
}
