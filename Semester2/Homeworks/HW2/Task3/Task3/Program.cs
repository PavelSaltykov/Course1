using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            var stackList = new StackList();
            var stackArray = new StackArray();

            Console.WriteLine("StackCalculator.Calculate(\"3 4 2 * +\", stackArray)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("3 4 2 * +", stackArray)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"106 100 -  13 17 + *\", stackList)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("106 100 -  13 17 + *", stackList)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"5 4 * 9 3 -\", stackArray)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("5 4 * 9 3 -", stackArray)}");
            Console.WriteLine();

            Console.WriteLine("StackCalculator.Calculate(\"9 0 / 5 3 + -\", stackList)");
            Console.WriteLine($"Result: {StackCalculator.Calculate("9 0 / 5 3 + -", stackList)}");
        }
    }
}
