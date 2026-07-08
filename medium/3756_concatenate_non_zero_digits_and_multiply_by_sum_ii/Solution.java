class Solution {
  public int[] sumAndMultiply(String s, int[][] queries) {
    final int n = s.length();

    final long mod = 1_000_000_007;
    final long inv10 = 700_000_005;

    final long[] pow10 = new long[n + 1];
    pow10[0] = 1L;
    final long[] inv10pow = new long[n + 1];
    inv10pow[0] = 1L;

    for (int i = 1; i <= n; ++i) {
      pow10[i] = pow10[i - 1] * 10 % mod;
      inv10pow[i] = inv10pow[i - 1] * inv10 % mod;
    }

    final int[] cnt = new int[n + 1];
    final long[] prefixSums = new long[n + 1];
    final long[] digitsSums = new long[n + 1];

    for (int i = 1; i <= n; ++i) {
      final long digit = s.charAt(i - 1) - '0';

      cnt[i] = cnt[i - 1];
      prefixSums[i] = prefixSums[i - 1];
      if (digit != 0) {
        ++cnt[i];
        prefixSums[i] = (prefixSums[i] + digit * inv10pow[cnt[i]] % mod) % mod;
      }
      digitsSums[i] = digitsSums[i - 1] + digit;
    }

    int i = 0;
    final int[] results = new int[queries.length];

    for (final int[] query : queries) {
      final int l = query[0];
      final int r = query[1];

      final long x = pow10[cnt[r + 1]] * ((prefixSums[r + 1] - prefixSums[l] + mod) % mod) % mod;
      final long digitSum = digitsSums[r + 1] - digitsSums[l];

      results[i] = (int) (x * digitSum % mod);
      ++i;
    }

    return results;
  }
}
