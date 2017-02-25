using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {
	public float acceleration;
	public float deceralation;
	public float jumpAcceleration;


	//Engine related
	private SpriteRenderer renderer;
	private Rigidbody2D rb;
	private BoxCollider2D collider;

	//GameObject related
	private float initialDrag;
	private float height;
	

	void Start () {
		renderer = GetComponent<SpriteRenderer>();	
		rb = GetComponent<Rigidbody2D>();		
		collider = GetComponent<BoxCollider2D>();
	
		initialDrag = rb.drag;
		height = collider.bounds.extents.y;

	}

	void Update () {
		Debug.Log(isGrounded());
		processInput();
	}

	void processInput(){
		processHMovement();
		processJump();
	}

	void processHMovement(){
		float horizontal = Input.GetAxis("Horizontal");
		
		if(horizontal != 0){
			rb.drag = initialDrag;
			rb.AddForce(new Vector3(horizontal*acceleration*Time.deltaTime, 0, 0));
		} else if(isGrounded())
			rb.drag = deceralation;
	}

	void processJump(){
		if(Input.GetButtonDown("Jump"))
			rb.AddForce(new Vector3(0, jumpAcceleration*Time.deltaTime, 0));
	}

	bool isGrounded(){
		return collider.IsTouchingLayers(LayerMask.NameToLayer("FloorLayer"));
	}

	void OnCollisionEnter2D(Collision2D collision){
		collision
		renderer.color = new Color(0.5f, 0.5f, 0.5f, 1f); //opaque grey
	}

	void OnCollisionExit2D(Collision2D collision){
		renderer.color = new Color(1f, 1f, 1f, 1f); //opaque grey
	}
}