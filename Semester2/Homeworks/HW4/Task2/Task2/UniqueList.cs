using Task2.Exceptions;

namespace Task2
{
    /// <summary>
    /// The List that does not contain duplicate values.
    /// </summary>
    public class UniqueList : List
    {
        /// <summary>
        /// Adds an element that is not in the list.
        /// </summary>
        /// <param name="value">Value to add</param>
        /// <param name="position">The zero-based position of the element to add</param>
        /// <exception cref="AddingExistingElementException">Thrown when trying to add a duplicate value</exception>
        public override void AddValue(int value, int position)
        {
            if (Contains(value))
            {
                throw new AddingExistingElementException();
            }

            base.AddValue(value, position);
        }

        /// <summary>
        /// Sets the value of element by position.
        /// </summary>
        /// <param name="value">New value that is not in the list</param>
        /// <param name="position">The zero-based position of the element to set value</param>
        /// <exception cref="AddingExistingElementException">Thrown when trying to set a duplicate value</exception>
        public override void SetValue(int value, int position)
        {
            if (Contains(value))
            {
                if (PositionOf(value) == position)
                {
                    return;
                }
                throw new AddingExistingElementException();
            }

            base.SetValue(value, position);
        }
    }
}
