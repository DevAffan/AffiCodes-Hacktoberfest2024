import java.util.HashMap;
import java.util.Map;

public class BoyerMoore {
    
    // Function to generate the bad character heuristic table
    private static Map<Character, Integer> preprocessBadCharacterRule(String pattern) {
        Map<Character, Integer> badCharShift = new HashMap<>();
        int patternLength = pattern.length();
        
        // Populate bad character shift map
        for (int i = 0; i < patternLength; i++) {
            badCharShift.put(pattern.charAt(i), Math.max(1, patternLength - i - 1));
        }
        
        return badCharShift;
    }

    // Function to search the pattern in the text using the Boyer-Moore algorithm
    public static int boyerMooreSearch(String text, String pattern) {
        Map<Character, Integer> badCharShift = preprocessBadCharacterRule(pattern);
        
        int textLength = text.length();
        int patternLength = pattern.length();
        
        int offset = 0; // current alignment of the pattern with the text
        
        while (offset <= textLength - patternLength) {
            int i = patternLength - 1;
            
            // Keep comparing the pattern with text from right to left
            while (i >= 0 && pattern.charAt(i) == text.charAt(offset + i)) {
                i--;
            }
            
            // If the pattern is found in the text
            if (i < 0) {
                System.out.println("Pattern found at index " + offset);
                return offset; // return the first occurrence index
            } else {
                // Move the pattern to align with the next potential match in the text
                char mismatchChar = text.charAt(offset + i);
                int shift = badCharShift.getOrDefault(mismatchChar, patternLength);
                offset += shift;
            }
        }
        
        System.out.println("Pattern not found");
        return -1; // return -1 if the pattern is not found
    }

    public static void main(String[] args) {
        String text = "THIS IS A SIMPLE EXAMPLE";
        String pattern = "EXAMPLE";
        
        boyerMooreSearch(text, pattern);
    }
}
