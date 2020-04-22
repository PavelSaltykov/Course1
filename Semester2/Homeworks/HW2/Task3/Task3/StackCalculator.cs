namespace Task3
{
    /// <summary>
    /// Class contains method for calculating postfix expression.
    /// </summary>
    public static class StackCalculator
    {
        /// <summary>
        /// Performs the operations +, -, *, / on an arithmetic expression in a postfix notation.
        /// </summary>
        /// <param name="postfixExpression">Reverse Polish notation</param>
        /// <param name="stack">Stack for calculating</param>
        /// <returns>True and result if the postfix expression was correct; otherwise, false and 0</returns>
        public static (bool, int) Calculate(string postfixExpression, IStack stack)
        { 
            var number = string.Empty;
            foreach (char symbol in postfixExpression)
            {
                if (char.IsDigit(symbol))
                {
                    number = string.Concat(number, char.ToString(symbol));
                    continue;
                }

                if (number.Length > 0)
                {
                    stack.Push(int.Parse(number));
                    number = string.Empty;
                    continue;
                }

                if (symbol == ' ')
                {
                    continue;
                }

                switch (symbol)
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if (stack.IsEmpty())
                        {
                            return (false, 0);
                        }

                        var topValue = stack.Pop();
                        if (stack.IsEmpty() || (symbol == '/' && topValue == 0))
                        {
                            stack.Clear();
                            return (false, 0);
                        }

                        stack.Push(topValue);
                        PerformOperation(symbol, stack);
                        break;
                    default:
                        stack.Clear();
                        return (false, 0);
                }
            }

            if (stack.IsEmpty())
            {
                return (false, 0);
            }

            var result = stack.Pop();
            if (stack.IsEmpty())
            {
                return (true, result);
            }

            stack.Clear();
            return (false, 0);
        }

        private static void PerformOperation(char operation, IStack stack)
        {
            var operand2 = stack.Pop();
            var operand1 = stack.Pop();
            if (operation == '+')
            {
                stack.Push(operand1 + operand2);
            }
            else if (operation == '-')
            {
                stack.Push(operand1 - operand2);
            }
            else if (operation == '*')
            {
                stack.Push(operand1 * operand2);
            }
            else
            {
                stack.Push(operand1 / operand2);
            }
        }
    }
}
