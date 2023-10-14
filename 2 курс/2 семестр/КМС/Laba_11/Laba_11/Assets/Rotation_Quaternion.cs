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

		// определяем углы поворота вокруг осей X и Z
		float xAngle = angle * Time.deltaTime;
		float zAngle = angle * Time.deltaTime * 1.5f;

		// создаем две кватернионы для вращения вокруг осей X и Z
		Quaternion xRotation = Quaternion.AngleAxis(xAngle, Vector3.right);
		Quaternion zRotation = Quaternion.AngleAxis(zAngle, Vector3.forward);

		// вычисляем общий кватернион поворота
		Quaternion rotation = xRotation * zRotation;

		// применяем поворот к объекту
		transform.rotation = _quaternion * rotation;

	}
}
