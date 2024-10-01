using System;

namespace Tableofnumber_prg
{
     class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter Your Number you want to write table = ");
            int number = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("\n");
            int m=1;
            while(m<=20)
            {
                int Operation = number * m;

                // Concatination Method

                //      Console.WriteLine(number + " * " + m + " = " + Operation);

                // String Interpolation Method .. Rigth Approach

                Console.WriteLine($"{number} * {m} = {Operation}");
               
                m++;
                

            }
            Console.ReadLine();




            //Console.Write("Enter Your Number to want to write table = ");
            //int number = Convert.ToInt32(Console.ReadLine());

            //for(int z= 1; z <= 20; z++)
            //{
            //    int operation = number * z;
            //    Console.WriteLine(number + " * " + z + " = " + operation);
            //}
        }
    }
}
