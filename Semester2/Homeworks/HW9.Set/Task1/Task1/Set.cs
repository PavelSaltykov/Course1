using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

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

            foreach (var item in this)
            {
                array[arrayIndex] = item;
                arrayIndex++;
            }
        }

        public void ExceptWith(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            if (other == this)
            {
                Clear();
                return;
            }

            foreach (var item in other)
            {
                Remove(item);
            }
        }

        public void IntersectWith(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            var itemsToRemove = this.Except(other);

            foreach (var item in itemsToRemove)
            {
                Remove(item);
            }
        }

        public bool IsProperSubsetOf(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            return IsSubsetOf(other) && Count < other.Distinct().Count();
        }

        public bool IsProperSupersetOf(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            return IsSupersetOf(other) && Count > other.Distinct().Count();
        }

        public bool IsSubsetOf(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            foreach (var item in this)
            {
                if (!other.Contains(item))
                    return false;
            }
            return true;
        }

        public bool IsSupersetOf(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            foreach (var item in other)
            {
                if (!Contains(item))
                    return false;
            }
            return true;
        }

        public bool Overlaps(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            foreach (var item in other)
            {
                if (Contains(item))
                    return true;
            }
            return false;
        }

        public bool SetEquals(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            return IsSubsetOf(other) && Count == other.Distinct().Count();
        }

        public void SymmetricExceptWith(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            if (other == this)
            {
                Clear();
                return;
            }

            foreach (var item in other)
            {
                if (Contains(item))
                {
                    Remove(item);
                }
                else
                {
                    Add(item);
                }
            }
        }

        public void UnionWith(IEnumerable<T> other)
        {
            if (other == null)
                throw new ArgumentNullException();

            if (other == this)
                return;

            foreach (var item in other)
            {
                Add(item);
            }
        }

        void ICollection<T>.Add(T item) => Add(item);

        public IEnumerator<T> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public bool Remove(T item)
        {
            throw new NotImplementedException();
        }
    }
}
