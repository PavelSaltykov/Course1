namespace Task3
{
    class StackList : IStack
    {
        private StackElement top;

        public bool IsEmpty { get; private set; } = true;

        private class StackElement
        {
            public int value;
            public StackElement next;

            public StackElement(int value, StackElement next)
            {
                this.value = value;
                this.next = next;
            }
        }

        public void Push(int value)
        {
            top = new StackElement(value, top);
            IsEmpty = false;
        }

        public int Pop()
        {
            int value = top.value;
            top = top.next;
            IsEmpty = top == null;
            return value;
        }

        public int Peek() => top.value;

        public void Clear()
        {
            top = null;
            IsEmpty = true;
        }
    }
}
