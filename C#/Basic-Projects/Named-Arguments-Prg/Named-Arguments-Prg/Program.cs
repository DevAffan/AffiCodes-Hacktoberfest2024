using System;

namespace MyApplication
{
    class NamedArguments
    {
        static void CustomMethod(string child1, string child2, string child3)
        {
            Console.WriteLine("The youngest child is: " + child3);
        }

        static void Main(string[] args)
        {
            CustomMethod(child3: "Ali", child1: "Saima", child2: "Kashaf");
            Console.ReadLine();
        }
    }
}

