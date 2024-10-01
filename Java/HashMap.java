import java.util.HashMap;

public class HashMapExample {
    public static void main(String[] args) {
        // Creating a HashMap
        HashMap<String, Integer> map = new HashMap<>();

        // Adding key-value pairs to the HashMap
        map.put("Alice", 25);
        map.put("Bob", 30);
        map.put("Charlie", 35);

        // Printing the HashMap
        System.out.println("Initial HashMap: " + map);

        // Accessing a value using its key
        String key = "Bob";
        if (map.containsKey(key)) {
            int value = map.get(key);
            System.out.println("Value associated with key \"" + key + "\" is: " + value);
        } else {
            System.out.println("Key \"" + key + "\" not found in the map.");
        }

        // Removing an entry
        map.remove("Alice");
        System.out.println("HashMap after removing key \"Alice\": " + map);

        // Iterating over the HashMap entries
        System.out.println("Iterating over HashMap:");
        for (HashMap.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        // Checking the size of the HashMap
        System.out.println("Size of the HashMap: " + map.size());
    }
}
