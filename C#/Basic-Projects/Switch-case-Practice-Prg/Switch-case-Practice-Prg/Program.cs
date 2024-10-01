using System;

namespace SwitchCaseUserInputPrg
{
    class Program
    {

        static int CalculateLevenshteinDistance(string s1, string s2)
        {
            int len1 = s1.Length;
            int len2 = s2.Length;

            int[,] distances = new int[len1 + 1, len2 + 1];

            for (int i = 0; i <= len1; i++)
            {
                distances[i, 0] = i;
            }

            for (int j = 0; j <= len2; j++)
            {
                distances[0, j] = j;
            }

            for (int j = 1; j <= len2; j++)
            {
                for (int i = 1; i <= len1; i++)
                {
                    int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

                    distances[i, j] = Math.Min(
                        Math.Min(distances[i - 1, j] + 1, distances[i, j - 1] + 1),
                        distances[i - 1, j - 1] + cost
                    );
                }
            }

            return distances[len1, len2];
        }

        static void Main(string[] args)
        {
            bool continueCheck = true;
            string[] validDays = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY" };

            while (continueCheck)
            {
                Console.Write("Enter the name of days or type exit to quit: ");
                string userInput = Console.ReadLine().ToUpper();

                if (userInput == "EXIT")
                {
                    continueCheck = false;
                }
                else
                {
                    string closestMatch = null;
                    int minDistance = int.MaxValue;

                    foreach (string validDay in validDays)
                    {
                        int distance = CalculateLevenshteinDistance(userInput, validDay);
                        if (distance < minDistance)
                        {
                            minDistance = distance;
                            closestMatch = validDay;
                        }
                    }

                    if (minDistance <= 2) // You can adjust the threshold as needed
                    {
                        // If the Levenshtein distance is below a certain threshold (e.g., 2), consider it a valid day and display the result.
                        switch (closestMatch)
                        {
                            case "MONDAY":
                                Console.WriteLine("1st day of the week");
                                break;
                            case "TUESDAY":
                                Console.WriteLine("2nd day of the week");
                                break;
                            case "WEDNESDAY":
                                Console.WriteLine("3rd day of the week");
                                break;
                            case "THURSDAY":
                                Console.WriteLine("4th day of the week");
                                break;
                            case "FRIDAY":
                                Console.WriteLine("5th day of the week");
                                break;
                            case "SATURDAY":
                                Console.WriteLine("6th day of the week");
                                break;
                            case "SUNDAY":
                                Console.WriteLine("7th and last day of the week");
                                break;
                        }
                    }
                    else
                    {
                        Console.WriteLine("Invalid name!");
                    }
                }
            }
        }
    }
}
