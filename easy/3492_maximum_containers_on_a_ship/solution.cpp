class Solution {
public:
  int maxContainers(int n, int w, int maxWeight) {
    int weight = 0;

    int containers;
    const int maxContainers = n * n;

    for (containers = 0; containers < maxContainers; ++containers) {
      if (weight + w > maxWeight)
        return containers;

      weight += w;
    }

    return containers;
  }
};
