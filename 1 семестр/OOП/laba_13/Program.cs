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