namespace Task2.HashFunctions
{
    /// <summary>
    /// Сlass that implements a hash function.
    /// </summary>
    public class HashFunction1 : IHashFunction
    {
        /// <summary>
        /// Hash function for strings, returns the numerical value of the first symbol.
        /// </summary>
        /// <param name="value">String value</param>
        /// <returns>Hash - numeric value</returns>
        public int Hash(string value)
        {
            return value[0];
        }
    }
}
