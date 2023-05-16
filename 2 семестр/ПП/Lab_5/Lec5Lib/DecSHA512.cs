using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Lec5Lib
{
    public class DecSHA512 : Decorator //вычисление хэша sha512
    {
        public DecSHA512(IWriter writer) : base(writer) { }
       public override string? Save(string? message) //формирование сообщения
        {
            if (message != null)
            {
                // Вычисляем хеш-код сообщения с помощью sha512
                byte[] hash = SHA512.Create().ComputeHash(Encoding.UTF8.GetBytes(message));

                // Преобразуем хеш-код в строку и добавляем его к сообщению
                string hashedMessage = message + Constant.Delimiter + Convert.ToBase64String(hash);

                // Сохраняем зашифрованное сообщение с помощью декорируемого объекта-писателя
                return writer?.Save(hashedMessage);
            }
            return null;
       }
    }
}
