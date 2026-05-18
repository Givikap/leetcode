import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
  public boolean canReach(int[] arr, int start) {
    final int n = arr.length;

    final boolean[] visited = new boolean[n];

    final Deque<Integer> s = new ArrayDeque<>();
    s.push(start);

    while (!s.isEmpty()) {
      final int i = s.pop();

      visited[i] = true;

      if (arr[i] == 0) {
        return true;
      }

      final int leftI = i + arr[i];
      final int rightI = i - arr[i];

      if (leftI < n && !visited[leftI]) {
        s.push(leftI);
      }
      if (rightI > -1 && !visited[rightI]) {
        s.push(rightI);
      }
    }

    return false;
  }
}
