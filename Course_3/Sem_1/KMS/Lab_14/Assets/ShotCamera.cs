using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShotCamera : MonoBehaviour
{
    // Start is called before the first frame update
public float pushForce = 10f;
  private Camera cam1;

  // Use this for initialization
  void Start()
  {
    cam1 = GetComponent<Camera>();
  }

  // Update is called once per frame
  void Update()
  {
    if (Input.GetMouseButtonDown(0))
    {
      Vector3 point = new Vector3(cam1.pixelWidth / 2, cam1.pixelHeight / 2 - 40, 0);
      Ray ray = cam1.ScreenPointToRay(point);

      RaycastHit hit;
      if (Physics.Raycast(ray, out hit))
      {

        string hitObject = hit.collider.gameObject.name;

        GameObject TargetObject = hit.collider.gameObject;
        Debug.Log(hitObject);

        Rigidbody hitRigidbody = TargetObject.GetComponent<Rigidbody>();

        if (hitObject == "goal1")
        {
          Vector3 pushDirection = TargetObject.transform.position - transform.position;
          hitRigidbody.AddForce(pushDirection.normalized * pushForce, ForceMode.Impulse);
        }
        if (hitObject == "goal2")
        {
          Vector3 pushDirection = TargetObject.transform.position - transform.position;
          hitRigidbody.AddForce(pushDirection.normalized * pushForce, ForceMode.Impulse);
        }
        if (hitObject == "goal3")
        {
          Vector3 pushDirection = TargetObject.transform.position - transform.position;
          hitRigidbody.AddForce(pushDirection.normalized * pushForce, ForceMode.Impulse);
        }

      }
    }
  }
}
