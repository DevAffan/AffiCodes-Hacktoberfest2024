using System;


namespace AgeFinder_prg
{
    class Program
    {
        static void Main(string[] args)
        {
          //  1.Logic 1 :

   Console.Write("Enter Your Date Of Birth Year= ");
            int Dob = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter Your Annual Year= ");
            string annualyear = Console.ReadLine();
            int cn = Convert.ToInt32(annualyear);
            int agefinder = cn - Dob;
            Console.Write("Your Current Age is = " + agefinder);
            Console.ReadLine();



            // 2. Logic 2

            // Console.WriteLine("Enter Your Date of Birth Date= ");
            // int currdate;
            // int datecal = currdate - date; 

            // Console.WriteLine("Enter Your Date of Birth Month= ");
            // int month = Convert.ToInt32(Console.ReadLine());

            //  Console.WriteLine("Enter Your Date of Birth Year= ");
            //  int year = Convert.ToInt32(Console.ReadLine());


        }
}
}

//namespace AgeFinder_prg
//{
//    class Program
//    {
//        static void Main()
//        {
//            Console.WriteLine("Enter Your Date Of Birth Year:");
//            int birthYear = Convert.ToInt32(Console.ReadLine());

//            Console.WriteLine("Enter Your Date Of Birth Month:");
//            int birthMonth = Convert.ToInt32(Console.ReadLine());

//            Console.WriteLine("Enter Your Date Of Birth Day:");
//            int birthDay = Convert.ToInt32(Console.ReadLine());

//            Console.WriteLine("Enter Your Annual Year:");
//            string annualYear = Console.ReadLine();
//            int currentYear = Convert.ToInt32(annualYear);

//            int age = CalculateAge(birthYear, birthMonth, birthDay, currentYear);

//            Console.WriteLine("Your Current Age is: " + age);
//            Console.ReadLine();
//        }

//        static int CalculateAge(int birthYear, int birthMonth, int birthDay, int currentYear)
//        {
//            DateTime birthDate = new DateTime(birthYear, birthMonth, birthDay);
//            DateTime currentDate = new DateTime(currentYear, DateTime.Now.Month, DateTime.Now.Day);

//            int age = currentDate.Year - birthDate.Year;

//            if (birthDate > currentDate.AddYears(-age))
//            {
//                age--;
//            }

//            return age;
//        }
//    }
//}