import java.util.*;

class psp
{
public static void main(String gg[])
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter the size of array : ");
int n=sc.nextInt();
int arr[]=new int[n];
for(int i=0;i<n;i++)
{
System.out.print("Enter an element : ");
arr[i]=sc.nextInt();
}
int g;
for(int i=0;i<n;i++)
{
int si=i;
for(int j=i+1;j<n;j++)if(arr[si]>arr[j])si=j;
g=arr[si];
arr[si]=arr[i];
arr[i]=g;
}
for(int i=0;i<n;i++)System.out.println(arr[i]);
}
}