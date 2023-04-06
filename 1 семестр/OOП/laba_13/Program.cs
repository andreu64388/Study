using System.Xml.Linq;
using System.Xml.Serialization;
using System.Xml.XPath;
namespace laba_13;

class Program
{
      static void Main(string[] args)
    {
        try
        {    
            Console.WriteLine("Json\n\n");
            Serialization.JsonSerializion(new Test(name: "Andrey", mark: 4, time: 42));
            Serialization.JsonSerializion(new Test(name: "Andrey2", mark: 4, time: 42));
            Serialization.JsonDeserializion();

            Console.WriteLine("Xml\n\n");
            Serialization.XmlSerializion(new TestXml(name: "Andrey3", age: 32));
            Serialization.XmlDeserializion();


            Console.WriteLine("Binary\n\n");
            Serialization.BinarySerializion(new Test(name: "Andrey4", mark: 4, time: 42));
            Serialization.BinaryDeserializion();

            List<Test> tests = new List<Test>();
            tests.Add(new Test(name: "Andrey5", mark: 4, time: 42));
            tests.Add(new Test(name: "Andrey6", mark: 4, time: 42));
            tests.Add(new Test(name: "Andrey7", mark: 4, time: 42));

            List<TestXml> tests1 = new List<TestXml>();
            tests1.Add(new TestXml(name: "Andrey8", age: 32));
            tests1.Add(new TestXml(name: "Andrey9", age: 32));
            tests1.Add(new TestXml(name: "Andrey10", age: 32));
            
            Console.WriteLine("Json\n\n");
            SerializationCollection.JsonSerializion(tests);
            SerializationCollection.JsonDeserializion();

            Console.WriteLine("Xml\n\n");
            SerializationCollection.XmlSerializion(tests1);
            SerializationCollection.XmlDeserializion();

            Console.WriteLine("Binary\n\n");
            SerializationCollection.BinarySerializion(tests);
            SerializationCollection.BinaryDeserializion();

            //Используя XPath напишите два селектора для вашего XML документ
            Console.WriteLine("XPath");
            XPathDocument doc = new XPathDocument("datas.xml");
            foreach (XPathNavigator nav in doc.CreateNavigator().Select("ArrayOfTestXml/TestXml/Name"))
            {
                Console.WriteLine(nav.Value);

            }
            Console.WriteLine("Test age");
            //сделать запрос где возрас будет больше 19
            foreach (XPathNavigator nav in doc.CreateNavigator().Select("ArrayOfTestXml/TestXml[Age>19]/Name"))
                
            {
                Console.WriteLine(nav.Value);

            }
            /*Используя Linq to XML (или Linq to JSON) создайте новый xml (json) -
документ и напишите несколько запросов.
*/
            Console.WriteLine("Linq to XML");
            XDocument xdoc = XDocument.Load("datas.xml"); 
            var items = from xe in xdoc.Element("ArrayOfTestXml").Elements("TestXml")
                        where (int)xe.Element("Age") > 19
                        select new TestXml
                        {
                            Name = xe.Element("Name").Value,
                            Age = (int)xe.Element("Age")
                        };
            foreach (TestXml s in items)
                Console.WriteLine("{0} - {1}", s.Name, s.Age);
          
           



        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

    }
}

[Serializable]
[XmlRoot("TestXML")]
public class TestXml
{
  
    [XmlElement("Name")]
    public string Name { get; set; }
    [XmlElement("Age")]
    public int Age { get; set; }

  
    public TestXml()
    {

    }
    public TestXml(string name, int age)
    {
        Name = name;
        Age = age;
    }
}


/*
1. Что такое сериализация, десериализация?
2. Какие существуют форматы сериализации? Поясните структуру для 
каждого формата. Какие классы для работы с ними существуют в 
.NET?
3. Какие классы существуют в пространстве имен System.Xml?
4. Какие атрибуты используются для настройки XML сериализации?
5. В чем отличие BinaryFormatter или SoapFormatter?
6. Что такое сериализация контрактов данных, контракт данных?
7. Где и для чего используются атрибуты [OnSerializing], [OnSerialized], 
[OnDeserializing], [OnDeserialized]?
8. Что такое XPath? Приведите пример.
9. Какие возможности дает LINQ to Xml. Приведите примеры*/



//1. Что такое сериализация, десериализация?

//Сериализация - это процесс преобразования объекта в поток байтов, 

//десериализация - это процесс преобразования потока байтов в объект.

//2. Какие существуют форматы сериализации? Поясните структуру для
//каждого формата. Какие классы для работы с ними существуют в
//.NET?

//Существует 3 формата сериализации: BinaryFormatter, SoapFormatter, XmlSerializer.

//BinaryFormatter - сериализует объект в бинарный формат, который может быть прочитан только в том же приложении.

//SoapFormatter - сериализует объект в формат SOAP, который может быть прочитан в любом приложении, поддерживающем SOAP.

//XmlSerializer - сериализует объект в XML, который может быть прочитан в любом приложении, поддерживающем XML.

//3. Какие классы существуют в пространстве имен System.Xml?

//XmlDocument, XmlElement, XmlAttribute, XmlText, XmlComment, XmlCDataSection

//4. Какие атрибуты используются для настройки XML сериализации?

//XmlRootAttribute, XmlTypeAttribute, XmlElementAttribute, XmlAttributeAttribute, XmlArrayAttribute, XmlArrayItemAttribute


//5. В чем отличие BinaryFormatter или SoapFormatter?

//BinaryFormatter - сериализует объект в бинарный формат, который может быть прочитан только в том же приложении.

//SoapFormatter - сериализует объект в формат SOAP, который может быть прочитан в любом приложении, поддерживающем SOAP.


//6. Что такое сериализация контрактов данных, контракт данных?

//Сериализация контрактов данных - это процесс преобразования объекта в поток байтов,

//контракт данных - это описание данных, которые будут сериализованы.


/*7. Где и для чего используются атрибуты [OnSerializing], [OnSerialized], 
[OnDeserializing], [OnDeserialized]?*/


//Атрибут [OnSerializing] - вызывается перед сериализацией объекта.

//Атрибут [OnSerialized] - вызывается после сериализации объекта.

//Атрибут [OnDeserializing] - вызывается перед десериализацией объекта.

//Атрибут [OnDeserialized] - вызывается после десериализации объекта.


//8. Что такое XPath? Приведите пример.

//XPath - это язык запросов, который позволяет получить доступ к элементам XML документа.

//Пример: /bookstore/book[price>35.00]/title


//9. Какие возможности дает LINQ to Xml. Приведите примеры*/

//LINQ to XML - это язык запросов, который позволяет получить доступ к элементам XML документа.

//Пример: var books = from b in xdoc.Descendants("book") select b;

