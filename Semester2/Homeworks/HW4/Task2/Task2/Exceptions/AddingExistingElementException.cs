using System;

namespace Task2.Exceptions
{
    /// <summary>
    /// The exception that is thrown when trying to add an element that already exists in the list.
    /// </summary>
    [Serializable]
    public class AddingExistingElementException : Exception
    {
        public AddingExistingElementException() { }

        public AddingExistingElementException(string message) : base(message) { }

        public AddingExistingElementException(string message, Exception inner) : base(message, inner) { }
        
        protected AddingExistingElementException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
