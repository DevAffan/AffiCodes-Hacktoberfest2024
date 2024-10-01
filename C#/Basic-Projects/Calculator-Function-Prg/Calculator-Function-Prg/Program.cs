//using System;

//namespace Calculator_Function_Prg
//{
//    class Program
//    {
//        public static double Addition(double x, double y)
//        {
//            return x + y;
//        }

//        public static double Subtraction(double x, double y)
//        {
//            return x - y;
//        }

//        public static double Multiplication(double x, double y)
//        {
//            return x * y;
//        }

//        public static double Division(double x, double y)
//        {
           
//            return x / y;
//        }

//        public static double Modulus(double x, double y)
//        {
           
//            return x % y;
//        }

//        static void Main(string[] args)
//        {
//            Console.Write("Enter a value for x: ");
//            double x = Convert.ToDouble(Console.ReadLine());

//            Console.Write("Enter a value for y: ");
//            double y = Convert.ToDouble(Console.ReadLine());


//            double add = Addition(x, y);
//            double subtract = Subtraction(x, y);
//            double multiply = Multiplication(x, y);
//            double divide = Division(x, y);
//            double modulus = Modulus(x, y);

//            Console.WriteLine($"Addition: {add}");
//            Console.WriteLine($"Subtraction: {subtract}");
//            Console.WriteLine($"Multiplication: {multiply}");
//            Console.WriteLine($"Division: {divide}");
//            Console.WriteLine($"Modulus: {modulus}");

//            Console.ReadLine();
//        }
//    }
//}

using System;

namespace Calculator_Function_Prg
{
    class Program
    {
        public static double Addition(double x, double y)
        {
            return x + y;
        }

        public static double Subtraction(double x, double y)
        {
            return x - y;
        }

        public static double Multiplication(double x, double y)
        {
            return x * y;
        }

        public static double Division(double x, double y)
        {
            return x / y;
        }

        public static double Modulus(double x, double y)
        {
            return x % y;
        }

        static void Main(string[] args)
        {
            Console.Write("Enter a value for x: ");
            double x = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter a value for y: ");
            double y = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Choose an operation:");
            Console.WriteLine("1 - Addition");
            Console.WriteLine("2 - Subtraction");
            Console.WriteLine("3 - Multiplication");
            Console.WriteLine("4 - Division");
            Console.WriteLine("5 - Modulus");

            int choice = Convert.ToInt32(Console.ReadLine());

            double result = 0;
            switch (choice)
            {
                case 1:
                    result = Addition(x, y);
                    break;
                case 2:
                    result = Subtraction(x, y);
                    break;
                case 3:
                    result = Multiplication(x, y);
                    break;
                case 4:
                    result = Division(x, y);
                    break;
                case 5:
                    result = Modulus(x, y);
                    break;
                default:
                    Console.WriteLine("Invalid operation!");
                    break;
            }

            Console.WriteLine($"Result: {result}");

            Console.ReadLine();
        }
    }
}


