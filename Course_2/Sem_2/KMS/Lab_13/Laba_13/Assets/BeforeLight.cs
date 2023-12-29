using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BeforeLight : MonoBehaviour
{
	// Start is called before the first frame update
	public GameObject Cylinder;
	public float LightSpeedChange = 0.001f;
	public float SpedCylinderRotate = 1f;
	public Light Point1;
	public Light Point2;
	public Light Point3;
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
		Cylinder.transform.Rotate(0, SpedCylinderRotate, 0);

		if (Point1.intensity < 10) Point1.intensity += LightSpeedChange;
		else Point1.intensity = 0;

		if (Point2.intensity < 10) Point2.intensity += LightSpeedChange;
		else Point2.intensity = 0;

		if (Point3.intensity < 10) Point3.intensity += LightSpeedChange;
		else Point3.intensity = 0;


	}
}
