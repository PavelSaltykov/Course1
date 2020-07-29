using System;
using System.Collections.Generic;

namespace Task1
{
    /// <summary>
    /// Functions for List of int.
    /// </summary>
    public static class Functions
    {
        /// <summary>
        /// Applies the transmitted function to each element of the list.
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="func">Function that transforms a list element</param>
        /// <returns>List of transformed elements</returns>
        public static List<int> Map(List<int> list, Func<int, int> func)
        {
            var newList = new List<int>();
            foreach (var elem in list)
            {
                newList.Add(func(elem));
            }
            return newList;
        }

        /// <summary>
        /// Creates list of elements for which the transmitted function returned true.
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="func">Function that returns a boolean value for a list element</param>
        /// <returns>Filtered list</returns>
        public static List<int> Filter(List<int> list, Func<int, bool> func)
        {
            var newList = new List<int>();
            foreach (var elem in list)
            {
                if (func(elem))
                {
                    newList.Add(elem);
                }
            }
            return newList;
        }

        /// <summary>
        /// Accumulates value while going through the list.
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="initial">Initial value</param>
        /// <param name="func">Function that returns the next accumulated value for the current value and element</param>
        /// <returns>Accumulated value</returns>
        public static int Fold(List<int> list, int initial, Func<int, int, int> func)
        {
            var accumulated = initial;
            foreach (var elem in list)
            {
                accumulated = func(accumulated, elem);
            }
            return accumulated;
        }
    }
}
