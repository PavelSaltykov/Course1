namespace Task1
{
    /// <summary>
    /// Node in a syntax tree.
    /// </summary>
    public interface INode
    {
        /// <summary>
        /// Prints node and subtree.
        /// </summary>
        public void Print();

        /// <summary>
        /// Calculates subtree.
        /// </summary>
        /// <returns>Result</returns>
        public int Calculate();
    }
}
