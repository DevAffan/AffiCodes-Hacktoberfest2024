using System;


namespace Switch_case_user_input_Prg
{
     class Program
    {
        static void Main(string[] args)
        {
            bool continue_chk = true;
            while (continue_chk)
            {

                Console.Write("Enter the name of days or type exit to quite=");
                string days_names = Console.ReadLine();
                if (days_names== "exit")
                {
                    continue_chk = false;
                }
                else
                {   

                    switch (days_names.ToUpper())
                    {
                        case "MONDAY":
                            Console.WriteLine("1st day of week");
                            break;
                        case "TUESDAY":
                            Console.WriteLine("2nd day of week");
                            break;
                        case "WEDNESDAY":
                            Console.WriteLine("3rd day of week");
                            break;
                        case "THURSDAY":
                            Console.WriteLine("4th day of week");
                            break;
                        case "FRIDAY":
                            Console.WriteLine("5th day of week");
                            break;
                        case "SATURDAY":
                            Console.WriteLine("6th day of week");
                            break;
                        case "SUNDAY":
                            Console.WriteLine("7th and last day of week");
                            break;
                        default:
                            Console.WriteLine("Invalid name !");
                            break;
                    }
                }
            }
        }
    }
}
