using Task2.Exceptions;

namespace Task2
{
    public class UniqueList : List
    {
        public override void AddValue(int value, int position)
        {
            if (Contains(value))
            {
                throw new AddingExistingElementException();
            }

            base.AddValue(value, position);
        }

        public override void SetValue(int value, int position)
        {
            if (Contains(value))
            {
                if (IndexOf(value) == position)
                {
                    return;
                }
                throw new AddingExistingElementException();
            }

            base.SetValue(value, position);
        }
    }
}
