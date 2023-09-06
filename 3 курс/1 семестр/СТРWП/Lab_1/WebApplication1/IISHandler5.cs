using System;
using System.Web;

namespace WebApplication1
{
	public class IISHandler5 : IHttpHandler
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



		//https://localhost:44370/KAV5?X=3&Y=3
		public void ProcessRequest(HttpContext context)
		{
			HttpResponse res = context.Response;

			if (context.Request.HttpMethod == "GET")
			{
				res.ContentType = "text/html";
				res.WriteFile("./index_5.html");
			}
			else if (context.Request.HttpMethod == "POST")
			{
				int parmX = int.Parse(context.Request.QueryString["x"]);
				int parmY = int.Parse(context.Request.QueryString["y"]);

				int responseText = parmX * parmY;

				res.Write(responseText);
			}
			else
			{
				res.Write("Unknown request method");
			}
		}

		#endregion
	}
}
