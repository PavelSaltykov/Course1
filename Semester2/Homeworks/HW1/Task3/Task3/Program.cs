using System;

namespace Task3
{
    class Program
    {
        private static void SortByBubble(int[] array)
        {
            for (int i = 0; i < array.Length; ++i)
            {
                for (int j = array.Length - 1; j > i; --j)
                {
                    if (array[j] < array[j - 1])
                    {
                        (array[j], array[j - 1]) = (array[j - 1], array[j]);
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            var array = new int[10];
            Console.Write("Array: ");
            for (var i = 0; i < array.Length; ++i)
            {
                var random = new Random();
                array[i] = random.Next(-10, 10);
                Console.Write(array[i] + " ");
            }
            SortByBubble(array);

            Console.Write("\nSorted array: ");
            for (var i = 0; i < array.Length; ++i)
            {
                Console.Write(array[i] + " ");
            }
        }
    }
}
