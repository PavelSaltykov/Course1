using System;

namespace Task3
{
    /// <summary>
    /// List-based stack, collection of elements, which organized by principle of "last in — first out".
    /// </summary>
    public class StackList : IStack
    {
        private StackElement top;

        /// <summary>
        /// Stack element, contains value and reference to next element.
        /// </summary>
        private class StackElement
        {
            public int Value { get; set; }
            public StackElement Next { get; set; }

            /// <summary>
            /// Initializes a new instance of the <see cref="StackElement"/> class.
            /// </summary>
            /// <param name="value">Value of element</param>
            /// <param name="next">Reference to next element</param>
            public StackElement(int value, StackElement next)
            {
                Value = value;
                Next = next;
            }
        }

        /// <summary>
        /// Checks for emptiness.
        /// </summary>
        /// <returns>True if the stack is empty</returns>
        public bool IsEmpty()
            => top == null;

        /// <summary>
        /// Adds element to a top of the stack.
        /// </summary>
        /// <param name="value">Element to add</param>
        public void Push(int value)
        {
            top = new StackElement(value, top);
        }

        /// <summary>
        /// Gets element from a top of the stack and removes it.
        /// </summary>
        /// <exception cref="InvalidOperationException">Thrown when the stack is empty</exception>
        /// <returns>Element that was on the top</returns>
        public int Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException();
            }

            int value = top.Value;
            top = top.Next;
            return value;
        }

        /// <summary>
        /// Removes all elements from the stack.
        /// </summary>
        public void Clear()
        {
            top = null;
        }
    }
}
