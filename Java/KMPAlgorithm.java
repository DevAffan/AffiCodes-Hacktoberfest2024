public class KMPAlgorithm {

    // Method to implement the KMP pattern searching algorithm
    public static void KMPSearch(String pattern, String text) {
        int m = pattern.length();  // Length of the pattern
        int n = text.length();     // Length of the text

        // Step 1: Preprocess the pattern to create the longest prefix suffix (LPS) array
        int[] lps = new int[m];
        computeLPSArray(pattern, m, lps);

        int i = 0;  // Index for text[]
        int j = 0;  // Index for pattern[]

        while (i < n) {
            // If characters match, move both indices forward
            if (pattern.charAt(j) == text.charAt(i)) {
                i++;
                j++;
            }

            // If the entire pattern is matched
            if (j == m) {
                System.out.println("Pattern found at index " + (i - j));
                j = lps[j - 1];  // Reset j to continue searching for next match
            }
            // Mismatch after j matches
            else if (i < n && pattern.charAt(j) != text.charAt(i)) {
                // Don't match lps[0..lps[j-1]] characters, they will match automatically
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }

    // Step 2: Compute the Longest Prefix Suffix (LPS) array
    public static void computeLPSArray(String pattern, int m, int[] lps) {
        int len = 0;  // Length of the previous longest prefix suffix
        int i = 1;

        lps[0] = 0;  // lps[0] is always 0

        // Loop to calculate lps[i] for i = 1 to m-1
        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                // (len != 0): consider the previous prefix suffix
                if (len != 0) {
                    len = lps[len - 1];
                }
                // (len == 0): no prefix suffix, just move to the next character
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Main method to test the KMP algorithm
    public static void main(String[] args) {
        String text = "ABABDABACDABABCABAB";
        String pattern = "ABABCABAB";

        System.out.println("Text: " + text);
        System.out.println("Pattern: " + pattern);

        KMPSearch(pattern, text);  // Perform KMP pattern search
    }
}
