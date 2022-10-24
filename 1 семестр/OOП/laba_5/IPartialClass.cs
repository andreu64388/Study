using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba_4;

partial class PartialClass
{
    #region Fielsd
    private string _name;
    private string _surname;
    #endregion

    #region Properties
    public string Name
    {
        get => _name;
        set => _name = value;
    }

    public string Surname
    {
        get => _surname;
        set => _surname = value;
    }
    #endregion

}



interface IPoint
{
    void Move();
}
struct Point : IPoint
{
    private int x;
    private int y;
    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    public int X
    {
        get => x;
        set => x = value;
    }

    public int Y
    {
        get => y;
        set => y = value;
    }

    public void Move()
    {
        throw new NotImplementedException();
    }

    public void Print()
    {
        Console.WriteLine($"{X}+{Y}={X+Y}");
    }


}
