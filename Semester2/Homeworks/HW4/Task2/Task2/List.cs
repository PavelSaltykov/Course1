using Task2.Exceptions;

namespace Task2
{
    public class List
    {        
        private class Node
        {
            public Node(int value, Node next)
            {
                Value = value;
                Next = next;
            }

            public int Value { get; set; }
            public Node Next { get; set; }
        }

        private Node head;

        public int Size { get; private set; }

        public bool IsEmpty => head == null;

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

        public int IndexOf(int value)
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