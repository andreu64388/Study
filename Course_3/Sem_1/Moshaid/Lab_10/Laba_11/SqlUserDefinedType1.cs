using System;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

[Serializable]
[SqlUserDefinedType(Format.UserDefined, IsByteOrdered = true, MaxByteSize = 8000)]
public struct PassportData : IBinarySerialize, INullable
{
    private string series;
    private int number;
    private bool isNull;

    public bool IsNull => isNull;

    public static PassportData Null => new PassportData { isNull = true };

    public string Series
    {
        get { return series; }
        set { series = value; }
    }

    public int Number
    {
        get { return number; }
        set { number = value; }
    }

    public void Read(System.IO.BinaryReader r)
    {
        // Чтение данных из потока
        if (r != null)
        {
            series = r.ReadString();
            number = r.ReadInt32();
        }
    }

    public void Write(System.IO.BinaryWriter w)
    {
        // Запись данных в поток
        if (w != null)
        {
            w.Write(series);
            w.Write(number);
        }
    }

    public override string ToString()
    {
        return isNull ? "NULL" : $"{series} {number}";
    }

    public static PassportData Parse(SqlString s)
    {
        if (s.IsNull)
            return Null;

        string[] parts = s.Value.Split(' ');

        if (parts.Length != 2)
            throw new ArgumentException("Invalid format. Use 'Series Number'.");

        PassportData passportData = new PassportData();
        passportData.Series = parts[0];
        passportData.Number = int.Parse(parts[1]);

        return passportData;
    }
}