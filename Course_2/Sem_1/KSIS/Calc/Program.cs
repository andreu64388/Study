using System.Collections;

namespace lab6;

class Program
{
    static void Main(string[] args)
    {
        try
        {
            Console.WriteLine("Введите IP-адрес: ");
            string? IP = Console.ReadLine();

            Console.WriteLine("Введите маску: ");
            string? Mask = Console.ReadLine();

            IPM ipm = new(IP, Mask);

            Console.WriteLine($"Информация:\n" +
                              $"IP\t\t\t\t{ipm.IPInfo.IP}\n" +
                              $"Mask\t\t\t\t{ipm.IPInfo.Mask}\n" +
                              $"Network ID\t\t\t{ipm.IPInfo.NetworkIp}\n" +
                              $"Host ID\t\t\t\t{ipm.IPInfo.HostIp}\n" +
                              $"Broadcast IP\t\t\t{ipm.IPInfo.BroadcastIp}");

        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }

    }
}