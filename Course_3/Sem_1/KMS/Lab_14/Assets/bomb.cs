using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bomb : MonoBehaviour
{
    // Start is called before the first frame update
   public GameObject prefab;



  // Start is called before the first frame update
  void Start()
  {
    
  }

  // Update is called once per frame
  void Update()
  {
    if (Input.GetKeyDown(KeyCode.E))
    {
      var maxX = transform.position.x + 10;
      var maxZ = transform.position.z + 10;
      var minX = transform.position.x - 10;
      var minZ = transform.position.z - 10;
      var heightY = transform.position.y + 20;

      GameObject bomb = GameObject.CreatePrimitive(PrimitiveType.Sphere);
      bomb.transform.localScale = new Vector3(2, 1, 1);

      bomb.transform.position = new Vector3(Random.Range(minX, maxX), heightY, Random.Range(minZ, maxZ));
      bomb.AddComponent<Rigidbody>();
      bomb.GetComponent<Rigidbody>().mass = 2000;
      bomb.GetComponent<Renderer>().material.color = Color.black;
    }
  }



  // Start is called before the first frame update
}
