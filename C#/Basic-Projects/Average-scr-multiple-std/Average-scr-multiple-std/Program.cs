using System;
namespace Std
{

    class Program
    {
        static double CalAvgScr(int[] scores)
        {
            double sum=0;
            foreach (int score in scores)
            {
                //sum+= score;
                sum = sum + score;
            }
            return sum/scores.Length;
        }
        static void Main(string[] args)
        {
            int[] scores = { 91, 98, 97, 84, 86, 87 };
            double  avgscr= CalAvgScr(scores);
            Console.WriteLine($"The Avg scores is = {avgscr}");
            Console.ReadLine();

        }


    }
}