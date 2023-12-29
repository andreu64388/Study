using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using TelephoneDirectory.Domain.Entity;
using TelephoneDirectory.Models;

namespace Web_API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DictController : ControllerBase
    {
        private readonly IRepository<ContactEntity> _contactService;

        public DictController(IRepository<ContactEntity> contactService)
        {
            _contactService = contactService;
        }


        [HttpGet]
    
        public async Task<ActionResult<ContactEntity>> GetAll()
        {
            return Ok(await _contactService.GetAll());
        }

        [HttpPost]
        public async Task<ActionResult<ContactEntity>> Create(Contact contact)
        {

            try
            {
                ContactEntity contactEntity = new ContactEntity
                {
                    Id = Guid.NewGuid(),
                    Name = contact.Name,
                    PhoneNumber = contact.PhoneNumber,
                };

                await _contactService.Create(contactEntity);
                return Ok(contactEntity);
            }
            catch(Exception err)
            {
                return BadRequest(err.Message);
            }
        }


        [HttpPut]
        public async Task<ActionResult<ContactEntity>> Update(Contact contact)
        {

            try
            {
         
                ContactEntity contactEntity = new ContactEntity
                {
                    Id = contact.Id,
                    Name = contact.Name,
                    PhoneNumber = contact.PhoneNumber,
                };
                await _contactService.Update(contactEntity);

                return Ok(contactEntity);
            }
            catch (Exception err)
            {
                return BadRequest(err.Message);
            }
        }


        [HttpDelete("{id}")]
        public async Task<ActionResult<ContactEntity>> Remove(Guid id)
        {
            try
            {

                var contact = await _contactService.GetId((id));
      

                await _contactService.Remove(contact);
                return Ok("Delete sucsess");
            }
            catch (Exception err)
            {
                return BadRequest(err.Message);
            }
        }


      
        [HttpGet("{id}")]
        public async Task<ActionResult<ContactEntity>> GetOne(Guid id)
        {
            var contact = await _contactService.GetId(id);

            if (contact == null) return BadRequest("Not found");
            return Ok(contact);
        }
    }


    /*  public async Task<ActionResult> Removes([FromForm] string id)
        {
            try
            {
                // Преобразуйте строку `id` в тип Guid, если это необходимо
                if (!Guid.TryParse(id, out Guid contactId))
                {
                    return BadRequest("Некорректный формат идентификатора");
                }

                var contact = await _contactService.GetId(contactId);

                if (contact == null)
                {
                    return NotFound(); // Если контакт с указанным Id не найден
                }

                await _contactService.Remove(contact);

                return Ok("Delete success");
            }
            catch (Exception err)
            {
                return BadRequest(err.Message);
            }
        }
*/
}
