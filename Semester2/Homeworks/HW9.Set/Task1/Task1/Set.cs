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
            if (root == null)
            {
                root = new Node(item);
                Count++;
                return true;
            }

            var current = root;
            Node parent = null;
            var order = 0;

            while (current != null)
            {
                order = item.CompareTo(current.Value);
                if (order == 0)
                    return false;

                parent = current;
                current = (order < 0) ? current.LeftChild : current.RightChild;
            }

            if (order < 0)
                parent.LeftChild = new Node(item);
            else
                parent.RightChild = new Node(item);

            Count++;
            return true;
        }

        public bool Remove(T item)
        {
            throw new NotImplementedException();
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

        public IEnumerator<T> GetEnumerator() => CopyToList().GetEnumerator();

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

        private List<T> CopyToList()
        {
            var list = new List<T>();
            CopySubtree(root);
            return list;

            void CopySubtree(Node node)
            {
                if (node == null)
                    return;

                CopySubtree(node.LeftChild);
                list.Add(node.Value);
                CopySubtree(node.RightChild);
            }
        }
    }
}
