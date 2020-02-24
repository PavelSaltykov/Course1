namespace Task3
{
    class StackArray : IStack
    {
        private int[] stackElements;
        private int counter;

        public bool IsEmpty { get; private set; } = true;

        public StackArray()
        {
            stackElements = new int[10];
        }

        public void Push(int value)
        {
            if (counter == stackElements.Length)
            {
                Resize();
            }

            stackElements[counter] = value;
            counter++;
            IsEmpty = false;
            
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
            IsEmpty = counter == 0;
            return value;
        }

        public int Peek() => stackElements[counter - 1];

        public void Clear()
        {
            stackElements = new int[10];
            counter = 0;
            IsEmpty = true;
        }
    }
}
