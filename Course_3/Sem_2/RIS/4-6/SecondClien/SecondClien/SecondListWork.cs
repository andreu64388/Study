using DatabaseClasses.Pattern;
using Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SecondClient
{
    public class SecondListWork
    {
        private static List<Data> _datas = new List<Data>();
        private static object locker = new();
        public static void AddElementsIntoList()
        {
            lock (locker)
            {
                using (UnitOfWork unitOfWork = new UnitOfWork("SecondDBConnect"))
                {
                    _datas = new List<Data>(unitOfWork.DataRepository.GetItems());
                }
            }
        }

        public static int GetLength()
        {
            int count;
            AddElementsIntoList();
            lock (locker)
            {
                count = _datas.Count;
                Thread.Sleep(100);
            }

            return count;
        }

        public static Data GetElement()
        {
            Data data = null;
            AddElementsIntoList();
            lock (locker)
            {
                if (_datas.Count != 0)
                {
                    data = new Data { Id = _datas[0].Id, Time = _datas[0].Time };

                    using (UnitOfWork unitOfWork = new UnitOfWork("SecondDBConnect"))
                    {
                        _datas[0].ItNew = false;
                        unitOfWork.DataRepository.UpdateItem(_datas[0]);
                        unitOfWork.Save();
                    }
                    _datas.Remove(_datas[0]);
                }
            }

            return data;
        }
    }
}
