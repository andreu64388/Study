using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// для того, чтобы понимать, где находится вершина стека
namespace laba_3;
/*Класс - стек Stack.Дополнительно перегрузить следующие
операции: + - добавить элемент в стек; -- - извлечь элемент из
стека; true - проверка, пустой ли стек; > - копирование одного
стека в другой с сортировкой в возрастающем порядке.*/

 class Stack<T>

{

    #region Fields
    private T[] stack; // для хранения элементов стека
    private int top; // для хранения индекса вершины стека
    private int size; // для хранения размера стека
    #endregion

    #region Constructors
    public Stack(int size) 
    {

        this.size = size;
        stack = new T[size];
        top = -1; // стек пуст 
                 
                 

    }
    #endregion

    #region Properties
    public T[] AllElements 
    {
        get 
        {
            T[] allElements = new T[top+1];
            Array.Copy(stack, allElements, top + 1);
            return allElements;
        }
        
    }
    #endregion

    #region Methods
    
    /// <summary>
    /// Добавить элемент в стек
    /// </summary>
    public void Push(T item)
    {
        if (top == size - 1)
        {
            Console.WriteLine("Stack is full");
            return;
        }
        stack[++top] = item;
    }
    
    public static Stack<T> operator +(Stack<T> stack, T element)
    {
        stack.Push(element);
        return stack;
    }
   
    /// <summary>
    /// Извлечь элемент
    /// </summary>
    public T Pop()
    {
        if (top == -1)
        {
            Console.WriteLine("Stack is empty");
            return default(T);
  
        }
        return stack[top--];
    }

    public static Stack<T> operator --(Stack<T> stack)
    {
        stack.Pop();
        return stack;
    }

    public static bool operator true(Stack<T> stack)
    {
        if (stack.top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public static bool operator false(Stack<T> stack)
    {
        if (stack.top == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    public static Stack<T> operator >(Stack<T> stack1, Stack<T> stack2)
    {
        for (int i = 0; i < stack1.size; i++)
        {
            stack2.stack[i] = stack1.stack[i];
        }
        Array.Sort(stack2.stack);
        return stack2;
    }
    public static Stack<T> operator <(Stack<T> stack1, Stack<T> stack2)
    {
        for (int i = 0; i < stack1.size; i++)
        {
            stack2.stack[i] = stack1.stack[i];
        }
        Array.Sort(stack2.stack);
        Array.Reverse(stack2.stack);
        return stack2;
    }
    
    public int CountSentences()
    {
        int count = 0;
        for (int i = 0; i < stack.Length; i++)
        {
            if (
                stack[i].ToString().Contains(".") ||
                stack[i].ToString().Contains("!") ||
                stack[i].ToString().Contains("?")
                )
            {
                count++;
            }
         
        }
        return count;

    }
    public static T MiddleElement(Stack<T> stack)
    {
        int middle = stack.size / 2;
        return stack.stack[middle];
    }

    /// <summary>
    /// Вывод на экран
    /// </summary>
    public void Print()
    {
        for (int i = 0; i < top+1; i++)
        {
            Console.WriteLine(stack[i]);
        }
    }

    public void Pushs(params T[] elements)
    {
        foreach (T element in elements)
        {
            Push(element);
        }
    }
    #endregion



















}













