using System;

namespace ContactRepository.Model;

public class Contact
{
    public Guid Id { get; set; }
    public string Name { get; set; }
    public string PhoneNumber { get; set; }
}