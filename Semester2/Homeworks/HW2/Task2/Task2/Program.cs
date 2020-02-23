using System;

namespace Task2
{
    class Program
    {
        static void Main(string[] args)
        {
            var hashTable = new HashTable();
            hashTable.AddValue("123");
            Console.WriteLine("hashTable.AddValue(\"123\")");
            Console.WriteLine($"hashTable.Contains(\"123\"): {hashTable.Contains("123")}");
            Console.WriteLine();

            hashTable.DeleteValue("123");
            Console.WriteLine("hashTable.DeleteValue(\"123\")");
            Console.WriteLine($"hashTable.Contains(\"123\"): {hashTable.Contains("123")}");
            Console.WriteLine();

            hashTable.AddValue("123");
            Console.WriteLine("hashTable.AddValue(\"123\")");
            hashTable.Clear();
            Console.WriteLine("hashTable.Clear()");
            Console.WriteLine($"hashTable.Contains(\"123\"): {hashTable.Contains("123")}");
        }
    }
}