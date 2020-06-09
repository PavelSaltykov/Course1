using System;

namespace Task2
{
    /// <summary>
    /// List, collection of string values.
    /// </summary>
    public class List
    {
        private Node head;

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
            public Node(string value, Node next)
            {
                Value = value;
                Next = next;
            }

            public string Value { get; set; }
            public Node Next { get; set; }
        }

        /// <summary>
        /// Checks for emptiness.
        /// </summary>
        /// <returns>True if the list is empty</returns>
        public bool IsEmpty => head == null;

        /// <summary>
        /// Adds a value to the beginning of the list.
        /// </summary>
        /// <param name="value">Value to add</param>
        public void AddToList(string value) => head = new Node(value, head);

        /// <summary>
        /// Deletes value from the list.
        /// </summary>
        /// <param name="value">Value for deletion</param>
        /// <returns>True if value was deleted</returns>
        public bool Delete(string value)
        {
            Node previous = null;
            var current = head;
            while (current != null)
            {
                if (Equals(current.Value, value))
                {
                    if (previous == null)
                    {
                        head = head.Next;
                        return true;
                    }
                    previous.Next = current.Next;
                    return true;
                }
                previous = current;
                current = current.Next;
            }
            return false;
        }

        /// <summary>
        /// Deletes and returns the first value in the list.
        /// </summary>
        /// <returns>The first value in the list</returns>
        /// <exception cref="InvalidOperationException">Thrown when the list is empty</exception>
        public string Delete()
        {
            if (IsEmpty)
            {
                throw new InvalidOperationException();
            }

            var value = head.Value;
            head = head.Next;
            return value;
        }

        /// <summary>
        /// Сhecks if the list contains a value.
        /// </summary>
        /// <param name="value">Value to check</param>
        /// <returns>True if the list contains value</returns>
        public bool Contains(string value)
        {
            var current = head;
            while (current != null)
            {
                if (Equals(current.Value, value))
                {
                    return true;
                }
                current = current.Next;
            }
            return false;
        }
    }
}
