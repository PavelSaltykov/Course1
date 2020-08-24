using NUnit.Framework;
using System;
using Task1.Exceptions;

namespace Task1.Tests
{
    [TestFixture()]
    public class CalculatorTests
    {
        private Calculator calculator;

        [SetUp]
        public void Initialize() => calculator = new Calculator();

        [Test]
        public void MissingOperandTest()
        {
            calculator.AddOperation(Operation.Addition);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
            calculator.AddNumber(1);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
        }

        [Test]
        public void MissingOperationTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(2);
            Assert.Throws<MissingOperationException>(() => calculator.Calculate());
        }

        [Test]
        public void ClearTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(2);
            calculator.AddOperation(Operation.Addition);
            Assert.DoesNotThrow(() => calculator.Calculate());

            calculator.Clear();

            calculator.AddNumber(1);
            calculator.AddNumber(2);
            Assert.Throws<MissingOperationException>(() => calculator.Calculate());

            calculator.Clear();

            calculator.AddNumber(1);
            calculator.AddOperation(Operation.Addition);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
        }

        [Test]
        public void DivideByZeroTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(0);
            calculator.AddOperation(Operation.Division);
            Assert.Throws<DivideByZeroException>(() => calculator.Calculate());
        }

        [TestCase(Operation.Addition, 9)]
        [TestCase(Operation.Subtraction, 3)]
        [TestCase(Operation.Multiplication, 18)]
        [TestCase(Operation.Division, 2)]
        public void OperationsTests(Operation operation, double expected)
        {
            calculator.AddNumber(6);
            calculator.AddNumber(3);
            calculator.AddOperation(operation);
            Assert.AreEqual(expected, calculator.Calculate());
        }

        [Test]
        public void CalculateTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(2);
            calculator.AddOperation(Operation.Addition);
            Assert.AreEqual(3, calculator.Calculate());
        }

        [Test]
        public void CalculateTwiceTest()
        {
            calculator.AddNumber(5);
            calculator.AddNumber(1);
            calculator.AddOperation(Operation.Subtraction);
            Assert.AreEqual(4, calculator.Calculate());
            Assert.AreEqual(3, calculator.Calculate());
        }

        [Test]
        public void ChangeOperationTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(2);
            calculator.AddOperation(Operation.Addition);
            calculator.Calculate();

            calculator.AddOperation(Operation.Multiplication);
            Assert.AreEqual(6, calculator.Calculate());
        }

        [Test]
        public void ChangeNumberTest()
        {
            calculator.AddNumber(20);
            calculator.AddNumber(2);
            calculator.AddOperation(Operation.Division);

            calculator.AddNumber(5);
            Assert.AreEqual(4, calculator.Calculate());

        }
    }
}