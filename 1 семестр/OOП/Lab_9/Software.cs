
namespace Lab_9;
class Software
{
    #region Property 
    public string Name { get; set; }
    public string Version { get; set; }
    public string Developer { get; set; }
    public string License { get; set; }
    public string Language { get; set; }
    #endregion

    #region Constructor
    public Software(string name, string version, string developer, string license, string language)
    {
        Name = name;
        Version = version;
        Developer = developer;
        License = license;
        Language = language;
    }
    #endregion
    
    #region Methods 

    public override string ToString()
    {
        return $"Name: {Name}, Version: {Version}, Developer: {Developer}, License: {License}, Language: {Language}";
    }
    public override bool Equals(object obj)
    {
        if (obj is Software software)
        {
            return Name == software.Name && Version == software.Version && Developer == software.Developer && License == software.License && Language == software.Language;
        }
        return false;
    }
    public override int GetHashCode()
    {
        return Name.GetHashCode() ^ Version.GetHashCode() ^ Developer.GetHashCode() ^ License.GetHashCode() ^ Language.GetHashCode();
    }
    #endregion

}

