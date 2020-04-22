using System;

namespace Task3
{
    class StackArray : IStack
    {
        private int[] stackElements;
        private int counter;

        public StackArray()
        {
            stackElements = new int[10];
        }

        public bool IsEmpty()
            => counter == 0;

        public void Push(int value)
        {
            if (counter == stackElements.Length)
            {
                Resize();
            }

            stackElements[counter] = value;
            counter++;
        }

        private void Resize()
        {
            Array.Resize(ref stackElements, stackElements.Length * 2);
        }

        public int Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException();
            }

            counter--;
            var value = stackElements[counter];
            stackElements[counter] = 0;
            return value;
        }

        public void Clear()
        {
            stackElements = new int[10];
            counter = 0;
        }
    }
}
