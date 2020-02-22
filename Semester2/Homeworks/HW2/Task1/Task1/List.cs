using System;

namespace Task1
{
    class List
    {
        private int size;
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

        public int GetSize() => size;

        public bool IsEmpty() => size == 0;

        public void AddValue(int value, int position)
        {
            if (position < 0 || position > size)
            {
                return;
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
            size++;
        }

        public bool DeleteValue(int position)
        {
            if (position < 0 || position > size - 1)
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
            size--;
            return true;
        }

        public int GetValue(int position)
        {
            if (position < 0 || position > size - 1)
            {
                return -1;
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.next;
            }
            return current.value;
        }

        public bool SetValue(int value, int position)
        {
            if (position < 0 || position > size - 1)
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
            for (var i = 0; i < size; ++i)
            {
                Console.Write($"{current.value} ");
                current = current.next;
            }
        }

        public void Clear()
        {
            head = null;
            size = 0;
        }
    }
}