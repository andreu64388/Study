using System;
using System.Collections.Generic;
using System.Text;
using System.Security.Cryptography;

namespace OIB8;

static class Encryptor
{
    public static string Encrypt(string plainText, out string keyBase64, out string vectorBase64)
    {
        using (Aes aesAlgorithm = Aes.Create())  
        {

            aesAlgorithm.KeySize = 128; 

            Console.WriteLine($"Aes режим шифрофания : {aesAlgorithm.Mode}");
            Console.WriteLine($"Aes кежим заполение: {aesAlgorithm.Padding}");  
            Console.WriteLine($"Aes размер ключа : {aesAlgorithm.KeySize}");  
            Console.WriteLine($"Aes  размер блока : {aesAlgorithm.BlockSize}");


            keyBase64 = Convert.ToBase64String(aesAlgorithm.Key); // Key - ключ шифрования
            vectorBase64 = Convert.ToBase64String(aesAlgorithm.IV); // IV - вектор инициализации нужен для того чтобы шифровать и расшифровывать данные
            File.WriteAllText("encryptKey.txt", keyBase64);
            File.WriteAllText("Ivector.txt", vectorBase64);
            
            ICryptoTransform encryptor = aesAlgorithm.CreateEncryptor();

            byte[] encryptedData;

         
            using (MemoryStream ms = new MemoryStream()) 
            {
                using (CryptoStream cs = new CryptoStream(ms, encryptor, CryptoStreamMode.Write))
                {
                    using (StreamWriter sw = new StreamWriter(cs))
                    {
                        sw.Write(plainText);
                    }
                    encryptedData = ms.ToArray();
                }
            }
            File.WriteAllText("encryptedData.txt", Convert.ToBase64String(encryptedData));
            return Convert.ToBase64String(encryptedData);
        }

    }
    public static string Decrypte(string cipherText, string keyBase64, string vectorBase64)
    {
        using (Aes aesAlgorithm = Aes.Create())
        {
            aesAlgorithm.Key = Convert.FromBase64String(keyBase64);
            aesAlgorithm.IV = Convert.FromBase64String(vectorBase64); 

            
            Console.WriteLine($"Aes режим шифрофания : {aesAlgorithm.Mode}");
            Console.WriteLine($"Aes кежим заполение: {aesAlgorithm.Padding}");
            Console.WriteLine($"Aes размер ключа : {aesAlgorithm.KeySize}");
            Console.WriteLine($"Aes  размер блока : {aesAlgorithm.BlockSize}");


            ICryptoTransform decryptor = aesAlgorithm.CreateDecryptor();

            byte[] cipher = Convert.FromBase64String(cipherText);

            
            using (MemoryStream ms = new MemoryStream(cipher))
            {
                using (CryptoStream cs = new CryptoStream(ms, decryptor, CryptoStreamMode.Read)) // режим для чтения данных
                {
                    using (StreamReader sr = new StreamReader(cs)) 
                    {
                        return sr.ReadToEnd();
                    }
                }
            }
        }
    }
}
class Program {
   static void Main(string[] args)
    {
        Console.WriteLine("Введите текст который вы хотите зашифровать:");
        string message = Console.ReadLine();
        
        string cipherText = Encryptor.Encrypt(message, out string keyBase64, out string vectorBase64);

       
        Console.WriteLine(cipherText);

        Console.WriteLine("Ключ шифрование в виде строки:");
        
        Console.WriteLine(keyBase64);

        Console.WriteLine("Вектор инициализации (IV) в виде строки:");
        
        Console.WriteLine(vectorBase64);

        Console.WriteLine("Расшифрованное сообщение: "+Encryptor.Decrypte(cipherText, keyBase64, vectorBase64));

        Console.WriteLine("Вычесленый хэш из файла hashmessage.txt: "+ GetHash());


    }

    static string GetHash(string? input = null)
    {
        input = input ?? File.ReadAllText("hashmessage.txt");
        SHA384 sha = new SHA384Managed();
        var hash = sha.ComputeHash(Encoding.UTF8.GetBytes(input));
        File.WriteAllBytes("hashedInBytes.txt", hash);
        File.WriteAllText("hashedInString", Convert.ToBase64String(hash));
        return Convert.ToBase64String(hash);
    }
}

