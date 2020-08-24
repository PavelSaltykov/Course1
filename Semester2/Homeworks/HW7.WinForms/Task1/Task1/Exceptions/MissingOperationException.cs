using System;

namespace Task1.Exceptions
{
    /// <summary>
    /// The exception that is thrown when there is not operation to perform an operation.
    /// </summary>
    [Serializable]
    public class MissingOperationException : Exception
    {
        public MissingOperationException() { }
        
        public MissingOperationException(string message) : base(message) { }
        
        public MissingOperationException(string message, Exception inner) : base(message, inner) { }
        
        protected MissingOperationException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
