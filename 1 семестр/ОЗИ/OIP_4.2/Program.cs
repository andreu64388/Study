
//Написать программу, которая получит общий секретный ключ из доступных публичных ключей с помощью алгоритма Диффи-Хеллмана.
//Генерируйте секретный ключ Алисы и Боба, и высчитайте секретный ключ, удостоверьтесь что его одинаково смогут получить и Алиса и Боб.

using System;
using System.Collections.Generic;

namespace ЛР__6._1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> Keys = new List<int>();
            Random rand = new Random();
            for (int i = 0; i < 2; i++)
                Keys.Add(rand.Next(1, 30));
            for (int i = 0; i < 2; i++)
                Keys.Add(rand.Next(1, 10));

            GetSecretKey(Keys[0], Keys[1], Keys[2], Keys[3]);
            //GetSecretKey(5, 23, 4, 3);

        }
        public static void GetSecretKey(int g, int p, int a, int b)
        {

            int A = Power(g, a, p);
            int B = Power(g, b, p);

            int K1 = Power(B, a, p);
            int K2 = Power(A, b, p);

            int SecretKey = Power(g, a * b, p);

            if (K1 == K2 && SecretKey == K1)
                Console.WriteLine($"Ключи равны!\nSecretKey = {SecretKey}\nK1 = {K1}\nK2 = {K2}");
            else
                Console.WriteLine($"Ключи не равны!\nSecretKey = {SecretKey}\nK1 = {K1}\nK2 = {K2}");
            Console.WriteLine(Power(2, 7, 37));
            Console.ReadKey(true);

        }
        public static int Power(int a, int b, int n)
        {
            int tmp = a;
            int sum = tmp;
            for (int i = 1; i < b; i++)
            {
                for (int j = 1; j < a; j++)
                {
                    sum += tmp;
                    if (sum >= n)
                    {
                        sum -= n;
                    }
                }
                tmp = sum;
            }
            return tmp;

        }
    }
}


    class Program
    {
        static void Mains(string[] args)
        {
            Random rnd = new Random();
            int p = 31;
            int q = 7;
            int e = 47;
            int msg = rnd.Next(5, 100);


            int n = p * q;

            int EulerFunction = (p - 1) * (q - 1);

            int d = modinv(e, EulerFunction);

            // Keys
            e = 7;
            n = 533;
            d = 343;

            List<int> OpenKey = new List<int>();
            OpenKey.Add(e);
            OpenKey.Add(n);

            List<int> SecretKey = new List<int>();
            SecretKey.Add(d);
            SecretKey.Add(n);

            Console.WriteLine("Число p: " + p);
            Console.WriteLine("Число q: " + q);
            Console.WriteLine("Открытая экспонента: " + e);
            Console.WriteLine("Закрытая экспонента: " + d);
            Console.WriteLine("Сообщение: " + msg);
            Console.WriteLine("Зашифрованное сообщение: " + Encrypt(OpenKey, msg));
            Console.WriteLine("Расшифрованное сообщени: " + Decrypt(SecretKey, Encrypt(OpenKey, msg)));
            Console.ReadKey(true);
        }
        public static int? GetPrime(int start, int end)
        {
            List<int> Primes = new List<int>();

            for (int i = start; i <= end; i++)
            {
                bool b = true;
                for (int j = 2; j < i / 2; j++)
                {
                    if (i % j == 0 & i % 1 == 0)
                    {
                        b = false;
                    }
                }
                if (b)
                {
                    Primes.Add(i);
                }
            }
            if (Primes.Count == 0)
                return null;
            else
            {
                Random rnd = new Random();
                return Primes[rnd.Next(0, Primes.Count)];
            }
        }
        public static int Encrypt(List<int> OpenKey, int msg)
        {
            return Modpow(msg, OpenKey[0], OpenKey[1]);
        }
        public static int Decrypt(List<int> SecretKey, int msg)
        {
            return Modpow(msg, SecretKey[0], SecretKey[1]);
        }
        public static int Modpow(int Base, int exp, int modulus)
        {
            Base %= modulus;
            int result = 1;
            while (exp > 0)
            {
                if ((exp & 1) != 0) result = (result * Base) % modulus;
                Base = (Base * Base) % modulus;
                exp >>= 1;
            }
            return result;
        }
        public static int modinv(int u, int v)
        {
            int inv, u1, u3, v1, v3, t1, t3, q;
            int iter;
            u1 = 1;
            u3 = u;
            v1 = 0;
            v3 = v;
            iter = 1;
            while (v3 != 0)
            {
                q = u3 / v3;
                t3 = u3 % v3;
                t1 = u1 + q * v1;
                u1 = v1;
                v1 = t1;
                u3 = v3;
                v3 = t3;
                iter = -iter;
            }
            if (u3 != 1)
                return 0;
            if (iter < 0)
                inv = v - u1;
            else
                inv = u1;
            return inv;
        }
    }
