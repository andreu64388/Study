using System;
using System.Web;

namespace WebApplication1
{
	public class IISHandler4 : IHttpHandler
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

			try
			{
				int parmX = int.Parse(context.Request.QueryString["ParmX"]);
				int parmY = int.Parse(context.Request.QueryString["ParmY"]);

				int responseText = parmX + parmY;
				
				context.Response.ContentType = "text/plain";

				context.Response.Write(responseText);
			}
			catch(Exception ex)
			{
				context.Response.ContentType = "text/plain";
				context.Response.Write(ex.Message);
			}
		}

		#endregion
	}
}
