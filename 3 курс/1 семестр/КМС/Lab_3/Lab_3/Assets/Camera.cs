using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
	[SerializeField]
	Transform targetPos;
	[SerializeField]
	int sensitivity = 3;
	[SerializeField]
	float scrollSpeed = 10f;
	[SerializeField]
	int maxDistance = 100;
	[SerializeField]
	int minDistance = 1;

	// Use this for initialization
	void Start()
	{
	}

	// Update is called once per frame
	void Update()
	{
		if (Input.GetMouseButton(1))
		{
			float y = Input.GetAxis("Mouse X") * sensitivity;
			if (y != 0)
			{
				transform.RotateAround(targetPos.position, Vector3.up, y);
			}
		}

		// ÄÂÈÆÅÍÈÅ ÊÀÌÅÐÛ Â ÑÒÎÐÎÍÛ ÊËÀÂÈØÀÌÈ Ñ ÎÃÐÀÍÈ×ÅÍÈßÌÈ ÏÎ ÐÀÇÌÅÐÀÌ ÏÎÌÅÙÅÍÈß
		float x = Input.GetAxis("Horizontal") / sensitivity; // êëàâèøè A, D
		if (x != 0)
		{
			Vector3 newpos = transform.position + transform.TransformDirection(new Vector3(x, 0, 0));
			if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
			{
				transform.position = newpos;
			}
		}

		// ÏÐÈÁËÈÆÅÍÈÅ È ÓÄÀËÅÍÈÅ ÊÀÌÅÐÛ Ê ÓÑÒÀÍÎÂÊÅ ÍÀ ÑÖÅÍÅ ÏÐÎÊÐÓÒÊÎÉ ÊÎËÅÑÀ ÌÛØÈ
		float z = Input.GetAxis("Mouse ScrollWheel") * scrollSpeed;
		if (z != 0)
		{
			Vector3 newpos = transform.position + transform.TransformDirection(Vector3.forward * z);
			if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
			{
				transform.position = newpos;
			}
		}
	}

	bool ControlDistance(float distance)
	{
		if (distance > minDistance && distance < maxDistance) return true;
		return false;
	}
}

