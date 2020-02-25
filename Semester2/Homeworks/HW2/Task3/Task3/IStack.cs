namespace Task3
{
    interface IStack
    {
        bool IsEmpty();

        void Push(int value);

        int Pop();

        void Clear();
    }
}
