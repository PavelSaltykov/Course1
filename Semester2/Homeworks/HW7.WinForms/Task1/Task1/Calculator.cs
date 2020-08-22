using System;
using Task1.Exceptions;

namespace Task1
{
    /// <summary>
    /// Arithmetic operations.
    /// </summary>
    public enum Operation
    {
        None,
        Addition,
        Subtraction,
        Multiplication,
        Division
    }

    /// <summary>
    /// Allows to perform operations on two double type numbers.
    /// </summary>
    public class Calculator
    {
        private double? number1;
        private double? number2;
        private Operation operation;

        /// <summary>
        /// If the first operand exists, adds or changes the second; otherwise, adds the first operand.
        /// </summary>
        /// <param name="number">Operand to add</param>
        public void AddNumber(double number)
        {
            if (number1 == null)
            {
                number1 = number;
                return;
            }
            number2 = number;
        }

        /// <summary>
        /// Adds or changes an operation.
        /// </summary>
        /// <param name="operation">Operation to add</param>
        public void AddOperation(Operation operation) => this.operation = operation;

        /// <summary>
        /// Removes operands and the operation.
        /// </summary>
        public void Clear()
        {
            number1 = null;
            number2 = null;
            operation = Operation.None;
        }

        /// <summary>
        /// Performs an operation.
        /// </summary>
        /// <returns>Calculation result</returns>
        /// <exception cref="MissingOperandException">Thrown when there is not operand.</exception>
        /// <exception cref="MissingOperationException">Thrown when there is not operation.</exception>
        public double Calculate()
        {
            if (number1 == null || number2 == null)
                throw new MissingOperandException();

            if (operation == Operation.Division && number2 == 0)
                throw new DivideByZeroException();
            
            var result = (double)PerformOperation();
            number1 = result;
            return result;
        }

        private double? PerformOperation() =>
            operation switch
            {
                Operation.Addition => number1 + number2,
                Operation.Subtraction => number1 - number2,
                Operation.Multiplication => number1 * number2,
                Operation.Division => number1 / number2,
                _ => throw new MissingOperationException()
            };
    }
}
