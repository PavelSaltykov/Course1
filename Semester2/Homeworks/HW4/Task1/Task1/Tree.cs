using System;
using Task1.Operations;

namespace Task1
{
    /// <summary>
    /// Abstract syntax tree.
    /// </summary>
    public class Tree
    {
        private INode root;

        /// <summary>
        /// Initializes a new instance of the <see cref="Tree"/> class.
        /// </summary>
        /// <param name="expression">Prefix expression</param>
        public Tree(string expression)
        {
            Build(expression);
        }

        private void Build(string expression)
        {
            var values = expression.Split(new char[] { ' ', '(', ')' }, StringSplitOptions.RemoveEmptyEntries);
            var position = -1;
            root = NewNode();

            INode NewNode()
            {
                position++;
                if (char.IsDigit(values[position], 0))
                {
                    return new Operand() { Value = int.Parse(values[position]) };
                }

                Operation newNode = values[position] switch
                {
                    "+" => new Addition(),
                    "-" => new Subtraction(),
                    "*" => new Multiplication(),
                    "/" => new Division(),
                    _ => null
                };

                newNode.LeftChild = NewNode();
                newNode.RightChild = NewNode();
                return newNode;
            }
        }

        /// <summary>
        /// Prints tree.
        /// </summary>
        public void Print() => root?.Print();

        /// <summary>
        /// Calculates the value of an expression by tree.
        /// </summary>
        /// <returns>Result</returns>
        public int Calculate() => root.Calculate();
    }
}
