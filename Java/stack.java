import java.util.*;
import java.util.stream.Collectors;

class GFG {
    public static void main (String[] args) {
 
          Stack<Integer> stack = new Stack<>();
        Deque<Integer> deque = new ArrayDeque<>();

        stack.push(1);//1 is the top
        deque.push(1);//1 is the top
        stack.push(2);//2 is the top
        deque.push(2);//2 is the top

        List<Integer> list1 = stack.stream().collect(Collectors.toList());//[1,2]
          System.out.println("Using Stack -");
          for(int i = 0; i < list1.size(); i++){
              System.out.print(list1.get(i) + " " );
        }
          System.out.println();

        List<Integer> list2 = deque.stream().collect(Collectors.toList());//[2,1]
          System.out.println("Using Deque -");
          for(int i = 0; i < list2.size(); i++){
              System.out.print(list2.get(i) + " " );
        }
          System.out.println();
      
    }
}
