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

        public bool AddValue(int value, int position)
        {
            if (position < 0 || position > Size)
            {
                return false;
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
            return true;
        }

        public bool DeleteValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                return false;
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
            return true;
        }

        public (bool, int) GetValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                return (false, 0);
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            return (true, current.Value);
        }

        public bool SetValue(int value, int position)
        {
            if (position < 0 || position > Size - 1)
            {
                return false;
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            current.Value = value;
            return true;
        }
    }
}