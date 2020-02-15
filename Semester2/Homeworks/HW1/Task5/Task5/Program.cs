using System;

namespace Task5
{
    class Program
    {
        private static void ArrayOutput(int[,] array)
        {
            var rows = array.GetUpperBound(0) + 1;
            var columns = array.GetUpperBound(1) + 1;
            for (var i = 0; i < rows; ++i)
            {
                for (var j = 0; j < columns; ++j)
                {
                    Console.Write(array[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        private static void SwapColumns(int[,] array, int columnNumber1, int columnNumber2)
        {
            var rows = array.GetUpperBound(0) + 1;
            for (var i = 0; i < rows; ++i)
            {
                (array[i, columnNumber1], array[i, columnNumber2]) = (array[i, columnNumber2], array[i, columnNumber1]);
            }
        }

        private static void SortColumns(int[,] array)
        {
            var columns = array.GetUpperBound(1) + 1;
            for (var i = 0; i < columns; ++i)
            {
                for (var j = columns - 1; j > i; --j)
                {
                    if (array[0, j] < array[0, j - 1])
                    {
                        SwapColumns(array, j, j - 1);
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            var random = new Random();
            int[,] array = new int[random.Next(1, 10), random.Next(1, 10)];
            var rows = array.GetUpperBound(0) + 1;
            var columns = array.GetUpperBound(1) + 1;

            Console.WriteLine("Random array:");
            for (var i = 0; i < rows; ++i)
            {
                for (var j = 0; j < columns; ++j)
                {
                    array[i, j] = random.Next(0, 10);
                    Console.Write(array[i, j] + " ");
                }
                Console.WriteLine();
            }

            SortColumns(array);
            Console.WriteLine("\nColumn sorted array:");
            ArrayOutput(array);
        }
    }
}