using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class MoveObjectWithMouse : MonoBehaviour
{
    bool isMoving = false;
    Vector3 previousMousePosition;


    float objectPositionY = 0;

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit) && hit.transform == transform)
            {
                isMoving = true;
                previousMousePosition = Input.mousePosition;
            }
        }

        if (Input.GetMouseButtonUp(0))
        {
            isMoving = false;
        }

        if (isMoving)
        {
            Vector3 currentMousePosition = Input.mousePosition;
            float deltaY = currentMousePosition.y - previousMousePosition.y;

          
            transform.position = new Vector3(transform.position.x, objectPositionY, transform.position.z);

         
            previousMousePosition = currentMousePosition;
        }
    }

}

