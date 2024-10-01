public class BinarySearch {

    static int find(int a[], int key) {
        int start = 0;
        int end = a.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (a[mid] == key) {
                return mid;
            } else if (a[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int a[] = { 5, 15, 20, 23, 27, 32, 41 };
        int chabi = 50;
        int c = BinarySearch.find(a, chabi);
        System.out.println(c);

    }

}