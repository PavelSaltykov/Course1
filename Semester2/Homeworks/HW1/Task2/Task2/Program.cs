using System;

namespace Task2
{
    class Program
    {
        private static int Fibonacci(int number)
        {
            if (number <= 0)
            {
                return 0;
            }
            if (number == 1)
            {
                return 1;
            }
            return Fibonacci(number - 1) + Fibonacci(number - 2);
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
