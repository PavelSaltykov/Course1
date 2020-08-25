using NUnit.Framework;
using System;
using System.Collections.Generic;

namespace Task1.Tests
{
    [TestFixture()]
    public class SetTests
    {
        [Test]
        public void ForeachTest()
        {
            var set = new Set<int> { 4, 3, 5, 1, 2, 0 };

            var actualList = new List<int>();
            foreach (var item in set)
            {
                actualList.Add(item);
            }

            var expectedList = new List<int>() { 0, 1, 2, 3, 4, 5 };
            Assert.AreEqual(expectedList, actualList);
        }

        [Test]
        public void ChangeInForeachTest()
        {
            var set = new Set<int>() { 0 };

            void ChaingeSetInForeach()
            {
                foreach (var item in set)
                {
                    set.Add(-1);
                }
            }

            Assert.Throws<InvalidOperationException>(() => ChaingeSetInForeach());
        }

        [Test()]
        public void AddTest()
        {
            var set = new Set<int>();

            Assert.IsTrue(set.Add(0));
            Assert.IsTrue(set.Add(1));
            Assert.IsTrue(set.Add(2));

            Assert.AreEqual(3, set.Count);
            Assert.IsTrue(set.Contains(2));
            Assert.IsTrue(set.Contains(1));
            Assert.IsTrue(set.Contains(0));
        }

        [Test()]
        public void AddExistingItemTest()
        {
            var set = new Set<int>() { 0 };

            Assert.IsFalse(set.Add(0));
            Assert.AreEqual(1, set.Count);
        }

        [Test()]
        public void RemoveTest()
        {
            var set = new Set<int>() { 0, 5, 1, -5, 4 };

            Assert.IsTrue(set.Remove(0));
            Assert.IsTrue(set.Remove(-5));

            Assert.AreEqual(3, set.Count);
            Assert.IsFalse(set.Contains(0));
            Assert.IsFalse(set.Contains(-5));
        }

        [Test()]
        public void RemoveNotExistingItemTest()
        {
            var set = new Set<int>() { 0, 1, 2 };

            Assert.IsFalse(set.Remove(-1));
            Assert.AreEqual(3, set.Count);
        }

        [Test()]
        public void ClearTest()
        {
            var set = new Set<int>() { 1, 0, 2 };
            Assert.AreEqual(3, set.Count);

            set.Clear();

            Assert.AreEqual(0, set.Count);
            Assert.IsFalse(set.Contains(1));
            Assert.IsFalse(set.Contains(0));
            Assert.IsFalse(set.Contains(2));
        }

        [Test()]
        public void ContainsTest()
        {
            var set = new Set<int>() { 1, -1, 0 };
            Assert.IsTrue(set.Contains(0));
            Assert.IsFalse(set.Contains(-2));
        }

        [Test()]
        public void CopyToTest()
        {
            var set = new Set<int>() { 3, -2, 0, 5, 2, 4, 1 };

            var actualArray = new int[set.Count + 2];
            set.CopyTo(actualArray, 2);

            var expectedArray = new int[] { 0, 0, -2, 0, 1, 2, 3, 4, 5 };
            Assert.AreEqual(expectedArray, actualArray);
        }

        [Test()]
        public void ExceptWithTest()
        {
            var set = new Set<int>() { 0, 1, 2, 3 };
            var other = new int[] { 0, 2, 4, 5 };

            set.ExceptWith(other);
            var expected = new int[] { 1, 3 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void ExceptWithItselfTest()
        {
            var set = new Set<int>() { 0, 1 };

            set.ExceptWith(set);
            var expected = new int[] { };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void IntersectWithTest()
        {
            var set = new Set<int>() { 3, 0, 2, 4 };
            var other = new int[] { 0, 2, 3, 5 };

            set.IntersectWith(other);
            var expected = new int[] { 0, 2, 3 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void IntersectWithItselfTest()
        {
            var set = new Set<int>() { -1, 1, 0 };

            set.IntersectWith(set);
            var expected = new int[] { -1, 1, 0 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void SymmetricExceptWithTest()
        {
            var set = new Set<int>() { 0, -4, -2, 1, 4, 2 };
            var other = new int[] { 0, 2, 4, 5, -1 };

            set.SymmetricExceptWith(other);
            var expected = new int[] { -4, -2, 1, 5, -1 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void SymmetricExceptWithItselfTest()
        {
            var set = new Set<int>() { 1, 2, 3 };

            set.SymmetricExceptWith(set);
            var expected = new int[] { };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void UnionWithTest()
        {
            var set = new Set<int>() { 3, 5, 2, 0, -1 };
            var other = new int[] { 3, 2, 10, 7 };

            set.UnionWith(other);
            var expected = new int[] { 3, 5, 2, 0, -1, 10, 7 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void UnionWithItselfTest()
        {
            var set = new Set<int>() { 0, -2, -1 };

            set.UnionWith(set);
            var expected = new int[] { 0, -2, -1 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void IsProperSubsetOfTest()
        {
            var set = new Set<int>() { 0, 1, 2, 3 };
            Assert.IsTrue(set.IsProperSubsetOf(new int[] { 1, 2, 3, 0, -1 }));
            Assert.IsFalse(set.IsProperSubsetOf(set));
            Assert.IsFalse(set.IsProperSubsetOf(new int[] { 1, 2, 3, 3 }));
        }

        [Test()]
        public void IsProperSupersetOfTest()
        {
            var set = new Set<int>() { 0, 1, 2, 3 };
            Assert.IsTrue(set.IsProperSupersetOf(new int[] { 1, 2, 3, 3 }));
            Assert.IsFalse(set.IsProperSupersetOf(set));
            Assert.IsFalse(set.IsProperSupersetOf(new int[] { 1, 2, 3, 0, -1 }));
        }

        [Test()]
        public void IsSubsetOfTest()
        {
            var set = new Set<int>() { 0, 1, 2, 3 };
            Assert.IsTrue(set.IsSubsetOf(new int[] { 0, 1, 2, 3, 4 }));
            Assert.IsTrue(set.IsSubsetOf(set));
            Assert.IsFalse(set.IsSubsetOf(new int[] { 1, 2, 3 }));
        }

        [Test()]
        public void IsSupersetOfTest()
        {
            var set = new Set<int>() { 0, 1, 2, 3 };
            Assert.IsTrue(set.IsSupersetOf(new int[] { 0, 1, 2, 3, 3 }));
            Assert.IsTrue(set.IsSupersetOf(set));
            Assert.IsFalse(set.IsSupersetOf(new int[] { 1, 2, 4 }));
        }

        [Test()]
        public void OverlapsTest()
        {
            var set = new Set<int>() { 0, 1, 2 };
            Assert.IsTrue(set.Overlaps(new int[] { 3, 4, 5, 0, 6, 7 }));
            Assert.IsFalse(set.Overlaps(new int[] { 4, 5 }));
        }

        [Test()]
        public void SetEqualsTest()
        {
            var set = new Set<int>() { 2, 3, -1, 0, 1 };
            Assert.IsTrue(set.SetEquals(new int[] { -1, 0, 0, 1, 2, 3 }));
            Assert.IsFalse(set.SetEquals(new int[] { 2, 3, -1, 0 }));
        }
    }
}