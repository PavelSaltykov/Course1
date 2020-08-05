using System;

namespace Task2
{
    /// <summary>
    /// The exception that is thrown when there is more than one character on the map.
    /// </summary>
    [Serializable]
    public class MoreThanOneCharacterException : Exception
    {
        public MoreThanOneCharacterException() { }

        public MoreThanOneCharacterException(string message) : base(message) { }

        public MoreThanOneCharacterException(string message, Exception inner) : base(message, inner) { }
        
        protected MoreThanOneCharacterException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
