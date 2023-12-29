using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class Click : MonoBehaviour, IPointerClickHandler
{
	// Start is called before the first frame update
	void Start()
	{

	}

	// Update is called once per frame
	void Update()
	{

	}
	public void OnPointerClick(PointerEventData eventData)
	{
		float red = Random.Range(.0f, 1.0f);
		float green = Random.Range(.0f, 1.0f);
		float blue = Random.Range(.0f, 1.0f);
		Color col1 = new Color(red, green, blue);
		gameObject.GetComponent<Renderer>().material.color = col1;


		int force = 200;
		Vector3 target = eventData.pointerPressRaycast.worldPosition;
		Vector3 collid = Camera.main.transform.position;
		Vector3 distance = target - collid;
		distance = distance.normalized;
		gameObject.GetComponent<Rigidbody>().AddForceAtPosition(distance * force, target);
	}
}
