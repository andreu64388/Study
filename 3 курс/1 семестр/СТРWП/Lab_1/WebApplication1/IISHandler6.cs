using System;
using System.Web;

namespace WebApplication1
{
	public class IISHandler6 : IHttpHandler
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
			get { return true; }
		}

		public void ProcessRequest(HttpContext context)
		{
			HttpResponse res = context.Response;

			if (context.Request.HttpMethod == "GET")
			{
				res.ContentType = "text/html";
				res.WriteFile("./index_6.html");
			}
			else if (context.Request.HttpMethod == "POST")
			{
				res.Write(int.Parse(context.Request.Form["x"]) * int.Parse(context.Request.Form["y"]));
			}
		
			else
			{
				res.Write("Unknown request method");
			}
		}

		#endregion
	}
}
