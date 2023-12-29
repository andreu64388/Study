using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player : MonoBehaviour
{
	// Start is called before the first frame update
	public float speed = 50.0f;
	public float horizontalViewSpeed = 2.0f;


	// Start is called before the first frame update
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{
		float translation = Input.GetAxis("Vertical") * speed;
		float rotation = Input.GetAxis("Horizontal") * speed;

		// Make it move 10 meters per second instead of 10 meters per frame...
		translation *= Time.deltaTime;
		rotation *= Time.deltaTime;

		// Move translation along the object's z-axis
		transform.Translate(rotation, 0, translation);


		// Get the mouse delta. This is not in the range -1...1
		float h = horizontalViewSpeed * Input.GetAxis("Mouse X");

		transform.Rotate(0, h, 0);


	}
}
