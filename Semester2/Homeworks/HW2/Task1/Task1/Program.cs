using System;

namespace Task1
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List();
            Console.WriteLine($"list.IsEmpty: {list.IsEmpty}");
            list.AddValue(1, 0);
            Console.WriteLine("list.AddValue(1, 0)");
            Console.WriteLine($"list.Size: {list.Size}");
            Console.WriteLine($"list.IsEmpty: {list.IsEmpty}");
            Console.WriteLine();

            list.DeleteValue(0);
            Console.WriteLine("list.DeleteValue(0);");
            Console.WriteLine($"list.Size: {list.Size}");
            Console.WriteLine($"list.IsEmpty: {list.IsEmpty}");
            Console.WriteLine($"list.GetValue(0): {list.GetValue(0)}");
            Console.WriteLine();

            list.AddValue(5, 0);
            Console.WriteLine("list.AddValue(5, 0)");
            Console.WriteLine($"list.GetValue(0): {list.GetValue(0)}");
            Console.WriteLine();

            list.SetValue(1, 0);
            Console.WriteLine("list.SetValue(1, 0);");
            Console.WriteLine($"list.GetValue(0): {list.GetValue(0)}");
            Console.WriteLine();

            list.AddValue(2, 0);
            list.AddValue(3, 2);
            list.AddValue(4, 3);
            Console.WriteLine("list.AddValue(2, 0)");
            Console.WriteLine("list.AddValue(3, 2)");
            Console.WriteLine("list.AddValue(4, 3)");
            Console.WriteLine($"list.IsEmpty: {list.IsEmpty}");
            Console.Write($"List: ");
            list.Print();
            Console.WriteLine();

            Console.WriteLine();
            list.Clear();
            Console.WriteLine("list.Clear()");
            Console.WriteLine($"list.Size: {list.Size}");
            Console.WriteLine($"list.IsEmpty: {list.IsEmpty}");
        }
    }
}