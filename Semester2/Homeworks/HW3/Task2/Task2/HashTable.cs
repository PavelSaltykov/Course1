using System;

namespace Task2
{
    public class HashTable
    {
        private int size;
        private int amountOfElements;
        private IHashFunction hashFunction;
        private List[] buckets;

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

        public void AddValue(string value)
        {
            AddToTable(value);
            amountOfElements++;

            if ((float)amountOfElements / size > 1)
            {
                Resize();
            }
        }

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

        public bool Contains(string value)
        {
            var hash = GetCorrectHash(value);
            return buckets[hash].Contains(value);
        }

        public void ChangeHashFunction(IHashFunction newHashFunction)
        {
            var tempList = TransferAllValuesToList();
            hashFunction = newHashFunction;
            TransferValuesFromListToTable(tempList);
        }

        public void Clear()
        {
            size = 20;
            amountOfElements = 0;
            CreateBuckets();
        }
    }
}