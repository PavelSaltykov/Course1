using System;

namespace Task2
{
    /// <summary>
    /// Hash table, collection of string values.
    /// </summary>
    public class HashTable
    {
        private int size;
        private int amountOfElements;
        private IHashFunction hashFunction;
        private List[] buckets;

        /// <summary>
        /// Initializes a new instance of the <see cref="HashTable"/> class.
        /// </summary>
        /// <param name="hashFunction">Hash function</param>
        public HashTable(IHashFunction hashFunction)
        {
            this.hashFunction = hashFunction;
            size = 20;
            CreateBuckets();
        }

        private void CreateBuckets()
        {
            buckets = new List[size];
            for (var i = 0; i < size; ++i)
            {
                buckets[i] = new List();
            }
        }

        private List TransferAllValuesToList()
        {
            var newList = new List();
            foreach (var list in buckets)
            {
                while (!list.IsEmpty)
                {
                    var value = list.DeleteFromHead();
                    newList.AddToList(value);
                }
            }
            return newList;
        }

        private void TransferValuesFromListToTable(List list)
        {
            while (!list.IsEmpty)
            {
                AddToTable(list.DeleteFromHead());
            }
        }

        private void Resize()
        {
            var tempList = TransferAllValuesToList();

            size *= 2;
            CreateBuckets();

            TransferValuesFromListToTable(tempList);
        }

        private int GetCorrectHash(string value) => Math.Abs(hashFunction.Hash(value)) % size;

        private void AddToTable(string value)
        {
            var hash = GetCorrectHash(value);
            buckets[hash].AddToList(value);
        }

        /// <summary>
        /// Adds value to hash table.
        /// </summary>
        /// <param name="value">Value to add</param>
        public void AddValue(string value)
        {
            AddToTable(value);
            amountOfElements++;

            if ((float)amountOfElements / size > 1)
            {
                Resize();
            }
        }

        /// <summary>
        /// Deletes value from the hash table.
        /// </summary>
        /// <param name="value">Value for deletion</param>
        /// <returns>True if value was delete</returns>
        public bool DeleteValue(string value)
        {
            var hash = GetCorrectHash(value);
            var valueDeleted = buckets[hash].Delete(value);
            if (valueDeleted)
            {
                amountOfElements--;
            }
            return valueDeleted;
        }

        /// <summary>
        /// Сhecks if the hash table contains a value.
        /// </summary>
        /// <param name="value">Value to check</param>
        /// <returns>True if the hash table contains value</returns>
        public bool Contains(string value)
        {
            var hash = GetCorrectHash(value);
            return buckets[hash].Contains(value);
        }

        /// <summary>
        /// Changes the hash function.
        /// </summary>
        /// <param name="newHashFunction">New hash function</param>
        public void ChangeHashFunction(IHashFunction newHashFunction)
        {
            var tempList = TransferAllValuesToList();
            hashFunction = newHashFunction;
            TransferValuesFromListToTable(tempList);
        }

        /// <summary>
        /// Removes all elements from the hash table.
        /// </summary>
        public void Clear()
        {
            size = 20;
            amountOfElements = 0;
            CreateBuckets();
        }
    }
}