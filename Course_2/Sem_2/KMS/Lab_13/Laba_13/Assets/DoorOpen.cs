using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DoorOpen : MonoBehaviour
{
	// Start is called before the first frame update
	public GameObject R_door;
	public GameObject L_door;
	public GameObject Cube;
	public float OpenWidht;
	public float SpeedCubeRotate = 10;

	// Start is called before the first frame update
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{

	}

	private void OnTriggerEnter(Collider col)
	{
		if (col.name == "player")
		{
			L_door.transform.position += new Vector3(-OpenWidht, 0, 0);
			R_door.transform.position += new Vector3(OpenWidht, 0, 0);

		}
	}

	private void OnTriggerExit(Collider col)
	{
		if (col.name == "player")
		{

			L_door.transform.position += new Vector3(OpenWidht, 0, 0);
			R_door.transform.position += new Vector3(-OpenWidht, 0, 0);
		}

	}

	private void OnTriggerStay(Collider col)
	{
		if (col.name == "robot")
		{
			Cube.transform.Rotate(0, SpeedCubeRotate, 0);
			Cube.transform.RotateAround(Vector3.zero, Vector3.up, SpeedCubeRotate * Time.deltaTime);
		}

	}
}
