using System.Text.RegularExpressions;

namespace lab6;
class IPM
{
    #region Fields

    private string ip;
    private string mask;
    private Info ipInfo;

    #endregion

    #region Props

    public string? IP
    {
        get => ip;
        set
        {
            if (value is null)
            {
                throw new ArgumentNullException(nameof(value));
            }
            ip = value;
        }
    }

    public string? Mask
    {
        get => mask;
        set => mask = value ??
                      throw new ArgumentNullException(nameof(value));
    }

    public Info IPInfo => ipInfo;

    #endregion

    #region Ctors

    public IPM()
    {
        ip = "";
        mask = "";
    }

    public IPM(string? ip,
               string? mask)
    {
        IP = ip;
        Mask = mask;

        if (CheckIP(IP, Mask))
        {
            Calculate(IP, Mask);
        }
    }

    #endregion

    #region Methods

    public static bool CheckIP(string ip,
                               string mask)
    {
        Regex regex = new(@"[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}");

        if (!regex.IsMatch(ip))
        {
            return false;
        }

        return CheckNumbersInIP(ip, mask);
    }

    private static bool CheckNumbersInIP(string ip, string mask)
    {
        var numsIp = ip.Split(".");
        var numsMask = mask.Split(".");

        if (!CheckNums(numsIp, numsMask))
        {
            return false;
        }

        IpClass ic = GetClass(numsIp[0]);

        if (!CheckMask(numsMask, ic))
        {
            return false;
        }

        return true;
    }

    private static bool CheckNums(string[] numsIp,
                                  string[] numsMask)
    {
        int numIp = int.Parse(numsIp[0]),
            numM;

        if (numIp is (< 1 or > 247))
        {
            throw new Exception("Нельзя подобрать класс для данного IP");
        }

        for (byte i = 0; i < numsIp.Length; i++)
        {
            numIp = int.Parse(numsIp[i]);
            numM = int.Parse(numsMask[i]);

            if (
                (numIp < 0 || numM > 255) ||
                (numM < 0 || numM > 255))
            {
                return false;
            }
        }

        return true;
    }

    private static IpClass GetClass(string first)
    {
        var num = int.Parse(first);

        IpClass ic = num switch
        {
            >= 1 and <= 126 => IpClass.A,
            >= 128 and <= 191 => IpClass.B,
            >= 192 and <= 223 => IpClass.C,
            >= 224 and <= 239 => IpClass.D,
            >= 240 and <= 247 => IpClass.E,
            < 1 or > 247 => IpClass.None
        };

        if (ic is IpClass.None)
        {
            throw new Exception("Нельзя опознать класс для данного айпи");
        }

        return ic;
    }

    private static bool CheckMask(string[] numsM,  IpClass ic)
    {

        string binMask = string.Empty;
        string binView;
        int num;

        foreach (string el in numsM)
        {
            num = int.Parse(el);
            binView = Convert.ToString(num, 2);

            while (binView.Length != 8)
            {
                binView = "0" + binView;
            }

            binMask += binView;
        }

        if (binMask.Contains("01"))
        {
            throw new Exception("Ошибка маски");
            return false;
            
        }

        return true;
    }

    public void Calculate(string IP,
                          string Mask)
    {
        string ip;
        string mask;
        string ipHost;
        string ipNetwork;
        string ipBroadcast;

        string[] numsM = Mask.Split('.');
        string[] numsIp = IP.Split('.');

        string binMask = string.Empty;
        string binView;
        int num;

        foreach (string el in numsM)
        {
            num = int.Parse(el);
            binView = Convert.ToString(num, 2);

            while (binView.Length != 8)
            {
                binView = "0" + binView;
            }

            binMask += binView;
        }

        mask = binMask;

        binMask = String.Empty;

        foreach (string el in numsIp)
        {
            num = int.Parse(el);
            binView = Convert.ToString(num, 2);

            while (binView.Length != 8)
            {
                binView = "0" + binView;
            }

            binMask += binView;
        }

        ip = binMask;

        ipNetwork = And(ip, mask);
        ipHost = And(ip, Invert(mask));
        ipBroadcast = Or(And(ip, mask), Invert(mask));

        ipInfo = new(IP, Mask, ConvertToD(ipHost), ConvertToD(ipNetwork), ConvertToD(ipBroadcast));
    }

    private static string And(string el1,
                              string el2)
    {
        string result = string.Empty;

        for (byte i = 0; i < el1.Length; i++)
        {
            if (el1[i] == el2[i] && el1[i] == '1')
            {
                result += '1';
            }
            else
            {
                result += '0';
            }
        }

        return result;
    }

    private static string Invert(string el1)
    {
        string result = string.Empty;

        for (byte i = 0; i < el1.Length; i++)
        {
            result += el1[i] == '0' ? '1' : '0';
        }

        return result;
    }

    private static string Or(string el1,
                             string el2)
    {
        string result = string.Empty;

        for (byte i = 0; i < el1.Length; i++)
        {
            if (el1[i] == '1' || el2[i] == '1')
            {
                result += '1';
            }
            else
            {
                result += '0';
            }
        }

        return result;
    }

    private static string ConvertToD(string ip)
    {
        string result = string.Empty;
        string bits = string.Empty;
        int num;

        for (byte i = 0; i < ip.Length; i++)
        {
            bits += ip[i];

            if ((i + 1) % 8 == 0)
            {
                num = Convert.ToInt32(bits, 2);
                result += num.ToString();
                bits = string.Empty;

                if (i + 1 != 32)
                {
                    result += '.';
                }
            }
        }

        return result;
    }

    #endregion

    private enum IpClass
    {
        A,
        B,
        C,
        D,
        E,
        None
    }
    public record struct Info
    {
        public string IP { get; set; }
        public string Mask { get; set; }
        public string HostIp { get; set; }
        public string NetworkIp { get; set; }
        public string BroadcastIp { get; set; }

        public Info(string ip,
                    string mask,
                    string hostIp,
                    string networkIp,
                    string broadcastIp)
        {
            IP = ip;
            Mask = mask;
            HostIp = hostIp;
            NetworkIp = networkIp;
            BroadcastIp = broadcastIp;
        }
    }
}