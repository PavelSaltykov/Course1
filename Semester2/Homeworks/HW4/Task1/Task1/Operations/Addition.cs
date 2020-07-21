using System;

namespace Task1.Operations
{
    /// <summary>
    /// Addition operation.
    /// </summary>
    public class Addition : Operation
    {
        /// <summary>
        /// Calculates subtree.
        /// </summary>
        /// <returns>Result</returns>
        public override int Calculate() => LeftChild.Calculate() + RightChild.Calculate();

        /// <summary>
        /// Prints the operation and subtree.
        /// </summary>
        public override void Print()
        {
            Console.Write("+ ");
            base.Print();
        }
    }
}
