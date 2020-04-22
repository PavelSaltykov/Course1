namespace Task3
{
    public interface IStack
    {
        bool IsEmpty();

        void Push(int value);

        int Pop();

        void Clear();
    }
}
