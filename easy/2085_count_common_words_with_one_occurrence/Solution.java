import java.util.HashMap;
import java.util.Map;

class Solution {
  public int countWords(String[] words1, String[] words2) {
    final Map<String, Integer> words1Counter = new HashMap<>();
    for (final String word : words1) {
      words1Counter.put(word, words1Counter.getOrDefault(word, 0) + 1);
    }

    final Map<String, Integer> words2Counter = new HashMap<>();
    for (final String word : words2) {
      words2Counter.put(word, words2Counter.getOrDefault(word, 0) + 1);
    }

    int wordsCount = 0;

    for (final Map.Entry<String, Integer> entry : words1Counter.entrySet()) {
      if (entry.getValue() == 1 && words2Counter.getOrDefault(entry.getKey(), 0) == 1) {
        ++wordsCount;
      }
    }

    return wordsCount;
  }
}
