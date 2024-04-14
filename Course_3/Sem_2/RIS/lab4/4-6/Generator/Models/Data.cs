using System;

namespace Models
{
    [Serializable]
    public class Data
    {
        public int Id { get; set; }
        public int CreatorNumber { get; set; }
        public string Time { get; set; }
        public bool ItNew { get; set; } = true;
    }
}