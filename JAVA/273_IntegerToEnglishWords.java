// Name: MaYiLagann
// Date: 08/10/2022

/**
 * Problem: LeetCode - 273. Integer to english words
 * (https://leetcode.com/problems/integer-to-english-words/)
 * 
 * In english, numbers are reading by specific patterns.
 * 
 * 1. Number and unit, after divided by 1000.
 * 2. Number, greater than 100.
 * 3. Unit, divided by 10.
 * 4. Number, less than 20.
 * 5. Repeat.
 * 
 * Write these procedures in to the codes.
 */
class Solution {
    /**
     * List of words by number.
     * 
     * @param <Integer> Actual number.
     * @param <String>  Word of the number.
     */
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
    /**
     * Maximum size of the word list.
     */
    public final int NumberMax = 20;

    /**
     * List of words by number which are divided by 10.
     * 
     * @param <Integer> Number divided by 10.
     * @param <String>  Word of the number.
     */
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
    /**
     * Divisor for 10.
     */
    public final int TensBase = 10;
    /**
     * Maximum number for divide by 10.
     */
    public final int TensMax = 100;

    /**
     * List of words by number which are divided by 1000.
     * 
     * @param <Integer> Number divided by 1000.
     * @param <String>  Word of the number.
     */
    public final Map<Integer, String> UnitWordMap = new HashMap<Integer, String>() {
        {
            put(1, "Thousand");
            put(2, "Million");
            put(3, "Billion");
        }
    };
    /**
     * Divisor for 1000.
     */
    public final int UnitBase = 1_000;

    /**
     * Generate words from number.
     * 
     * @param num Number.
     * @return Words that reading number.
     */
    public String numberToWords(int num) {
        // If number is 0, then return "Zero".
        if (num == 0)
            return NumberWordMap.get(num);

        // Words for result.
        String words = "";
        // Index of unit of the number.
        int unitIndex = 0;

        // Repeat generate words until number exists.
        while (num > 0) {
            // Words, but number is smaller than 1000.
            String w = "";
            // Number, but number is smaller than 1000.
            int n = num % UnitBase;

            // If number and unit exists, then append unit word to front.
            if (n > 0 && unitIndex != 0) {
                words = UnitWordMap.get(unitIndex) + " " + words.trim();
            }

            // Repeat generate words until number (smaller then 1000) exists.
            while (n > 0) {
                if (n < NumberMax) {
                    // If the number is smaller than 20,
                    // then append words from normal number.
                    w += " " + NumberWordMap.get(n);
                    // Set variable n to 0 for exit iteration.
                    n = 0;
                } else if (n < TensMax) {
                    // If the number is smaller than 100,
                    // then append words from number that divided by 10.
                    w += " " + TensWordMap.get(n / TensBase);
                    // Set variable n to smaller then 10.
                    n %= TensBase;
                } else {
                    // If the number is same or greater than 100,
                    // then append words from number that excludes by 100
                    // and append "Hundred".
                    w += " " + NumberWordMap.get(n / TensMax) + " " + TensWordMap.get(TensMax / TensBase);
                    // Set variable n to smaller then 100.
                    n %= TensMax;
                }
            }

            // Append generated words to front.
            words = w + " " + words.trim();

            // Divide number by 1000.
            num /= UnitBase;
            // Increase index of the unit.
            unitIndex++;
        }

        // Return result with trim.
        return words.trim();
    }
}
