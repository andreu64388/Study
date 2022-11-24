
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using System.Text.Json;
using System.Xml.Serialization;

namespace laba_13;

#region Task 1 
/*1. Из лабораторной №4 выберите класс с наследованием и/или 
композицией/агрегацией для сериализации. Выполните 
сериализацию/десериализацию объекта используя форматы: 
a. Binary, 
b. SOAP, 
c. JSON, 
d. XML.*/

#endregion
static class Serialization 
{
    #region Fields Path
    
    private static string path_json = "data.json";
    private static string path_xml = "data.xml";
    private static string path_soap = "data.soap";
    private static string path_binary = "data.bin";

    #endregion

    #region Methods

    public static void JsonSerializion(Test test)
    {
        using StreamWriter sw = new StreamWriter(path_json, true);
        var data = JsonSerializer.Serialize(test);
        sw.WriteLine(data);
        
    }
    public static void JsonDeserializion()
    {
        using StreamReader sr = new StreamReader(path_json);
       
        var list = new List<Test>();
        while (!sr.EndOfStream)
        {
            var data = sr.ReadLine();
            var test = JsonSerializer.Deserialize<Test>(data);

            list.Add(test);   
            
        }
        foreach (var item in list)
        {
            Console.WriteLine(item);
        }





    }
    public static void XmlSerializion(TestXml test)
    {
      
        var formatter = new XmlSerializer(typeof(TestXml));
      
        using (FileStream fs = new FileStream(path_xml, FileMode.OpenOrCreate))
        {
            formatter.Serialize(fs, test);
        }


    }
    
    public static void XmlDeserializion()
    {
        var formatter = new XmlSerializer(typeof(TestXml));
        using (FileStream fs = new FileStream(path_xml, FileMode.Open))
        {
            TestXml test;
            test = (TestXml)formatter.Deserialize(fs);
            Console.WriteLine(test.Name);
            Console.WriteLine(test.Age);
            
        }
        
    }

    public static void SoapSerializion(Test test)
    {
        using FileStream fs = new FileStream(path_soap, FileMode.OpenOrCreate);
        var soapFormatter = new SoapFormatter();
        soapFormatter.Serialize(fs, test);
    }
    
    public static void SoapDeserializion()
    {
        using FileStream fs = new FileStream(path_soap, FileMode.OpenOrCreate);
        var soapFormatter = new SoapFormatter();
       
    }

    public static void BinarySerializion(Test test)
    {
        //серилизация в бинарный формат
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream fs = new FileStream(path_binary, FileMode.OpenOrCreate))
        {
            formatter.Serialize(fs, test);
        }
        
        


    }
    public static void BinaryDeserializion()
    {
        //де серилизация в бинарный формат
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream fs = new FileStream(path_binary, FileMode.OpenOrCreate))
        {
            Test test;
            test = (Test)formatter.Deserialize(fs);

            Console.WriteLine(test);
        }
        

    }

  

    #endregion

}

/*2. Создайте коллекцию (массив) объектов и выполните 
сериализацию/десериализацию – возможность сохранения и загрузки 
спсика объектов в/из файла. */
static class SerializationCollection
{
    #region Fields Path
    private static string path_json = "datas.json";
    private static string path_xml = "datas.xml";
    private static string path_soap = "datas.soap";
    private static string path_binary = "datas.bin";

    #endregion

    #region Consructor 


    #endregion
    #region Methods

    public static void JsonSerializion(List<Test> test)
    {


        using StreamWriter sw = new StreamWriter(path_json, true);
        var data = JsonSerializer.Serialize(test);
        sw.WriteLine(data);


    }
    
    public static void JsonDeserializion()
    {
        using StreamReader sr = new StreamReader(path_json);

        
        var data =  sr.ReadLine();
        var test = JsonSerializer.Deserialize<List<Test>>(data);

        var list = new List<Test>(test);


        foreach (var item in list)
        {
            Console.WriteLine(item);
        }
        //Используя  Linq to JSON) создайте новый xml (json) - документ и напишите несколько запросов
        //с использованием LINQ to JSON
        




    }
    
    public static void XmlSerializion(List<TestXml> test)
    {
        var formatter = new XmlSerializer(typeof(List<TestXml>));
    
        using (FileStream fs = new FileStream(path_xml, FileMode.OpenOrCreate))
        {
            formatter.Serialize(fs, test);
        }


    }

    public static void XmlDeserializion()
    {
        var formatter = new XmlSerializer(typeof(List<TestXml>));
        using (FileStream fs = new FileStream(path_xml, FileMode.Open))
        {
            List<TestXml> test;
            test = (List<TestXml>)formatter.Deserialize(fs);
            foreach (var item in test)
            {
                Console.WriteLine(item.Name);
                Console.WriteLine(item.Age);
            }

        }

    }

    public static void BinarySerializion(List<Test> test)
    {
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream fs = new FileStream(path_binary, FileMode.OpenOrCreate))
        {
            formatter.Serialize(fs, test);
        }

    }

    public static void BinaryDeserializion()
    {
        BinaryFormatter formatter = new BinaryFormatter();
        using (FileStream fs = new FileStream(path_binary, FileMode.OpenOrCreate))
        {
            List<Test> test;
            test = (List<Test>)formatter.Deserialize(fs);

            foreach (var item in test)
            {
                Console.WriteLine(item);
            }
        }

    }

    #endregion
}


/*Все сериализаторы должен реализовывать общий интерфейс. Выбор и 
использование сериализатора следует реализовать таким образом, чтобы 
добавление нового сериализатора не требовало изменения существующего 
кода*/
interface ISerialization
{
  void JsonSerializion(List<Test> test);

    void JsonDeserializion();

    
       
}







