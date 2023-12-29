    using System.Collections;
    using System.Collections.Generic;
    using UnityEngine;

    public class core : MonoBehaviour
    {
        // Start is called before the first frame update
      public float speedShell=1f;
      public GameObject explosion1;



      // Start is called before the first frame update
      void Start()
      {
        Destroy(gameObject, 5f);                                                                                                                                   // Удаляем
      }

      // Update is called once per frame
      void Update()
      {
        transform.position += transform.TransformDirection(Vector3.forward * speedShell);                                                                       // Вперед стрельба
      }

      private void OnCollisionEnter(Collision col)
      {
        if (col.gameObject.tag == "goal")
        {
            
                Instantiate(explosion1, gameObject.transform);
                GetComponent<Renderer>().enabled = false;
                col.gameObject.GetComponent<Renderer>().material.color = new Color(1, 0, 0);
                col.gameObject.GetComponent<AudioSource>().PlayOneShot(col.gameObject.GetComponent<AudioSource>().clip);
            
        }

      }
    }
