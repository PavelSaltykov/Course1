using System;

namespace Task3
{
    /// <summary>
    /// Array-based stack, organized by principle of "last in — first out".
    /// </summary>
    public class StackArray : IStack
    {
        private int[] stackElements;
        private int counter;

        /// <summary>
        /// Initializes a new instance of the <see cref="StackArray"/> class.
        /// </summary>
        public StackArray()
        {
            stackElements = new int[10];
        }

        /// <summary>
        /// Checks for emptiness.
        /// </summary>
        /// <returns>True if the stack is empty</returns>
        public bool IsEmpty()
            => counter == 0;

        /// <summary>
        /// Adds element to a top of the stack.
        /// </summary>
        /// <param name="value">Element to add</param>
        public void Push(int value)
        {
            if (counter == stackElements.Length)
            {
                Resize();
            }

            stackElements[counter] = value;
            counter++;
        }

        private void Resize()
        {
            Array.Resize(ref stackElements, stackElements.Length * 2);
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

            counter--;
            var value = stackElements[counter];
            stackElements[counter] = 0;
            return value;
        }

        /// <summary>
        /// Removes all elements from the stack.
        /// </summary>
        public void Clear()
        {
            stackElements = new int[10];
            counter = 0;
        }
    }
}
