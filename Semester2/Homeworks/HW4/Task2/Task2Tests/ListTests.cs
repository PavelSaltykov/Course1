using NUnit.Framework;
using Task2.Exceptions;

namespace Task2.Tests
{
    [TestFixture()]
    public class ListTests
    {
        private List list;

        [SetUp()]
        public void Initialize()
        {
            list = new List();
        }

        [Test()]
        public void AddByInvalidPositionTest()
        {
            Assert.Throws<InvalidPositionException>(() => list.AddValue(0, 1));
            Assert.Throws<InvalidPositionException>(() => list.AddValue(0, -1));
        }

        [Test()]
        public void DeleteByInvalidPositionTest()
        {
            Assert.Throws<InvalidPositionException>(() => list.DeleteValue(100));
            Assert.Throws<InvalidPositionException>(() => list.DeleteValue(-100));
        }

        [Test()]
        public void GetByInvalidPositionTest()
        {
            Assert.Throws<InvalidPositionException>(() => list.GetValue(0));
            Assert.Throws<InvalidPositionException>(() => list.GetValue(-1));
        }

        [Test()]
        public void SetByInvalidPositionTest()
        {
            Assert.Throws<InvalidPositionException>(() => list.SetValue(0, 0));
            Assert.Throws<InvalidPositionException>(() => list.SetValue(0, -10));
        }

        [Test()]
        public void AddValueTest()
        {
            Assert.IsTrue(list.IsEmpty);
            list.AddValue(0, 0);
            list.AddValue(1, 1);

            Assert.IsFalse(list.IsEmpty);
            Assert.AreEqual(2, list.Size);
        }

        [Test()]
        public void DeleteValueTest()
        {
            list.AddValue(0, 0);
            list.AddValue(1, 1);

            list.DeleteValue(1);
            list.DeleteValue(0);

            Assert.AreEqual(0, list.Size);
            Assert.IsTrue(list.IsEmpty);
        }

        [Test()]
        public void GetValueTest()
        {
            list.AddValue(0, 0);
            list.AddValue(1, 0);
            Assert.AreEqual(0, list.GetValue(1));
        }

        [Test()]
        public void SetValueTest()
        {
            list.AddValue(0, 0);
            list.SetValue(1, 0);
            Assert.AreEqual(1, list.GetValue(0));
        }

        [Test()]
        public void ContainsTest()
        {
            list.AddValue(0, 0);
            Assert.IsTrue(list.Contains(0));
            Assert.IsFalse(list.Contains(1));
        }

        [Test()]
        public void PositionOfTest()
        {
            list.AddValue(1, 0);
            list.AddValue(2, 0);
            Assert.AreEqual(1, list.PositionOf(1));
            Assert.AreEqual(-1, list.PositionOf(3));
        }
    }
}