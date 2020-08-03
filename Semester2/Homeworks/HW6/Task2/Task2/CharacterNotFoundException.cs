using System;

namespace Task2
{
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
