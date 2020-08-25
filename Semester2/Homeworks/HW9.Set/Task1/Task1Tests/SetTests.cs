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

        //[Test()]
        //public void ContainsTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void CopyToTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void ExceptWithTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void IntersectWithTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void IsProperSubsetOfTest()
        //{
        //    Assert.Fail();
        //}

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

        //[Test()]
        //public void GetEnumeratorTest()
        //{
        //    Assert.Fail();
        //}
    }
}