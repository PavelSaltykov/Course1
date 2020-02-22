using System;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List();
            list.AddValue(1, 0);
            Console.WriteLine($"Size: {list.GetSize()}");
            Console.WriteLine();

            list.DeleteValue(0);
            Console.WriteLine($"Size: {list.GetSize()}");
            Console.WriteLine($"Value: {list.GetValue(0)}");
            Console.WriteLine();

            list.AddValue(5, 0);
            Console.WriteLine($"Value: {list.GetValue(0)}");
            Console.WriteLine();

            list.SetValue(1, 0);
            Console.WriteLine($"Value: {list.GetValue(0)}");
            Console.WriteLine();

            list.AddValue(2, 0);
            list.AddValue(3, 2);
            list.AddValue(4, 3);
            Console.WriteLine($"List: ");
            list.Print();
            Console.WriteLine();

            Console.WriteLine();
            list.Clear();
            Console.WriteLine($"Size: {list.GetSize()}");
        }
    }
}