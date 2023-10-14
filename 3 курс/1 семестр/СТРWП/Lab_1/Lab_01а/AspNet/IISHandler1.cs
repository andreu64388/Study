using System;
using System.Web;

namespace WebApplication1
{
	public class IISHandler1 : IHttpHandler
	{

		#region Члены IHttpHandler

		public bool IsReusable
		{
			
			get { return false; }
		}



		//https://localhost:44370/KAV?ParmA=aaa&ParmB=bbb
		public void ProcessRequest(HttpContext context)
		{

			try
			{
				string parmA = context.Request.QueryString["ParmA"];
				string parmB = context.Request.QueryString["ParmB"];
		
				string responseText = $"GET-Http-KAV:ParmA = {parmA},ParmB = {parmB}";
		
				context.Response.ContentType = "text/plain";

				context.Response.Write(responseText);
			}
			catch (Exception e)
			{
				context.Response.ContentType = "text/plain";
				context.Response.Write(e.Message);
			}
			
		}
		#endregion
	}
}