using System.Security.Cryptography;
using System.Text;
using System.Xml;
using System.Xml.Linq;
using Lec5Lib;

namespace lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Лабораторная работа # 5");
            // ------ УСПЕШНО --------------------------------------------------

            {
                IWriter writer = new StrWriter();
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecSHA512(rsa);
                string? result = hash.Save("AAAAABBBBCCCCC");

                bool testresult = testSHA512_SA(result, Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 1, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new FileWriter("test2.txt");
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecSHA512(rsa);
                string? result = hash.Save("BBBBCCCCC");

                StreamReader reader = new StreamReader(result);
                string? message = reader.ReadLine();
                reader.Close();
                bool testresult = testSHA512_SA(message, Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 2, testresult ? "успешно" : "НЕ успешно"));

            }
            {
                IWriter writer = new StrWriter();
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecMD5(rsa);
                string? result = hash.Save("AAAAACCCCBBBBB");

                bool testresult = testMD5_SA(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 3, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new FileWriter("test4.txt");
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecMD5(rsa);
                string? result = hash.Save("AAAAABBBBDDDDDCCCCC");

                StreamReader reader = new StreamReader(result);
                string? message = reader.ReadLine();
                bool testresult = testMD5_SA(message, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 4, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new StrWriter();
                IWriter hash = new DecSHA512(writer);
                string? result = hash.Save("AAAAAEEEEEBBBBCCCCC");

                bool testresult = testSHA512(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 5, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new StrWriter();
                IWriter hash = new DecMD5(writer);
                string? result = hash.Save("AAAAABBBBCCCCCHHHH");

                bool testresult = testMD5(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 6, testresult ? "успешно" : "НЕ успешно"));
            }

            {
                IWriter writer = new FileWriter();
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecSHA512(rsa);
                string? result = hash.Save("AAAAABBBBDDDDDCCCCC");

                StreamReader reader = new StreamReader(result);
                string? message = reader.ReadLine();
                bool testresult = testSHA512_SA(message, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 7, testresult ? "успешно" : "НЕ успешно"));
            }



            // ------  НЕ УСПЕШНО --------------------------------------------------
            {
                IWriter writer = new StrWriter();
                IWriter hash = new DecSHA512(writer);
                string? result = hash.Save("AAAAABBBBCCCCC");

                bool testresult = testMD5(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 8, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new StrWriter();
                IWriter hash = new DecSHA512(writer);
                string? result = hash.Save(string.Format("{0}{1}{2}", "AAAAA", Lec5Lib.Constant.Delimiter, "BBBBCCCCC"));  // разделитель в тексте

                bool testresult = testSHA512(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 9, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new StrWriter();
                IWriter hash = new DecMD5(writer);
                string? result = hash.Save(string.Format("{0}{1}{2}", "AAAAA", Lec5Lib.Constant.Delimiter, "BBBBCCCCC"));
                bool testresult = testSHA512(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 10, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new StrWriter();
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecMD5(rsa);
                string? result = hash.Save("HHHAAAAABBBBCCCCC");

                bool testresult = testSHA512_SA(result, Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 11, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new FileWriter("test12.txt");
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecSHA512(rsa);
                string? result = hash.Save("BBBBCCCCC");


                StreamReader reader = new StreamReader(result);
                string? message = reader.ReadLine();
                bool testresult = testSHA512_SA("BBBBXCCCC", Lec5Lib.Constant.Delimiter);
                Console.WriteLine(string.Format("тест {0} - {1} ", 12, testresult ? "успешно" : "НЕ успешно"));
            }
            {
                IWriter writer = new FileWriter("test13.txt");
                IWriter rsa = new DecRSA(writer);
                IWriter hash = new DecMD5(rsa);
                string? result = hash.Save("BBBBCCCCC");

                StreamReader reader = new StreamReader(result);
                string? message = reader.ReadLine();
                bool testresult = testSHA512_SA(message, Lec5Lib.Constant.Delimiter);

                Console.WriteLine(string.Format("тест {0} - {1} ", 13, testresult ? "успешно" : "НЕ успешно"));
            }
        }

        static bool testSHA512(string? message, char delimiter = '\uffff')
        {
            bool rc = false;
            try
            {
                message = message ?? string.Empty;
                int k1 = message.IndexOf(delimiter);
                if (k1 == -1) throw new Exception("delimiter not found");
                string xs = message.Substring(0, k1);
                string xsbhcs = message.Substring(k1 + 1);
                byte[] xsbhc = Convert.FromBase64String(xsbhcs);
                rc = eqSHA512(xs, xsbhc);
            }
            catch (Exception ex)
            {
                Console.WriteLine(string.Format("testSHA512: {0}", ex.Message));
            }
            return rc;
        }
        static bool testMD5(string? message, char delimiter = '\uffff')
        {
            bool rc = false;
            try
            {
                message = message ?? string.Empty;
                int k1 = message.IndexOf(delimiter);
                if (k1 == -1) throw new Exception("delimiter not found");
                string xs = message.Substring(0, k1);
                string xsbhcs = message.Substring(k1 + 1);
                byte[] xsbhc = Convert.FromBase64String(xsbhcs);
                rc = eqMD5(xs, xsbhc);
            }
            catch (Exception ex)
            {
                Console.WriteLine(string.Format("testMD5: {0}", ex.Message));
            }
            return rc;

        }
        static bool testSHA512_SA(string? message, char delimiter = '\uffff')
        {
            bool rc = false;
            try
            {
                message = message ?? string.Empty;
                int k1 = message.IndexOf(delimiter);
                int k2 = message.IndexOf(delimiter, k1 + 1);
                if (k1 == -1 || k2 == -1) throw new Exception("delimiter not found");
                string xs = message.Substring(0, k1);
                string xsbhcs = message.Substring(k1 + 1, k2 - k1 - 1);
                string xparam = message.Substring(k2 + 1);
                byte[] xsbh = deRSA(xsbhcs, xparam);
                rc = eqSHA512(xs, xsbh);
            }
            catch (Exception ex)
            {
                Console.WriteLine(string.Format("testSHA512_SA: {0}", ex.Message));
            }
            return rc;
        }

        static bool testMD5_SA(string? message, char delimiter = '\uffff')
        {
            bool rc = false;
            try
            {
                message = message ?? string.Empty;
                int k1 = message.IndexOf(delimiter);
                int k2 = message.IndexOf(delimiter, k1 + 1);
                if (k1 == -1 || k2 == -1) throw new Exception("delimiter not found");
                string xs = message.Substring(0, k1);
                string xsbhcs = message.Substring(k1 + 1, k2 - k1 - 1);
                string xparam = message.Substring(k2 + 1);
                byte[] xsbh = deRSA(xsbhcs, xparam);
                rc = eqMD5(xs, xsbh);
            }
            catch (Exception ex)
            {
                Console.WriteLine(string.Format("testMD5_SA: {0}", ex.Message));
            }
            return rc;
        }



        static byte[] deRSA(string sbhcs, string xmlparam)
        {
            byte[] rc = { };
            try
            {
                byte[] xsbhc = Convert.FromBase64String(sbhcs);
                using (RSACryptoServiceProvider rsa = new RSACryptoServiceProvider())
                {

                    rsa.FromXmlString(xmlparam);

                    rc = rsa.Decrypt(xsbhc, false);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(string.Format("deRSA: {0}", ex.Message));
            }
            return rc;
        }
        static bool eqMD5(string s, byte[] hash)
        {
            bool rc = true;
            s = s ?? string.Empty;
            byte[] sb = Encoding.ASCII.GetBytes(s);
            MD5 md5 = MD5.Create();
            byte[] sbh = md5.ComputeHash(sb);
            rc = sbh.SequenceEqual(hash);
            return rc;
        }

        static bool eqSHA512(string s, byte[] hash)
        {
            bool rc = true;
            s = s ?? string.Empty;
            byte[] sb = Encoding.ASCII.GetBytes(s);
            SHA512 sha512 = SHA512.Create();
            byte[] sbh = sha512.ComputeHash(sb);
            rc = sbh.SequenceEqual(hash);
            return rc;
        }
    }
}