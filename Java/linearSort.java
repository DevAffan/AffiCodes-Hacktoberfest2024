import java.util.*;
class psp
{
public static void main(String gg[])
{
Scanner sc=new Scanner(System.in);
System.out.print("Enter the size : ");
int n=sc.nextInt();
int arr[]=new int[n];
int g;
for(int i=0;i<n;i++)
{
System.out.print("Enter an element : ");
arr[i]=sc.nextInt();
}
for(int i=0;i<arr.length;i++)
{
for(int j=i+1;j<arr.length;j++)
{
if(arr[i]>arr[j])
{
g=arr[i];
arr[i]=arr[j];
arr[j]=g;
}
}
}
for(int i=0;i<n;i++)System.out.print(arr[i]+" ");
}
}