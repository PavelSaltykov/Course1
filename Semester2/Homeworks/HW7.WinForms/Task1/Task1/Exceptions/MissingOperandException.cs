using System;

namespace Task1.Exceptions
{
    [Serializable]
    public class MissingOperandException : Exception
    {
        public MissingOperandException() { }

        public MissingOperandException(string message) : base(message) { }
        
        public MissingOperandException(string message, Exception inner) : base(message, inner) { }
        
        protected MissingOperandException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
