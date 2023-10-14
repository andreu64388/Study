using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Box : MonoBehaviour
{
    // Start is called before the first frame update
   void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
  private void OnTriggerStay(Collider other)
  {
    transform.Rotate(0, Time.deltaTime * 40, 0);
  }
}
