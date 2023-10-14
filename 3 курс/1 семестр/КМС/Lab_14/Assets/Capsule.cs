using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Capsule : MonoBehaviour
{
    // Start is called before the first frame update
   void Start()
  {

  }

  // Update is called once per frames
  void Update()
  {

  }

  public Light lightPoint;
  private void OnTriggerEnter(Collider collider)
  {
    if (collider.gameObject.name == "Tank")
    {
      lightPoint.intensity = 2;
    }
  }
}
