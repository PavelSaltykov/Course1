using System;

namespace Task4
{
    class Program
    {
        private static void ArrayOutput(int[] array)
        {
            for (var i = 0; i < array.Length; ++i)
            {
                Console.Write(array[i] + " ");
            }
        }

        private static int[] SpiralTraversal(int[,] array)
        {
            int[] output = new int[array.Length];
            var iPosition = array.GetLength(0) / 2;
            var jPosition = iPosition;
            output[0] = array[iPosition, jPosition];

            var size = array.GetLength(0);
            var iStep = 1;
            var jStep = -1;
            var currentPosition = 1;

            for (var n = 1; n < size; ++n)
            {
                for (var m = 0; m < n; ++m)
                {
                    output[currentPosition] = array[iPosition, jPosition += jStep];
                    ++currentPosition;
                }
                for (var m = 0; m < n; ++m)
                {
                    output[currentPosition] = array[iPosition += iStep, jPosition];
                    ++currentPosition;
                }
                iStep = -iStep;
                jStep = -jStep;
            }

            for (var n = 0; n < size - 1; ++n)
            {
                output[currentPosition] = array[iPosition, jPosition += jStep];
                ++currentPosition;
            }
            return output;
        }

        static void Main(string[] args)
        {
            var random = new Random();
            var size = 2 * random.Next(0, 4) + 1;
            int[,] array = new int[size, size];

            Console.WriteLine("Random array:");
            for (var i = 0; i < size; ++i)
            {
                for (var j = 0; j < size; ++j)
                {
                    array[i, j] = random.Next(0, 10);
                    Console.Write(array[i, j] + " ");
                }
                Console.WriteLine();
            }

            Console.Write("\nSpiral traversal: ");
            ArrayOutput(SpiralTraversal(array));
        }
    }
}