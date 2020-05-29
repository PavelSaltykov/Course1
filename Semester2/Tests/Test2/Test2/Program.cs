using System.Collections.Generic;

namespace Test2
{
    public class Program
    {
        /// <summary>
        /// Generic method bubble sort.
        /// </summary>
        /// <typeparam name="T">Type of list items"</typeparam>
        /// <param name="list">List to sort</param>
        /// <param name="comparer">Object that allows to compare list items</param>
        public static void BubbleSort<T>(IList<T> list, IComparer<T> comparer)
        {
            for (var i = 0; i < list.Count; ++i)
            {
                for (var j = list.Count - 1; j > i; --j)
                {
                    if (comparer.Compare(list[j], list[j - 1]) < 0)
                    {
                        (list[j], list[j - 1]) = (list[j - 1], list[j]);
                    }
                }
            }
        }

        static void Main(string[] args)
        {
        }
    }
}
