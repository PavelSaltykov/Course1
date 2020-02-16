using System;

namespace Task2
{
    class Program
    {
        private static int Fibonacci(int number)
        {
            int[] tempArray = { 0, 1, 1 };
            for (int i = 0; i < number; i++)
            {
                tempArray[2] = tempArray[0] + tempArray[1];
                for (int j = 0; j < 2; j++)
                {
                    tempArray[j] = tempArray[j + 1];
                }
            }
            return tempArray[2];
        }

        static void Main(string[] args)
        {
            Console.WriteLine($"Fibonacci({1}): {Fibonacci(1)}");
            Console.WriteLine($"Fibonacci({6}): {Fibonacci(6)}");
            Console.WriteLine($"Fibonacci({10}): {Fibonacci(10)}");

            Console.Write("Enter the fibonacci number: ");
            var inputString = Console.ReadLine();
            var number = int.Parse(inputString);
            Console.WriteLine($"Fibonacci({number}): {Fibonacci(number)}");
        }
    }
}
