using System;
using System.Web;

namespace WebApplication1
{
	public class IISHandler2 : IHttpHandler
	{
		/// <summary>
		/// Вам потребуется настроить этот обработчик в файле Web.config вашего 
		/// веб-сайта и зарегистрировать его с помощью IIS, чтобы затем воспользоваться им.
		/// см. на этой странице: https://go.microsoft.com/?linkid=8101007
		/// </summary>
		#region Члены IHttpHandler

		public bool IsReusable
		{
			// Верните значение false в том случае, если ваш управляемый обработчик не может быть повторно использован для другого запроса.
			// Обычно значение false соответствует случаю, когда некоторые данные о состоянии сохранены по запросу.
			get { return false; }
		}


		
		public void ProcessRequest(HttpContext context)
		{
			try
			{
				string parmA = context.Request.QueryString["ParmA"];
				string parmB = context.Request.QueryString["ParmB"];

				string responseText = $"POST-Http-KAV:ParmA = {parmA},ParmB = {parmB}";

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
