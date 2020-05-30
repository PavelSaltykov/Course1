namespace Task2.HashFunctions
{
    public class HashFunction2 : IHashFunction
    {
        public int Hash(string value)
        {
            var result = 0;
            foreach (var symbol in value)
            {
                result += symbol;
            }
            return result;
        }
    }
}
