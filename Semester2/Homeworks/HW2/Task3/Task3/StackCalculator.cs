namespace Task3
{
    public static class StackCalculator
    {
        /// <summary>
        /// Implements the operations +, -, *, / on an arithmetic expression as a string in a postfix notation.
        /// </summary>
        /// <param name="postfixExpression">String in reverse Polish notation</param>
        /// <param name="choice">True/False to use a list-based/array-based stack for calculate</param>
        /// <returns>True and result if the postfix expression was correct, else false and 0</returns>
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
                            return (false, 0);
                        }

                        stack.Push(topValue);
                        PerformOperation(symbol, stack);
                        break;
                    default:
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
