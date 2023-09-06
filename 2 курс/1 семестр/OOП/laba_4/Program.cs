class A { }
class B : A { }
class C : A { } //1
class Program4
{
    static void Main()
    {
        A one = new B(); //2
        A two = new C(); //3
        one = two; //4
        Console.WriteLine("few");
    }
}