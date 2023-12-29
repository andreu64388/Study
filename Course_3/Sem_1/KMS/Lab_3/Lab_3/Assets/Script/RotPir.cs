
using UnityEngine;
using System.Collections;
using UnityEngine.EventSystems;
public class RotPir : MonoBehaviour
{
    [SerializeField]
    private float rotationSpeed = 0.5f;

    [SerializeField]
    private GameObject Line;

    [SerializeField]
    private GameObject Pir;

    [SerializeField]
    private Camera mainCamera;

    bool isRotating = false;
    Vector3 previousMousePosition;

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            if (mainCamera != null)
            {
                Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
                if (Physics.Raycast(ray, 100))
                {
                    print("Hit something");
                }
                RaycastHit hit;
                if (Physics.Raycast(ray, out hit) && hit.transform == transform)
                {
                    isRotating = true;
                    previousMousePosition = Input.mousePosition;
                }
            }
        }

        if (Input.GetMouseButtonUp(0))
        {
            isRotating = false;
        }

        if (isRotating)
        {
            Vector3 currentMousePosition = Input.mousePosition;
            float deltaX = currentMousePosition.y - previousMousePosition.y;

            float PirRotation = Pir.transform.eulerAngles.x;

            if (PirRotation > 333)
            {
                PirRotation = 333;
            }

            transform.Rotate(-Vector3.forward, deltaX * rotationSpeed);

            Pir.transform.eulerAngles = new Vector3(PirRotation, Pir.transform.eulerAngles.y, Pir.transform.eulerAngles.z);

            Pir.transform.Rotate(Vector3.right, deltaX * rotationSpeed);

            Line.transform.position += new Vector3(0, 0, deltaX / 1500);

            previousMousePosition = currentMousePosition;
        }
    }
}
