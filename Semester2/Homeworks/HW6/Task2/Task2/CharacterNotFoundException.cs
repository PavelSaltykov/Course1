using System;

namespace Task2
{
    /// <summary>
    /// The exception that is thrown when the map from the file does not contain the character symbol.
    /// </summary>
    [Serializable]
    public class CharacterNotFoundException : Exception
    {
        public CharacterNotFoundException() { }

        public CharacterNotFoundException(string message) : base(message) { }
        
        public CharacterNotFoundException(string message, Exception inner) : base(message, inner) { }
        
        protected CharacterNotFoundException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
