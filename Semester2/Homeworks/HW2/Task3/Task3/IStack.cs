namespace Task3
{
    /// <summary>
    /// Interface for stack.
    /// </summary>
    public interface IStack
    {
        /// <summary>
        /// Checks for emptiness.
        /// </summary>
        /// <returns>True if the stack is empty</returns>
        bool IsEmpty();

        /// <summary>
        /// Adds element to a top of the stack.
        /// </summary>
        /// <param name="value">Element to add</param>
        void Push(int value);

        /// <summary>
        /// Gets element from a top of the stack and removes it.
        /// </summary>
        /// <returns>Element that was on the top</returns>
        int Pop();

        /// <summary>
        /// Removes all elements from the stack.
        /// </summary>
        void Clear();
    }
}
