using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("StackCalculator.Calculate(\"3 4 2 * +\", false)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("3 4 2 * +", false)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"106 100 -  13 17 + *\", true)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("106 100 -  13 17 + *", true)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"5 4 * 9 3 -\", false)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("5 4 * 9 3 -", false)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"9 0 / 5 3 + -\", true)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("9 0 / 5 3 + -", true)}");
        }
    }
}
