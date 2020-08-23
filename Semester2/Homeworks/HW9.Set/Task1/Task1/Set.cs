using System;
using System.Collections;
using System.Collections.Generic;

namespace Task1
{
    public class Set<T> : ISet<T> where T : IComparable
    {
        private Node root;

        private class Node
        {
            public T Value { get; set; }
            public Node LeftChild { get; set; }
            public Node RightChild { get; set; }

            public Node(T value)
            {
                Value = value;
            }
        }

        public int Count { get; private set; }

        public bool IsReadOnly => false;

        public bool Add(T item)
        {
            return AddToSubtree(root);

            bool AddToSubtree(Node node)
            {
                if (node == null)
                {
                    node = new Node(item);
                    Count++;
                    return true;
                }

                if (item.CompareTo(node.Value) < 0)
                    return AddToSubtree(node.LeftChild);

                if (item.CompareTo(node.Value) > 0)
                    return AddToSubtree(node.RightChild);

                return false;
            }
        }

        public void Clear()
        {
            root = null;
            Count = 0;
        }

        public bool Contains(T item)
        {
            return SubtreeContains(root);

            bool SubtreeContains(Node node)
            {
                if (node == null)
                    return false;

                if (item.CompareTo(node.Value) < 0)
                    return SubtreeContains(node.LeftChild);

                if (item.CompareTo(node.Value) > 0)
                    return SubtreeContains(node.RightChild);

                return true;
            }
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            if (array == null)
                throw new ArgumentNullException();

            if (arrayIndex < 0)
                throw new ArgumentOutOfRangeException();

            if (array.Length - arrayIndex < Count)
                throw new ArgumentException(nameof(array));

            CopySubtree(root);

            void CopySubtree(Node node)
            {
                if (node == null)
                    return;

                CopySubtree(node.LeftChild);
                array[arrayIndex] = node.Value;
                arrayIndex++;
                CopySubtree(node.RightChild);
            }
        }

        public void ExceptWith(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public IEnumerator<T> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public void IntersectWith(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool IsProperSubsetOf(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool IsProperSupersetOf(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool IsSubsetOf(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool IsSupersetOf(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool Overlaps(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public bool Remove(T item)
        {
            throw new NotImplementedException();
        }

        public bool SetEquals(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public void SymmetricExceptWith(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        public void UnionWith(IEnumerable<T> other)
        {
            throw new NotImplementedException();
        }

        void ICollection<T>.Add(T item)
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
}
