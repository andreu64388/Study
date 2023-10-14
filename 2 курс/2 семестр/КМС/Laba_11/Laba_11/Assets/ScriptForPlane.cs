using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScriptForPlane : MonoBehaviour
{

	//���������� ���������� ��� ����������� ������ ��������� �� ���� X-Z
	float minX, maxX, minZ, maxZ, objY, objX, objZ, angle = 2f;

	void Start()

	{
		//������������ ���������� ���� MeshRenderer ��� ��������� ����� ���������
		MeshRenderer rend = gameObject.GetComponent<MeshRenderer>();


		//������� �������� ��� ������ ��������� � �������������� ����������� 
		//bounds - �������� ������� ������� 
		minX = rend.bounds.min.x;
		maxX = rend.bounds.max.x;
		minZ = rend.bounds.min.z;
		maxZ = rend.bounds.max.z;
		//���������� ���������� ��� ��������� XYZ ��������� ������� �� �����
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
