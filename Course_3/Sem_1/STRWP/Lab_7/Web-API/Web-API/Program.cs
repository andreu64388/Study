using Microsoft.EntityFrameworkCore;
using TelephoneDirectory.Domain;
using TelephoneDirectory.Domain.Entity;
using TelephoneDirectory.Domain.Repository;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();

var connectionString = builder.Configuration.GetConnectionString("MSSQL");

builder.Services.AddDbContext<AppDbContext>(option =>
option.UseSqlServer(connectionString)
);

builder.Services.AddScoped<IRepository<ContactEntity>, ContactService>();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var app = builder.Build();


if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();