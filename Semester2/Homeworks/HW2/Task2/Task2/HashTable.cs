using System;

namespace Task2
{
    class HashTable
    {
        private class List
        {
            private Node head;

            public bool IsEmpty { get; private set; } = true;

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
                IsEmpty = false;
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
                            IsEmpty = head == null;
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

            public string DeleteFromHead()
            {
                if (IsEmpty)
                {
                    return string.Empty;
                }

                var value = head.value;
                head = head.next;
                IsEmpty = head == null;
                return value;
            }
        }

        private int size;
        private float loadFactor;
        private int amountOfElements;
        private List[] buckets;

        public HashTable()
        {
            size = 20;
            CreateBuckets();
        }

        private void CreateBuckets()
        {
            buckets = new List[size];
            for (var i = 0; i < size; ++i)
            {
                buckets[i] = new List();
            }
        }

        private void Resize()
        {
            var tempList = new List();
            foreach(var list in buckets)
            {
                while (!list.IsEmpty)
                {
                    var value = list.DeleteFromHead();
                    tempList.AddValue(value);
                }
            }

            size *= 2;
            CreateBuckets();

            while (!tempList.IsEmpty)
            {
                Add(tempList.DeleteFromHead());
            }
        }

        private int HashFunction(string value)
        {
            var result = 0;
            foreach (var symbol in value)
            {
                result = (result + symbol) % size;
            }
            return result;
        }

        private void Add(string value)
        {
            var hash = HashFunction(value);
            buckets[hash].AddValue(value);
        }

        public void AddValue(string value)
        {
            Add(value);
            amountOfElements++;
            loadFactor = (float)amountOfElements / size;

            if (loadFactor > 1)
            {
                Resize();
            }
        }

        public bool DeleteValue(string value)
        {
            var hash = HashFunction(value);
            var valueDeleted = buckets[hash].DeleteValue(value);
            if (valueDeleted)
            {
                amountOfElements--;
                loadFactor = (float)amountOfElements / size;
            }
            return valueDeleted;
        }

        public bool Contains(string value)
        {
            var hash = HashFunction(value);
            return buckets[hash].Contains(value);
        }

        public void Clear()
        {
            size = 20;
            amountOfElements = 0;
            loadFactor = 0;
            CreateBuckets();
        }
    }
}