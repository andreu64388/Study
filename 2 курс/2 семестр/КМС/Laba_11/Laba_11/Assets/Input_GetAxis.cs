using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Input_GetAxis : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
		float x = Input.GetAxis("Horizontal");
		float z = Input.GetAxis("Vertical");
		transform.Translate(x, 0, z);

		float mx = Input.GetAxis("Mouse Y");
		float my = Input.GetAxis("Mouse X");
		mx = Mathf.Clamp(mx, 0, 90);
		transform.Rotate(mx, my, 0);
	}
}
