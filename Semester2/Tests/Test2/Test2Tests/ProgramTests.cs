using NUnit.Framework;
using System.Collections.Generic;
using System.ComponentModel;

namespace Test2.Tests
{
    [TestFixture()]
    public class ProgramTests
    {
        private readonly Comparer<int> comparer = Comparer<int>.Default;

        static readonly object[] Cases =
        {
            new object[] { new List<int>(), new List<int>() },
            new object[] { new List<int> { -1, 2, 3, 1, 0 }, new List<int> { -1, 0, 1, 2, 3 } },
            new object[] { new List<int> { 1, 1, 1 }, new List<int> { 1, 1, 1 } }
        };

        [TestCaseSource(nameof(Cases))]
        public void BubbleSortTest(List<int> listToSort, List<int> expectedList)
        {
            Program.BubbleSort(listToSort, comparer);
            Assert.AreEqual(expectedList, listToSort);
        }

        [Test()]
        public void BubbleSortListOfStringsTest()
        {
            var listToSort = new List<string> { "sd", "bc", "abd" };
            var expectedList = new List<string> { "abd", "bc", "sd" };
            var stringComarer = Comparer<string>.Default;

            Program.BubbleSort(listToSort, stringComarer);

            Assert.AreEqual(expectedList, listToSort);
        }
    }
}