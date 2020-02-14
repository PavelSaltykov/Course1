using System;

namespace Task1
{
    class Program
    {
        private static int Factorial(int number) => number <= 1 ? 1 : number * Factorial(number - 1);

        static void Main(string[] args)
        {
            Console.WriteLine($"Factorial({1}) = {Factorial(1)}");
            Console.WriteLine($"Factorial({4}) = {Factorial(4)}");
            Console.WriteLine($"Factorial({5}) = {Factorial(5)}");

            Console.Write("Enter number: ");
            var inputString = Console.ReadLine();
            var number = int.Parse(inputString);
            Console.WriteLine($"Factorial({number}) = {Factorial(number)}");
        }
    }
}
