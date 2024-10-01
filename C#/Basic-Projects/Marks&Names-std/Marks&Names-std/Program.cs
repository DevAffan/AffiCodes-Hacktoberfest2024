using System;
using System.Security.Policy;


namespace Marks_Names_std
{
     class Program
    {
        static void Main(string[] args)
        {
            string student_1, student_2;
            Console.Write("Enter the name of student 1: ");
            student_1 = Console.ReadLine();
            Console.Write("Enter  marks of subject 1: ");
            int marks1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter  marks of subject 2: ");
            int marks2 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter  marks of subject 3: ");
            int marks3 = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("\n");
            Console.Write("Enter the name of student 2: ");
            student_2 = Console.ReadLine();
            Console.Write("Enter  marks of subject 1: ");
            int marks1st = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter  marks of subject 2: ");
            int marks2nd = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter  marks of subject 3: ");
            int marks3rd = Convert.ToInt32(Console.ReadLine());


            int totalMarksStudent1 = marks1 + marks2 + marks3;
            int totalMarksStudent2 = marks1st + marks2nd + marks3rd;
            if (totalMarksStudent1 > totalMarksStudent2)
            {
                Console.WriteLine(student_1 + " has the highest  marks: " + totalMarksStudent1);
                Console.ReadLine();
            }
            else if (totalMarksStudent2 > totalMarksStudent1)
            {
                Console.WriteLine(student_2 + " has the highest  marks: " + totalMarksStudent2);
                Console.ReadLine();
            }
            else
            {
                Console.WriteLine("Both " + student_1 + " and " + student_2 + " have the same  marks: " + totalMarksStudent1);
                Console.ReadLine();
            }


        }
    }
}
