using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace For_Each_Prg
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] cars = { "Civic , Honda City , Land Cruiser , Vigo" };
            foreach (string car in cars)
            {
               Console.WriteLine(car);
               Console.ReadLine();
            }
            int[] number = { 22, 00, 89, 87, 55, 34, 65, 12, 65, 67 };
            foreach (int i in number)
            {
               Console.WriteLine(i);
            

            }
            Console.ReadLine();
        }
    }
}
