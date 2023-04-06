using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lec04LibN
{
	public partial class Logger : ILogger
	{

		private static readonly Logger instance = new Logger();

		private string LogFileName = string.Format(@"{0}/LOG{1}.txt", Directory.GetCurrentDirectory(), DateTime.Now.ToString("yyyyMMdd-HH-mm-ss"));

		private int countLog = 0;

		private string Title;
		public void log(string message)
		{
			countLog++;

			if (message == "START" || message == "STOP" || message == "INIT")
			{
				File.AppendAllText(LogFileName, countLog.ToString().PadLeft(6, '0') + '-' +
				DateTime.Now.ToString("dd.MM.yyyy HH:mm:ss") + "-" + message + " " + Title + '\n');
			}
			else
			{
				File.AppendAllText(LogFileName, countLog.ToString().PadLeft(6, '0') + '-' +
				DateTime.Now.ToString("dd.MM.yyyy HH:mm:ss") + "- INFO " + Title + " " + message + '\n');
			}

		}
		public void start(string title)
		{
			Title += title + ":";
			this.log("START");
		}

		public void stop()
		{
			Title = Title.Remove(Title.Length - 2, 2);
			this.log("STOP");
		}
		private Logger()
		{
			this.log("INIT");
		}

		public static ILogger create()
		{
			return instance;
		}
		public static ILogger Instance { get { return instance; } }


	}
}
