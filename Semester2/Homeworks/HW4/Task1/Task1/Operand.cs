using System;

namespace Task1
{
    /// <summary>
    /// Operand - leaf in a syntax tree.
    /// </summary>
    public class Operand : INode
    {
        /// <summary>
        /// Operand value.
        /// </summary>
        public int Value { get; set; }

        /// <summary>
        /// Calculates operand.
        /// </summary>
        /// <returns>Operand value</returns>
        public int Calculate() => Value;

        /// <summary>
        /// Prints the operand value.
        /// </summary>
        public void Print()
        {
            Console.Write($"{Value} ");
        }
    }
}
