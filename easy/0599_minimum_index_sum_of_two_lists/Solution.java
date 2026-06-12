import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
  public String[] findRestaurant(String[] list1, String[] list2) {
    final Map<String, Integer> list1Map = new HashMap<>();
    for (int i = 0; i < list1.length; ++i) {
      list1Map.put(list1[i], i);
    }

    int minIndex = Integer.MAX_VALUE;
    final List<String> commonRestaurants = new ArrayList<>();

    for (int i = 0; i < list2.length; ++i) {
      if (list1Map.containsKey(list2[i])) {
        final int currIndex = i + list1Map.get(list2[i]);

        if (currIndex == minIndex) {
          commonRestaurants.add(list2[i]);
        } else if (currIndex < minIndex) {
          minIndex = currIndex;
          commonRestaurants.clear();
          commonRestaurants.add(list2[i]);
        }
      }
    }

    return commonRestaurants.toArray(String[]::new);
  }
}
