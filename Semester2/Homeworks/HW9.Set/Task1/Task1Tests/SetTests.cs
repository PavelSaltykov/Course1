using NUnit.Framework;
using System.Collections.Generic;

namespace Task1.Tests
{
    [TestFixture()]
    public class SetTests
    {
        private Set<int> set;

        [SetUp]
        public void Initialize() => set = new Set<int>();

        [Test]
        public void ForeachTest()
        {
            set.Add(4);
            set.Add(3);
            set.Add(5);
            set.Add(1);
            set.Add(2);
            set.Add(0);

            var actualList = new List<int>();
            foreach (var item in set)
            {
                actualList.Add(item);
            }

            var excpectedList = new List<int>() { 0, 1, 2, 3, 4, 5 };
            Assert.AreEqual(excpectedList, actualList);
        }

        [Test()]
        public void AddTest()
        {
            set.Add(0);
            Assert.AreEqual(1, set.Count);
            Assert.IsTrue(set.Contains(0));
        }

        [Test()]
        public void AddExistingItemTest()
        {
            set.Add(0);
            set.Add(0);
            Assert.AreEqual(1, set.Count);
        }

        //[Test()]
        //public void RemoveTest()
        //{
        //    Assert.Fail();
        //}

        //[Test()]
        //public void ClearTest()
        //{
        //    Assert.Fail();
        //}

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