import java.util.Scanner;

class Sorter {
    static void heapify(int a[], int n, int i) {
        int max = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && a[left] > a[max]) max = left;
        if (right < n && a[right] > a[max]) max = right;
        if (max != i) {
            int temp = a[i];
            a[i] = a[max];
            a[max] = temp;
            heapify(a, n, max);
        }
    }

    static void sort(int a[]) {
        int n = a.length;
        for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
        for (int i = n - 1; i > 0; i--) {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            heapify(a, i, 0);
        }
    }

    static void display(int a[]) {
        for (int i = 0; i < a.length; i++) System.out.print(a[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        sort(a);
        System.out.println("Sorted array is:");
        display(a);
    }
}
