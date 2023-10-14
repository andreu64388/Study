using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotation_Rotate : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }
	public float rotateSpeed = 10f;
	// Update is called once per frame
	void Update()
	{
		transform.Rotate(0, rotateSpeed * Time.deltaTime,0);

	}
}
