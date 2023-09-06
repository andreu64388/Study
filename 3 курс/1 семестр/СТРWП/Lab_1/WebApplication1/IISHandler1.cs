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
			string parmA = context.Request.QueryString["ParmA"];
			string parmB = context.Request.QueryString["ParmB"];
		
			string responseText = $"GET-Http-KAV:ParmA = {parmA},ParmB = {parmB}";
		
			context.Response.ContentType = "text/plain";

			context.Response.Write(responseText);
		}
		#endregion
	}
}