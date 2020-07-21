namespace Task1.Operations
{
    /// <summary>
    /// Operation - node in a syntax tree.
    /// </summary>
    public abstract class Operation : INode
    {
        /// <summary>
        /// Left child node.
        /// </summary>
        public INode LeftChild { get; set; }
        /// <summary>
        /// right child node.
        /// </summary>
        public INode RightChild { get; set; }

        /// <summary>
        /// Calculates subtree.
        /// </summary>
        /// <returns>Result</returns>
        public abstract int Calculate();

        /// <summary>
        /// Prints subtree.
        /// </summary>
        public virtual void Print()
        {
            LeftChild?.Print();
            RightChild?.Print();
        }
    }
}
