
/*Question:
 * Given an array arr[] of size, N. Find the subarray with maximum XOR. A subarray is a contiguous part of the array.
 *  Example testcase: int N=4, arr[]={1,2,3,4}, output:7.Explanation The subarray {3,4} has maximum xor 
value equal to 7.


Solution :
If we create each and every subarray and find xor value it will give time complexity of
O(n^2), to optimise it and bring it down to O{n} we use trie. Here each number is stored in its
bitwise form we mean 0's and 1's. So if we have a array of numbers say 1,2,3,4 we can represent 
1-->0001
2-->0010
3-->0011
4-->0100
Now for each trienode we will have two pointer nodes that is 0 and 1.When we try to insert a number
from the array in each step it will check if the node 0 or 1 for the particular bit of the number
is present or not if present then it will not create another node and if not then it will
with the respectivw bit value that is either 1 or 0 .In order to solve this problem we leverage the 
concept bit trie to store all the numbers in bitwise form inn this trie data structure
Now we start to take prefix sum starting at index 0 and store the value in the trie
for each prefix sum value we get we trie to search for the maximum xor value we can get 
by traversing the trie. Say for the number 5 its bitwise representation-->000101 now to find max xor
we need to find 0's for position it has 1 and 1 for vice versa since xor of 1 and 1=0 and 1 and 0 or 0 and 1
is 1,if not found then we will xor with whatever value is present the number found will give the value of 
an intermediate substring and we will continuosly check whether it is maximum or not.For the xoring the value
with that which is in trie is inspired from the property that if a^b=c the a^(a^b)=a^c which is ultimately
b=a^c

 */

 public class Max_Xor_Subarray_Trie
{
     public static void main(String[] args) {
     Solution obj = new Solution();
     int []arr={1,2,3,4};
     int n=4;
        int res = obj.maxSubarrayXOR(n, arr);
        System.out.print(res);
        System.out.println();
	}
}



class Solution{
static class TrieNode {
        TrieNode left;
        TrieNode right;
    }

    public static void insert(TrieNode head, int num) {
        TrieNode pCrawl = head;
        for (int i = 31; i >= 0; i--) {
            int ithBit = (num >> i) & 1;
            if (ithBit == 0) {
                if (pCrawl.left == null) {
                    pCrawl.left = new TrieNode();
                }
                pCrawl = pCrawl.left;
            } else {
                if (pCrawl.right == null) {
                    pCrawl.right = new TrieNode();
                }
                pCrawl = pCrawl.right;
            }
        }
    }

    public static int maxXor(TrieNode head, int num) {
        int maxXor = 0;
        TrieNode pCrawl = head;
        //I am moving from left most bit(MSB) to right most(LSB) to get max answer so as to get set bit 1 in left most position (MSB) to get large decimal value
        for (int i = 31; i >= 0; i--) {
            int ithBit = (num >> i) & 1;
            if (ithBit == 1) {
                if (pCrawl.left != null) {
                    maxXor += Math.pow(2, i);
                    pCrawl = pCrawl.left;
                } else {
                    pCrawl = pCrawl.right;
                }
            } else {
                if (pCrawl.right != null) {
                    maxXor += Math.pow(2, i);
                    pCrawl = pCrawl.right;
                } else {
                    pCrawl = pCrawl.left;
                }
            }
        }
        return maxXor;
    }

    static int maxSubarrayXOR(int n, int arr[]){
        TrieNode root=new TrieNode();
           insert(root,0);
     
        // Initialize answer and xor of current prefix
        int result = Integer.MIN_VALUE;
        int pre_xor = 0;
     
        // Traverse all input array element
        for (int i=0; i<n; i++)
        {
            // update current prefix xor and insert it 
                // into Trie
            pre_xor = pre_xor^arr[i];
            insert(root,pre_xor);
     
            // Query for current prefix xor in Trie and 
            // update result if required
            result = Math.max(result, maxXor(root,pre_xor));

        }
        return result;
    }
}