using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class muzzle : MonoBehaviour
{
    // Start is called before the first frame update
   public GameObject projectilePrefab; // Префаб снаряда
  public float gunLength = 1f; // Длина ствола
  public float projectileSpeed = 100f; // Скорость снаряда

  // Метод Update вызывается каждый кадр
  void Update()
  {
    // Проверяем нажатие клавиши Space для выполнения выстрела
    if (Input.GetMouseButtonDown(0))
    {
                                                                                                                                    
      Vector3 spawnPoint = transform.position + transform.forward * gunLength;

                                                                                                                                        // Сам заряд экземпляр                                                                              
      GameObject projectile = Instantiate(projectilePrefab, spawnPoint, transform.rotation);

      
      Rigidbody projectileRigidbody = projectile.GetComponent<Rigidbody>();

                                                                                                                                    // Задаем скорость снаряда в направлении ствола
      projectileRigidbody.velocity = transform.forward * projectileSpeed;

      gameObject.GetComponent<AudioSource>().PlayOneShot(gameObject.GetComponent<AudioSource>().clip);
    }
  }
}
