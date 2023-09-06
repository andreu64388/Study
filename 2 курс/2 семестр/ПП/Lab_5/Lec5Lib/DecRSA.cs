using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Security.Cryptography;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Lec5Lib
{
    public class DecRSA : Decorator // RSA-шифровать хэш
    {
        public DecRSA(IWriter writer):base(writer) { }

        public override string? Save(string message)
        {
            // Генерация ключей RSA
            string publicKeyXml;
            byte[] encyptedData;
            message = message ?? string.Empty;
            int k1 = message.IndexOf(Constant.Delimiter);
            if (k1 == -1) throw new Exception("delimiter not found");
            string xs = message.Substring(0, k1);
            string xsbhcs = message.Substring(k1 + 1);
            // Вычисление хеша
            byte[] xsbhc = Convert.FromBase64String(xsbhcs);
            using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
            {
                publicKeyXml = rsa.ToXmlString(true);
                rsa.ImportParameters(rsa.ExportParameters(false));
                encyptedData = rsa.Encrypt(xsbhc, false);
            }

            // Запись в файл
            string result = $"{xs}{Lec5Lib.Constant.Delimiter}{Convert.ToBase64String(encyptedData)}{Lec5Lib.Constant.Delimiter}{publicKeyXml}";
            return writer.Save(result);
        }
       
    }
}
