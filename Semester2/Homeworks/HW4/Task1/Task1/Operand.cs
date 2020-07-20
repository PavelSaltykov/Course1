using System;

namespace Task1
{
    public class Operand : INode
    {
        public int Value { get; set; }
        public INode LeftChild { get; set; }
        public INode RightChild { get; set; }

        public int Calculate() => Value;

        public void Print()
        {
            Console.Write($"{Value} ");
        }
    }
}
