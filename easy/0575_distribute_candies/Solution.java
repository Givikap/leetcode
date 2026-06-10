import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
  public int distributeCandies(int[] candyType) {
    return Math.min(
        Arrays.stream(candyType).boxed().collect(Collectors.toSet()).size(), candyType.length);
  }
}
