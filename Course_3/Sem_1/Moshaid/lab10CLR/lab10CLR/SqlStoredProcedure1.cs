using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

public partial class StoredProcedures
{
    [Microsoft.SqlServer.Server.SqlProcedure]
    public static void CalculateAverageWithoutMinMax(SqlString values, out double result)
    {
        result = 0;

        if (values.IsNull)
            return;

        string[] stringValues = values.Value.Split(',');

        if (stringValues.Length < 3)
            return;

        double sum = 0;
        double count = 0;

        for (int i = 0; i < stringValues.Length; i++)
        {
            if (double.TryParse(stringValues[i], out double currentValue))
            {
                sum += currentValue;
                count++;
            }
        }

        if (count > 2)
            result = sum / count;
    }
}
