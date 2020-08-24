using System;

namespace Task1.Exceptions
{
    /// <summary>
    /// The exception that is thrown when there is not operand to perform an operation.
    /// </summary>
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
