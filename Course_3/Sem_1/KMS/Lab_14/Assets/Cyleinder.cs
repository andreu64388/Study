using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cyleinder : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
  public GameObject green;
  private void OnTriggerExit(Collider other)
  {
    green.gameObject.GetComponent<Light>().intensity = 2;
  }
}
