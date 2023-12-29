using System;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

public partial class UserDefinedFunctions
{
    [Microsoft.SqlServer.Server.SqlFunction(DataAccess = DataAccessKind.Read)]
    public static double CalculateAverageWithoutx(SqlString values)
    {
        if (values.IsNull)
            return 0; 

        string[] stringValues = values.Value.Split(',');

        if (stringValues.Length < 3)
            return 0; 

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

        if (count > 0)
            return sum / count;
        else
            return 0; 
    }
}
