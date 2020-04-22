using NUnit.Framework;
using System;

namespace Task3.Tests
{
    public class StackTest
    {
        static IStack[] Stacks = { new StackList(), new StackArray() };

        [SetUp]
        public void Initialize() 
        {
            Stacks = new IStack[] { new StackList(), new StackArray() };
        }

        [TestCaseSource("Stacks")]
        public void PopFromEmptyStackTest(IStack stack)
        {
            Assert.Throws(typeof(InvalidOperationException), () => stack.Pop());
        }

        [TestCaseSource("Stacks")]
        public void PushTest(IStack stack)
        {
            stack.Push(1);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestCaseSource("Stacks")]
        public void PopTest(IStack stack)
        {
            stack.Push(2);
            Assert.AreEqual(2, stack.Pop());
        }

        [TestCaseSource("Stacks")]
        public void TwoElementsPopTest(IStack stack)
        {
            stack.Push(3);
            stack.Push(4);
            Assert.AreEqual(4, stack.Pop());
            Assert.AreEqual(3, stack.Pop());
        }

        [TestCaseSource("Stacks")]
        public void ClearTest(IStack stack)
        {
            stack.Push(5);
            stack.Clear();
            Assert.IsTrue(stack.IsEmpty());
        }

        [Test]
        public void ResizeTest()
        {
            var stack = new StackArray();
            for (var i = 0; i < 1000; ++i)
            {
                stack.Push(i);
            }
            Assert.AreEqual(999, stack.Pop());
        }
    }
}