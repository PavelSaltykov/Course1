using NUnit.Framework;
using Task2.Exceptions;

namespace Task2.Tests
{
    [TestFixture()]
    public class UniqueListTests
    {
        private UniqueList list;

        [SetUp()]
        public void Initialize()
        {
            list = new UniqueList();
        }

        [Test()]
        public void AddValueTest()
        {
            list.AddValue(0, 0);
            list.AddValue(1, 1);
            Assert.Throws<AddingExistingElementException>(() => list.AddValue(1, 1));
        }

        [Test()]
        public void SetValueTest()
        {
            list.AddValue(0, 0);
            list.AddValue(1, 1);

            list.SetValue(1, 1);
            Assert.Throws<AddingExistingElementException>(() => list.SetValue(1, 0));
        }
    }
}