






class Program
{
    public static void Main()
    {


        int[] a = new int[2];


        int[,] b = new int[2, 2]
        {
            {1, 2},
            {3, 4}
        };
        
        for(int i = 0;i<b.GetLength(1);i++)
        {
            for (int j = 0; j < b.GetLength(0); j++)
            {
                Console.WriteLine(b[i, j]);
            }
        }
    }
    }






