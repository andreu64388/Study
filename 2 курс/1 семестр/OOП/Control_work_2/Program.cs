delegate int NumberChanger(int n);
class TestDelegate
{

    static int num = 10;
    public static int AddNum(int p)
    {
        ++num;
        return num;
    }
}

class Program
{
   public static void Main()
    {
        NumberChanger nc;
        NumberChanger nc1 = new NumberChanger(TestDelegate.AddNum);

        nc = nc1;
        Console.WriteLine(nc(5));
        

    }
}