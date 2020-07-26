using Task2.Exceptions;

namespace Task2
{
    /// <summary>
    /// The list, collection of integer values.
    /// </summary>
    public class List
    {
        /// <summary>
        /// List element, contains value and reference to next element.
        /// </summary>
        private class Node
        {
            /// <summary>
            /// Initializes a new instance of the <see cref="Node"/> class.
            /// </summary>
            /// <param name="value">Value of element</param>
            /// <param name="next">Reference to next element</param>
            public Node(int value, Node next)
            {
                Value = value;
                Next = next;
            }

            public int Value { get; set; }
            public Node Next { get; set; }
        }

        private Node head;

        /// <summary>
        /// Number of elements.
        /// </summary>
        public int Size { get; private set; }

        /// <summary>
        /// Checks for emptiness.
        /// </summary>
        public bool IsEmpty => head == null;

        /// <summary>
        /// Adds an element by position.
        /// </summary>
        /// <param name="value">Value to add</param>
        /// <param name="position">The zero-based position of the element to add</param>
        /// <exception cref="InvalidPositionException">Thrown when position is invalid</exception>
        public virtual void AddValue(int value, int position)
        {
            if (position < 0 || position > Size)
            {
                throw new InvalidPositionException();
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < position; ++i)
            {
                previous = current;
                current = current.Next;
            }

            if (previous == null)
            {
                head = new Node(value, head);
            }
            else
            {
                previous.Next = new Node(value, current);
            }
            Size++;
        }

        /// <summary>
        /// Deletes an element by position.
        /// </summary>
        /// <param name="position">The zero-based position of the element to delete</param>
        /// <exception cref="InvalidPositionException">Thrown when position is invalid</exception>
        public void DeleteValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < position; ++i)
            {
                previous = current;
                current = current.Next;
            }

            if (previous == null)
            {
                head = current.Next;
            }
            else
            {
                previous.Next = current.Next;
            }
            Size--;
        }

        /// <summary>
        /// Returns the value of element by position.
        /// </summary>
        /// <param name="position">The zero-based position of the element to get value</param>
        /// <returns>Value by position</returns>
        /// <exception cref="InvalidPositionException">Thrown when position is invalid</exception>
        public int GetValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            return current.Value;
        }

        /// <summary>
        /// Sets the value of element by position.
        /// </summary>
        /// <param name="value">New value</param>
        /// <param name="position">The zero-based position of the element to set value</param>
        /// <exception cref="InvalidPositionException">Thrown when position is invalid</exception>
        public virtual void SetValue(int value, int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            current.Value = value;
        }

        /// <summary>
        /// Determines whether an element is in the list.
        /// </summary>
        /// <param name="value">Value to locate in the list</param>
        /// <returns>True if value is found in the list; otherwise, false</returns>
        public bool Contains(int value)
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                if (current.Value == value)
                {
                    return true;
                }
                current = current.Next;
            }
            return false;
        }

        /// <summary>
        /// Returns the zero-based position of the first occurrence
        /// </summary>
        /// <param name="value">Value to locate in the list</param>
        /// <returns>The zero-based position, if found; otherwise, -1</returns>
        public int PositionOf(int value)
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                if (current.Value == value)
                {
                    return i;
                }
                current = current.Next;
            }
            return -1;
        }
    }
}
