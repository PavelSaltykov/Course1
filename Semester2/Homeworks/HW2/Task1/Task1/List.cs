using System;

namespace Task1
{
    class List
    {
        private Node head;

        private class Node
        {
            public Node(int value, Node next)
            {
                this.value = value;
                this.next = next;
            }

            public int value;
            public Node next;
        }

        public int Size { get; private set; }

        public bool IsEmpty { get; private set; }

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
                current = current.next;
            }

            if (previous == null)
            {
                head = new Node(value, head);
            }
            else
            {
                previous.next = new Node(value, current);
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
                current = current.next;
            }

            if (previous == null)
            {
                head = current.next;
            }
            else
            {
                previous.next = current.next;
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
                current = current.next;
            }
            return (true, current.value);
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
                current = current.next;
            }
            current.value = value;
            return true;
        }

        public void Print()
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                Console.Write($"{current.value} ");
                current = current.next;
            }
        }

        public void Clear()
        {
            head = null;
            Size = 0;
            IsEmpty = true;
        }
    }
}