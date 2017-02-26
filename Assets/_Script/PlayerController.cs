using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour {
	public float maxSpeed;
	public float jumpSpeed;


	//Engine related
	private SpriteRenderer renderer;
	private Rigidbody2D rb;
	private BoxCollider2D collider;


	void Start () {
		renderer = GetComponent<SpriteRenderer>();	
		rb = GetComponent<Rigidbody2D>();		
		collider = GetComponent<BoxCollider2D>();
	}

	void Update () {
		processInput();
	}

	void processInput(){
		processHMovement();
		processJump();
	}


	/*
	 * Processes Horizontal movement
	 */
	void processHMovement(){
		float horizontal = Input.GetAxis("Horizontal");
		rb.velocity = new Vector2(horizontal * maxSpeed, rb.velocity.y);
	}

	void processJump(){
		if(Input.GetButtonDown("Jump") && isGrounded())
			rb.velocity = new Vector2( rb.velocity.x, jumpSpeed);
	}

	bool isGrounded(){
		return collider.IsTouching(GameObject.FindGameObjectWithTag("Floor").GetComponent<Collider2D>());
	}

	void OnCollisionEnter2D(Collision2D collision){
		renderer.color = new Color(0.5f, 0.5f, 0.5f, 1f); //opaque grey
	}

	void OnCollisionExit2D(Collision2D collision){
		renderer.color = new Color(1f, 1f, 1f, 1f); //opaque grey
	}
}