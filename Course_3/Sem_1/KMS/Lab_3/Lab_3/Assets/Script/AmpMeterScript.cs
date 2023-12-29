using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AmpMeterScript : MonoBehaviour
{
    public float amplitude = 0.01f;
    public float frequency = 0.01f;
    public float rotationSpeed = 150f;

    private float timeCounter = 0f;
    public float minYRotation = -180f; 
    public float maxYRotation = 180.25f;
    void Update()
    {

        if (!GlobalGonfig.isSocket) return;


        if (!GlobalGonfig.isConstTok)
        {



            float deltaY = amplitude * Mathf.Sin(2 * Mathf.PI * frequency * timeCounter);
            transform.Rotate(-Vector3.right, deltaY * rotationSpeed * Time.deltaTime);
            timeCounter += Time.deltaTime;


           
        }
    }
}

