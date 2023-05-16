using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6Lib
{
    public class SubscriberA : ISubscriber
    {
        public void update(string eventname)
        {
            Console.WriteLine(string.Format("Subscriber:{0}, Event:{1}", "A", eventname));
        }
    }
}
