namespace Task2
{
    /// <summary>
    /// Interface for hash function.
    /// </summary>
    public interface IHashFunction
    {
        /// <summary>
        /// Function that converts a string value to a numeric value.
        /// </summary>
        /// <param name="value">String value</param>
        /// <returns>Hash - a numeric value</returns>
        public int Hash(string value);
    }
}
