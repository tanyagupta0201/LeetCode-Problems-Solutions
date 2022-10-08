// Name: MaYiLagann
// Date: 08/10/2022
// Description: Problem link: (https://leetcode.com/problems/integer-to-english-words/)

class Solution {
    public final Map<Integer, String> NumberWordMap = new HashMap<Integer, String>() {
        {
            put(0, "Zero");
            put(1, "One");
            put(2, "Two");
            put(3, "Three");
            put(4, "Four");
            put(5, "Five");
            put(6, "Six");
            put(7, "Seven");
            put(8, "Eight");
            put(9, "Nine");
            put(10, "Ten");
            put(11, "Eleven");
            put(12, "Twelve");
            put(13, "Thirteen");
            put(14, "Fourteen");
            put(15, "Fifteen");
            put(16, "Sixteen");
            put(17, "Seventeen");
            put(18, "Eighteen");
            put(19, "Nineteen");
        }
    };
    public final int NumberMax = 20;

    public final Map<Integer, String> TensWordMap = new HashMap<Integer, String>() {
        {
            put(1, "Ten");
            put(2, "Twenty");
            put(3, "Thirty");
            put(4, "Forty");
            put(5, "Fifty");
            put(6, "Sixty");
            put(7, "Seventy");
            put(8, "Eighty");
            put(9, "Ninety");
            put(10, "Hundred");
        }
    };
    public final int TensBase = 10;
    public final int TensMax = 100;

    public final Map<Integer, String> UnitWordMap = new HashMap<Integer, String>() {
        {
            put(1, "Thousand");
            put(2, "Million");
            put(3, "Billion");
        }
    };
    public final int UnitBase = 1_000;

    public String numberToWords(int num) {
        if (num == 0)
            return NumberWordMap.get(num);

        String words = "";
        int unitIndex = 0;

        while (num > 0) {
            int n = num % UnitBase;

            while (n > 0) {
                if (n < NumberMax) {
                    words = NumberWordMap.get(n) + " " + words;
                    n = 0;
                } else if (n < TensMax) {
                    words = TensWordMap.get(n / TensBase) + " " + words;
                    n %= NumberMax;
                } else {
                    words = NumberWordMap.get(n / TensMax) + " " + TensWordMap.get(TensMax / TensBase) + " " + words;
                    n %= TensMax;
                }
            }

            num /= UnitBase;
            unitIndex++;

            words = UnitWordMap.get(unitIndex) + " " + words;
        }

        return words.trim();
    }
}
