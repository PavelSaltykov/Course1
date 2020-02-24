namespace Task3
{
    interface IStack
    {
        void Push(int value);

        int Pop();

        int Peek();

        void Clear();
    }
}
