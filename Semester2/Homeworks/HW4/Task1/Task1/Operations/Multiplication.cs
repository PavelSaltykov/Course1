using System;

namespace Task1.Operations
{
    public class Multiplication : Operation
    {
        public override int Calculate() => LeftChild.Calculate() * RightChild.Calculate();

        public override void Print()
        {
            Console.Write("* ");
            base.Print();
        }
    }
}
