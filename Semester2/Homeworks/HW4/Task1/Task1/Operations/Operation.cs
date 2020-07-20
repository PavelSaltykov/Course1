namespace Task1.Operations
{
    public abstract class Operation : INode
    {
        public INode LeftChild { get; set; }
        public INode RightChild { get; set; }

        public abstract int Calculate();

        public virtual void Print()
        {
            LeftChild?.Print();
            RightChild?.Print();
        }
    }
}
