using UnityEngine;

public class RotMouse : MonoBehaviour
{
    bool isRotating = false;
    Vector3 previousMousePosition;
    float rotationSpeed = 0.5f;
    public GameObject Amp;
    public GameObject Volt;
    bool Play;

    float minZ = 902.458f;
    float maxZ = 903.4f;


    public RunTest RunTest;

    float digitValue = 0;
    void OnEnable()
    {
        RunTest.OnPlayInstChanged += HandlePlayInstChanged;
    }

    void OnDisable()
    {
        RunTest.OnPlayInstChanged -= HandlePlayInstChanged;
    }

    void HandlePlayInstChanged(bool newValue)
    {

        Play = newValue;
    }
    void Update()
    {


        if (!GlobalGonfig.isSocket) return;
        if (Input.GetMouseButtonDown(0))
        {
            Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            if (Physics.Raycast(ray, out hit) && hit.transform == transform)
            {
                isRotating = true;
                previousMousePosition = Input.mousePosition;
            }
        }

        if (Input.GetMouseButtonUp(0))
        {
            isRotating = false;
        }

        if (isRotating && Play)
        {



            Vector3 currentMousePosition = Input.mousePosition;
            float deltaY = currentMousePosition.y - previousMousePosition.y;




            transform.Translate(Vector3.up * deltaY * rotationSpeed * Time.deltaTime);


            float newZ = Mathf.Clamp(transform.position.z, minZ, maxZ);
            transform.position = new Vector3(transform.position.x, transform.position.y, newZ);

            previousMousePosition = currentMousePosition;





            float res = deltaY * rotationSpeed;

            if (!GlobalGonfig.isHeart)
            {
                res *= 2f;
            }

            Amp.transform.Rotate(-Vector3.right, res);
            Volt.transform.Rotate(-Vector3.right, res);

            digitValue += deltaY / 20;

            previousMousePosition = currentMousePosition;
        }
    }
}
