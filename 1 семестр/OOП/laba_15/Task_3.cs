
namespace laba_15;

static class Task_3
{
    /*3. Создайте три задачи с возвратом результата и используйте их для 
выполнения четвертой задачи. Например, расчет по формуле*/

    public static int RandomFor10()
    {
        Random rndm = new Random();
        return rndm.Next(10);
    }
    public static int RandomFor20()
    {
        Random rndm = new Random();
        return rndm.Next(20);
    }
    public static int RandomFor30()
    {
        Random rndm = new Random();
        return rndm.Next(30);
    }
    public static int AverageValue(int value1, int value2, int value3)
    {
        return (value1 + value2 + value3) / 3;
    }

    


}
