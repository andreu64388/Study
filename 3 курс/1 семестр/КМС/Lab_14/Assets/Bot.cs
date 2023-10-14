using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bot : MonoBehaviour
{

	public float movespeed = 0.15f;
	public float rotspeedtank = 0.1f;
	public float rotspeedbash = 0.5f;
	public float speedcore = 3f;
	public Transform bash;
	public Transform stvol;
	public GameObject core;
	public bool canshoot = true;
	public int life = 3;

	private void OnTriggerStay(Collider other)
	{
		if (other.tag == "Player")
		{
			Vector3 relativePos = other.transform.position - transform.position;
			Quaternion newrot = Quaternion.LookRotation(relativePos) * Quaternion.AngleAxis(0, Vector3.up);
			bash.rotation = Quaternion.Slerp(bash.rotation, newrot, Time.deltaTime * rotspeedbash);
			RaycastHit hit;
			if (Physics.Raycast(bash.position, bash.TransformDirection(Vector3.forward), out hit))
			{
				if ((hit.transform.tag == "Player") && canshoot)
					StartCoroutine(botshoot());
			}
			float distance = Vector3.Distance(other.transform.position, transform.position);
			if (distance >  10 && distance < 20)
			{
				transform.rotation = Quaternion.Slerp(transform.rotation, newrot, Time.deltaTime * rotspeedtank);
				transform.position = Vector3.Lerp(transform.position, other.transform.position, Time.deltaTime * movespeed);
			}
		}
	}

	IEnumerator botshoot()
	{
		canshoot = false;
		Vector3 forwardofstvol = stvol.transform.position + stvol.TransformDirection(Vector3.forward * 12f);
		GameObject newcore = Instantiate(core, forwardofstvol, stvol.rotation);
		yield return new WaitForSeconds(2f);
		canshoot = true;
	}

	private void OnCollisionEnter(Collision collision)
	{
		
			Debug.Log(collision.gameObject.tag);
			if (collision?.gameObject?.tag !=null && collision?.gameObject?.tag=="core")
		{
			Debug.Log("BotCOre");
			life--;
			if (life < 1)
				Destroy(gameObject);

		}
	}
}

