using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CapEnd : MonoBehaviour
{
	// Start is called before the first frame update
	public float speedH = 2.0f;
	public float speedV = 2.0f;

	private float yaw = 0.0f;
	private float pitch = 0.0f;

	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{
		float x = Input.GetAxis("Horizontal");
		float z = Input.GetAxis("Vertical");
		transform.Translate(x * 0.1f, 0, 0.1f * z);

		yaw += speedH * Input.GetAxis("Mouse X");
		pitch -= speedV * Input.GetAxis("Mouse Y");

		transform.eulerAngles = new Vector3(pitch, yaw, 0.0f);
	}
}
