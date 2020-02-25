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
            var newElements = new int[stackElements.Length + 10];
            stackElements.CopyTo(newElements, 0);
            stackElements = newElements;
        }

        public int Pop()
        {
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
