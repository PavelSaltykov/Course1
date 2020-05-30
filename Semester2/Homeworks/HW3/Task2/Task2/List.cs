namespace Task2
{
    public class List
    {
        private Node head;

        private class Node
        {
            public Node(string value, Node next)
            {
                Value = value;
                Next = next;
            }

            public string Value { get; set; }
            public Node Next { get; set; }
        }

        public bool IsEmpty => head == null;

        public void AddToList(string value) => head = new Node(value, head);

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

        public string DeleteFromHead()
        {
            if (IsEmpty)
            {
                return string.Empty;
            }

            var value = head.Value;
            head = head.Next;
            return value;
        }
    }
}
