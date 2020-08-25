using NUnit.Framework;
using System;
using System.Collections.Generic;

namespace Task1.Tests
{
    [TestFixture()]
    public class SetTests
    {
        private Set<int> set;

        [Test]
        public void ForeachTest()
        {
            set = new Set<int> { 4, 3, 5, 1, 2, 0 };

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
            set = new Set<int>() { 0 };

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
            set = new Set<int>();

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
            set = new Set<int>() { 0 };
            
            Assert.IsFalse(set.Add(0));
            Assert.AreEqual(1, set.Count);
        }

        [Test()]
        public void RemoveTest()
        {
            set = new Set<int>() { 0, 5, 1, -5, 4 };

            Assert.IsTrue(set.Remove(0));
            Assert.IsTrue(set.Remove(-5));

            Assert.AreEqual(3, set.Count);
            Assert.IsFalse(set.Contains(0));
            Assert.IsFalse(set.Contains(-5));
        }

        [Test()]
        public void RemoveNotExistingItemTest()
        {
            set = new Set<int>() { 0, 1, 2 };

            Assert.IsFalse(set.Remove(-1));
            Assert.AreEqual(3, set.Count);
        }

        [Test()]
        public void ClearTest()
        {
            set = new Set<int>() { 1, 0, 2 };
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
            set = new Set<int>() { 1, -1, 0 };
            Assert.IsTrue(set.Contains(0));
            Assert.IsFalse(set.Contains(-2));
        }

        [Test()]
        public void CopyToTest()
        {
            set = new Set<int>() { 3, -2, 0, 5, 2, 4, 1 };

            var actualArray = new int[set.Count + 2];
            set.CopyTo(actualArray, 2);

            var expectedArray = new int[] { 0, 0, -2, 0, 1, 2, 3, 4, 5 };
            Assert.AreEqual(expectedArray, actualArray);
        }

        [Test()]
        public void ExceptWithTest()
        {
            set = new Set<int>() { 0, 1, 2, 3 };
            var other = new int[] { 0, 2, 4, 5 };

            set.ExceptWith(other);
            var expected = new int[] { 1, 3 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void ExceptWithItselfTest()
        {
            set = new Set<int>() { 0, 1 };

            set.ExceptWith(set);
            var expected = new int[] { };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void IntersectWithTest()
        {
            set = new Set<int>() { 3, 0, 2, 4 };
            var other = new int[] { 0, 2, 3, 5 };

            set.IntersectWith(other);
            var expected = new int[] { 0, 2, 3 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        [Test()]
        public void IntersectWithItselfTest()
        {
            set = new Set<int>() { -1, 1, 0 };

            set.IntersectWith(set);
            var expected = new int[] { -1, 1, 0 };
            CollectionAssert.AreEquivalent(expected, set);
        }

        //[Test()]
        //public void SymmetricExceptWithTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void UnionWithTest()
        //{
        //    Assert.Fail();
        //}

        [Test()]
        public void IsProperSubsetOfTest()
        {
            set = new Set<int>() { 0, 1, 2, 3 };
            Assert.IsTrue(set.IsProperSubsetOf(new int[] { 1, 2, 3, 0, -1 }));
            Assert.IsFalse(set.IsProperSubsetOf(set));
            Assert.IsFalse(set.IsProperSubsetOf(new int[] { 1, 2, 3 }));
        }

        //[Test()]
        //public void IsProperSupersetOfTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void IsSubsetOfTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void IsSupersetOfTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void OverlapsTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void SetEqualsTest()
        //{
        //    Assert.Fail();
        //}
    }
}