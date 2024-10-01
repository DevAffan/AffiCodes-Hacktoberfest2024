/*Question:
 * Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returning the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.
 */
import java.io.*;
import java.util.*;
class Solution {

    // Function to search for pattern occurrences in the given text
    ArrayList<Integer> search(String pat, String txt) {
        ArrayList<Integer> result = new ArrayList<>();
        int N = txt.length(); // Length of the text
        int M = pat.length(); // Length of the pattern

        // Precompute the longest prefix suffix (LPS) array for the pattern
        int[] lps = computeLPS(pat);

        int i = 0; // Index for the text
        int j = 0; // Index for the pattern

        // Traverse through the text
        while (i < N) {
            // If characters match, move both indices forward
            if (j < M && pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            // If the pattern is found
            if (j == M) {
                result.add(i - j + 1); // Add the start index of the match (1-based index)
                j = lps[j - 1]; // Update the pattern index using the LPS array
            }
            // If characters do not match
            else if (i < N && (j == 0 || pat.charAt(j) != txt.charAt(i))) {
                // If there's a partial match, use the LPS array to skip unnecessary comparisons
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++; // Otherwise, just move the text index forward
                }
            }
        }

        return result; // Return list of starting indices where the pattern is found
    }

    // Helper function to compute the LPS array
    private int[] computeLPS(String pattern) {
        int M = pattern.length();
        int[] lps = new int[M]; // LPS array to store the length of the longest prefix suffix
        int len = 0; // Length of the previous longest prefix suffix

        lps[0] = 0; // The LPS value for the first character is always 0

        int i = 1;
        while (i < M) {
            // If the current character matches the character at the 'len' index
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++; // Increase the length of the current prefix suffix
                lps[i] = len; // Store this length in the LPS array
                i++;
            }
            // If characters do not match
            else {
                // If len is not 0, try to find a shorter prefix that matches the suffix
                if (len != 0) {
                    len = lps[len - 1];
                }
                // If len is 0, set LPS value to 0 and move to the next character
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps; // Return the LPS array
    }
}
class Main {
    public static void main (String []args) throws IOException{
        String txt = "geeksforgeeks";
        String pat = "geek";
        Solution obj=new Solution();
        ArrayList<Integer> list=obj.search(pat, txt);
        for(int item:list)
        {
            System.out.print(item);
            System.out.print(" ");

        }
    }
}
