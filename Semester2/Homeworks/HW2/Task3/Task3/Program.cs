using System;

namespace Task3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter:");
            Console.WriteLine("1 - use list-based stack");
            Console.WriteLine("2 - use array-based stack");
            Console.WriteLine("to calculate postfix expression");

            var input = Console.ReadLine();
            int choice;
            if (!int.TryParse(input, out choice))
            {
                Console.WriteLine("Invalid input");
                return;
            }

            IStack stack;
            switch (choice)
            {
                case 1:
                    stack = new StackList();
                    break;
                case 2:
                    stack = new StackArray();
                    break;
                default:
                    Console.WriteLine("Invalid input");
                    return;
            }

            Console.WriteLine("Enter postfix expression: ");
            input = Console.ReadLine();
            var (isCorrect, result) = StackCalculator.Calculate(input, stack);
            
            if (!isCorrect)
            {
                Console.WriteLine("Invalid postfix expression");
                return;
            }

            Console.WriteLine($"Result: {result}");
        }
    }
}
