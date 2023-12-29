using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotation_Quaternion : MonoBehaviour
{
    // Start is called before the first frame update

    private Quaternion _quaternion;
    private float angle;
    void Start()
    {
        _quaternion = transform.rotation;
    }

    // Update is called once per frame
    void Update()
    {
		angle++;

		// ���������� ���� �������� ������ ���� X � Z
		float xAngle = angle * Time.deltaTime;
		float zAngle = angle * Time.deltaTime * 1.5f;

		// ������� ��� ����������� ��� �������� ������ ���� X � Z
		Quaternion xRotation = Quaternion.AngleAxis(xAngle, Vector3.right);
		Quaternion zRotation = Quaternion.AngleAxis(zAngle, Vector3.forward);

		// ��������� ����� ���������� ��������
		Quaternion rotation = xRotation * zRotation;

		// ��������� ������� � �������
		transform.rotation = _quaternion * rotation;

	}
}
