





namespace laba_14;
class Program
{
    
    public static void Main()
    {

        try
        {

            Console.WriteLine("\n-----------------1------------------\n");
            
            #region 1

            Infomartion.PrintProssecor();

            #endregion


            Console.WriteLine("\n-----------------2------------------\n");
            
            #region 2

            Infomartion.PrintDomen();

            #endregion

            Console.WriteLine("\n-----------------3------------------\n");
            #region 3
            
            Infomartion.PrintTread();
            Thread.Sleep(3000);

            #endregion

            Console.WriteLine("\n-----------------4------------------\n");
            #region 4

            Infomartion.TwoThreads();

            Thread.Sleep(3000);
            Console.WriteLine("\n--------------------Text file--------------------\n");
            Infomartion.ReadFile();
            Console.WriteLine("\n--------------------------------------------------\n");

            #endregion
        }

        catch (Exception e)
        {
            Console.WriteLine("Exception: " + e.Message);
        }
    
      

    }
}