using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RobotScript : MonoBehaviour
{
	// Start is called before the first frame update
	float speed = 0.03f;
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{
		if (Input.GetKey(KeyCode.E))
		{
			transform.position += new Vector3(0, 0, speed);
		}
		if (Input.GetKey(KeyCode.R))
		{
			transform.position += new Vector3(-speed, 0, 0);
		}
		if (Input.GetKey(KeyCode.T))
		{
			transform.position += new Vector3(0, 0, -speed);
		}
		if (Input.GetKey(KeyCode.Y))
		{
			transform.position += new Vector3(speed, 0, 0);
		}
	}
}
