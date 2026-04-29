class Solution {
  public double calculateTax(int[][] brackets, int income) {
    double tax = 0;

    int lower = 0;
    int remainingIncome = income;

    for (final int[] bracket : brackets) {
      final int upper = bracket[0];
      final int percent = bracket[1];

      final int bracketIncome = Math.min(upper - lower, remainingIncome);
      lower = upper;

      tax += bracketIncome * percent / 100.0;
      remainingIncome -= bracketIncome;

      if (remainingIncome == 0) {
        break;
      }
    }

    return tax;
  }
}
