using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TrigBox : MonoBehaviour
{


	// Start is called before the first frame update
	public Light Point;
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{

	}

	private void OnTriggerEnter(Collider col)
	{
		if (col.name == "player") Point.enabled = true;
	}

	private void OnTriggerExit(Collider col)
	{
		if (col.name == "player") Point.enabled = false;
	}
}

