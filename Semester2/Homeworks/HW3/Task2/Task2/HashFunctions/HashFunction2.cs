namespace Task2.HashFunctions
{
    /// <summary>
    /// Сlass that implements a hash function.
    /// </summary>
    public class HashFunction2 : IHashFunction
    {
        /// <summary>
        /// Hash function for strings, returns sum of numerical values ​​of all symbols.
        /// </summary>
        /// <param name="value">String value</param>
        /// <returns>Hash - numeric value</returns>
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
