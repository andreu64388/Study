using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScriptCamera : MonoBehaviour
{
	Camera camera;

	void Start()
	{
		camera = GetComponent<Camera>();
	}

	// Update is called once per frame
	void Update()
	{
		if (Input.GetMouseButtonDown(0))
		{
			Vector3 point = new Vector3(camera.pixelWidth / 2, camera.pixelHeight / 2, 0);
			Ray ray = camera.ScreenPointToRay(point);
			RaycastHit hit;
			if (Physics.Raycast(ray, out hit))
			{
				GameObject sphere = GameObject.CreatePrimitive(PrimitiveType.Sphere);
				Vector3 pos = hit.point;
				sphere.transform.position = pos;
			}
		}
	}
}
