using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Lec5Lib
{
    public class DecMD5 : Decorator
    {
        public DecMD5(IWriter writer): base(writer) { }
        public override string? Save(string? message)
        {
            if (message != null)
            {
                // Вычисляем хеш-код сообщения с помощью MD5
                byte[] hash = MD5.Create().ComputeHash(Encoding.UTF8.GetBytes(message));

                // Преобразуем хеш-код в строку и добавляем его к сообщению
                string hashedMessage = message + Constant.Delimiter + Convert.ToBase64String(hash);

                // Сохраняем зашифрованное сообщение с помощью декорируемого объекта-писателя
                return writer?.Save(hashedMessage);
            }

            return null;
        }
    }
}
