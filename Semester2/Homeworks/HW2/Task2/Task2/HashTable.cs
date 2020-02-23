using System;

namespace Task2
{
    class HashTable
    {
        private class List
        {
            private Node head;

            private class Node
            {
                public Node(string value, Node next)
                {
                    this.value = value;
                    this.next = next;
                }

                public string value;
                public Node next;
            }

            public void AddValue(string value)
            {
                head = new Node(value, head);
            }
            
            public bool DeleteValue(string value)
            {
                Node previous = null;
                var current = head;
                while (current != null)
                {
                    if (Equals(current.value, value))
                    {
                        if (previous == null)
                        {
                            head = head.next;
                            return true;
                        }
                        previous.next = current.next;
                        return true;
                    }
                    previous = current;
                    current = current.next;
                }
                return false;
            }

            public bool Contains(string value)
            {
                var current = head;
                while (current != null)
                {
                    if (Equals(current.value, value))
                    {
                        return true;
                    }
                    current = current.next;
                }
                return false;
            }

            public void Clear()
            {
                head = null;
            }
        }

        private readonly int size;
        private readonly List[] buckets;

        public HashTable()
        {
            size = 20;
            buckets = new List[size];
            for (var i = 0; i < size; ++i)
            {
                buckets[i] = new List();
            }
        }

        private int HashFunction(string value)
        {
            var result = 0;
            foreach (char symbol in value)
            {
                result = (result + symbol) % size;
            }
            return result;
        }

        public void AddValue(string value)
        {
            var hash = HashFunction(value);
            buckets[hash].AddValue(value);
        }

        public bool DeleteValue(string value)
        {
            var hash = HashFunction(value);
            return buckets[hash].DeleteValue(value);
        }

        public bool Contains(string value)
        {
            var hash = HashFunction(value);
            return buckets[hash].Contains(value);
        }

        public void Clear()
        {
            foreach (List list in buckets)
            {
                list.Clear();
            }
        }
    }
}