using System;

namespace Task1.Operations
{
    public class Division : Operation
    {
        public override int Calculate() => LeftChild.Calculate() / RightChild.Calculate();

        public override void Print()
        {
            Console.Write("/ ");
            base.Print();
        }
    }
}
