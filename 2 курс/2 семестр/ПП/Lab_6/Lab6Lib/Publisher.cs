using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6Lib
{
    public class Publisher
    {
        private List<ISubscriber> subscribers = new List<ISubscriber>(); // список подписчиков
        private string eventName; // имя события

        public Publisher(string eventName)
        {
            this.eventName = eventName;
        }

        public void subscribe(ISubscriber sub)
        {
            subscribers.Add(sub); // добавляем подписчика в список
        }

        public bool unsubscribe(ISubscriber sub)
        {
            return subscribers.Remove(sub); // удаляем подписчика из списка и возвращаем true, если он был удален
        }

        public int nonify()
        {
            int count = 0; // счетчик уведомленных подписчиков
            foreach (ISubscriber sub in subscribers) // для каждого подписчика в списке
            {
                sub.update(eventName); // вызываем метод update, передавая имя события
                count++; // увеличиваем счетчик
            }
            return count; // возвращаем количество уведомленных подписчиков
        }


    }

}
