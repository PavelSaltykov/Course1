using System;

namespace Task1.Exceptions
{
    /// <summary>
    /// The exception that is thrown when the sign does not match any operation.
    /// </summary>
    [Serializable]
    public class InvalidOperationSignException : Exception
    {
        public InvalidOperationSignException() { }

        public InvalidOperationSignException(string message) : base(message) { }
        
        public InvalidOperationSignException(string message, Exception inner) : base(message, inner) { }
        
        protected InvalidOperationSignException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
