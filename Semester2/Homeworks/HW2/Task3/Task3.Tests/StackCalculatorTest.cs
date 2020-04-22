using NUnit.Framework;
using System;
using System.Collections.Generic;

namespace Task3.Tests
{
    [TestFixture]
    public class StackCalculatorTest
    {
        static IEnumerable<IStack> Stacks
        {
            get
            {
                yield return new StackList();
                yield return new StackArray();
            }
        }

        [TestCaseSource(nameof(Stacks))]
        public void WithInvalidSymbolsTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("1 3 * a -", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void EmptyStringTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void DivideByZeroTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("9 0 / 5 3 +", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void OperationBeforeOperandTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("+ 1 2", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void OneOperandBeforeOperationTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("3 - 2", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void NotEnoughOperationTest(IStack stack)
        {
            Assert.AreEqual((false, 0), StackCalculator.Calculate("4 5 + 3 2 *", stack));
        }
        
        [TestCaseSource(nameof(Stacks))]
        public void StackShouldBeEmpty1Test(IStack stack)
        {
            StackCalculator.Calculate("7 0 / 1", stack);
            Assert.IsTrue(stack.IsEmpty());
        }

        [TestCaseSource(nameof(Stacks))]
        public void StackShouldBeEmpty2Test(IStack stack)
        {
            StackCalculator.Calculate("5 b", stack);
            Assert.IsTrue(stack.IsEmpty());
        }

        [TestCaseSource(nameof(Stacks))]
        public void StackShouldBeEmpty3Test(IStack stack)
        {
            StackCalculator.Calculate("9 6", stack);
            Assert.IsTrue(stack.IsEmpty());
        }

        [TestCaseSource(nameof(Stacks))]
        public void CalculateCorrectExpression1Test(IStack stack)
        {
            Assert.AreEqual((true, 3), StackCalculator.Calculate("96 6 - 17 13 + /", stack));
        }

        [TestCaseSource(nameof(Stacks))]
        public void CalculateCorrectExpression2Test(IStack stack)
        {
            Assert.AreEqual((true, 110), StackCalculator.Calculate("26 42 2 * +", stack));
        }
    }
}
