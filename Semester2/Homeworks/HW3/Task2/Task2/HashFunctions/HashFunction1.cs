namespace Task2.HashFunctions
{
    public class HashFunction1 : IHashFunction
    {
        public int Hash(string value)
        {
            return value[0];
        }
    }
}
