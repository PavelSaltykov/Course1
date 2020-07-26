using System;

namespace Task2.Exceptions
{
    [Serializable]
    public class InvalidPositionException : Exception
    {
        public InvalidPositionException() { }

        public InvalidPositionException(string message) : base(message) { }
        
        public InvalidPositionException(string message, Exception inner) : base(message, inner) { }
        
        protected InvalidPositionException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
