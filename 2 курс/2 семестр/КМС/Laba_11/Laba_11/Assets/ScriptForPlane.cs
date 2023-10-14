using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScriptForPlane : MonoBehaviour
{

	//ќбъ€вление переменных дл€ определени€ границ плоскости по ос€м X-Z
	float minX, maxX, minZ, maxZ, objY, objX, objZ, angle = 2f;

	void Start()

	{
		//ќбъ€вленение переменной типа MeshRenderer дл€ каркасной сетки плоскости
		MeshRenderer rend = gameObject.GetComponent<MeshRenderer>();


		//«адание значений дл€ границ плоскости с использованием конструкций 
		//bounds - свойство границы объекта 
		minX = rend.bounds.min.x;
		maxX = rend.bounds.max.x;
		minZ = rend.bounds.min.z;
		maxZ = rend.bounds.max.z;
		//ќбъ€вление переменных дл€ координат XYZ генерации объекта на сцене
		objY = gameObject.transform.position.y + 5;
	}

	// Update is called once per frame
	void Update()
	{
		objX = Random.Range(minX, maxX);
		objZ = Random.Range(minZ, maxZ);

		if (Input.GetKeyDown(KeyCode.Q))
		{
			GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
			cube.transform.position = new Vector3(objX, objY, objZ);
			cube.AddComponent<Rigidbody>();
		}

		if (Input.GetKeyDown(KeyCode.D))
		{
			Quaternion rotZ = Quaternion.AngleAxis(-1, new Vector3(0, 0, angle));
			transform.rotation *= rotZ;
		}

		if (Input.GetKeyDown(KeyCode.A))
		{
			Quaternion rotZ = Quaternion.AngleAxis(1, new Vector3(0, 0, angle));
			transform.rotation *= rotZ;
		}
	}
}
