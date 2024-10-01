using System;


namespace Function_Return_Value_Prg
{
    class Program
    {
        static int MyMethod(int x)
        {
            return 5 + x;

        }
        static void Main(string[] args)
        {
            Console.WriteLine(MyMethod(3));
           int result= MyMethod(9);
            Console.WriteLine(result);
            Console.WriteLine(MyMethod(result));
            Console.ReadLine();

        }
    }
}
