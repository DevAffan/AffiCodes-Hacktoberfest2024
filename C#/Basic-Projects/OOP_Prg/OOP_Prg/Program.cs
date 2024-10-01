using System;

namespace YourNamespace
{
    class Prg
    {
        int a = 10;
        string b = "John";

        public string show()
        {
             return a.ToString()  + b;
           // return int.Parse(a.ToString() + b);
          //  return a + b;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Prg prg1 = new Prg();
            Console.WriteLine(prg1.show());
            Console.ReadLine();
        }
    }
}
