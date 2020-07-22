using NUnit.Framework;

namespace Task1.Tests
{
    [TestFixture()]
    public class TreeTest
    {
        static readonly object[] Cases =
        {
            new object[] { new Tree("(* (+ 1 1) 2)"), 4 },
            new object[] { new Tree("* ( + 52 71) (- 6 31)"), -3075 },
            new object[] { new Tree("(- (* 25 (- 70 35))(/ (* (+ 15 110) 6) 7))"), 768 }
        };

        [TestCaseSource(nameof(Cases))]
        public void CalculateTest(Tree tree, int expected)
        {
            Assert.AreEqual(expected, tree.Calculate());
        }
    }
}