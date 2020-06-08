using NUnit.Framework;
using System;

namespace Task2.Tests
{
    [TestFixture()]
    public class ListTest
    {
        private List list;

        [SetUp()]
        public void Initialize()
        {
            list = new List();
        }

        [Test()]
        public void AddToListTest()
        {
            Assert.IsTrue(list.IsEmpty);
            list.AddToList("a");
            Assert.IsFalse(list.IsEmpty);
        }

        [Test()]
        public void DeleteTest()
        {
            list.AddToList("ab");

            Assert.IsFalse(list.Delete("ba"));
            Assert.IsTrue(list.Delete("ab"));
            Assert.IsTrue(list.IsEmpty);
        }

        [Test()]
        public void ContainsTest()
        {
            list.AddToList("abc");
            Assert.IsFalse(list.Contains("abcd"));
            Assert.IsTrue(list.Contains("abc"));
        }

        [Test()]
        public void DeleteFromHeadOfEmptyListTest()
        {
            Assert.Throws(typeof(InvalidOperationException), () => list.DeleteFromHead());
        }

        [Test()]
        public void DeleteFromHeadTest()
        {
            list.AddToList("abc");
            Assert.AreEqual("abc", list.DeleteFromHead());
            Assert.IsTrue(list.IsEmpty);
        }
    }
}