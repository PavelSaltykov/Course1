using NUnit.Framework;
using System.Collections.Generic;

namespace Task1.Tests
{
    [TestFixture()]
    public class FunctionsTests
    {
        private readonly List<int> list = new List<int> { 1, 2, 3 };

        [Test()]
        public void MapTest()
        {
            Assert.AreEqual(new List<int>() { 2, 4, 6 }, Functions.Map(list, (elem) => elem * 2));
            Assert.AreEqual(new List<int>() { 9, 8, 7 }, Functions.Map(list, (elem) => 10 - elem));
        }

        [Test()]
        public void FilterTest()
        {
            Assert.AreEqual(new List<int>() { 2 }, Functions.Filter(list, (elem) => elem % 2 == 0));
            Assert.AreEqual(new List<int>() { }, Functions.Filter(list, (elem) => elem < 0));
        }

        [Test()]
        public void FoldTest()
        {
            Assert.AreEqual(6, Functions.Fold(list, 1, (acc, elem) => acc * elem));
            Assert.AreEqual(0, Functions.Fold(list, -6, (acc, elem) => acc + elem));
        }
    }
}