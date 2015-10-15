class animatedObject {};

class character: animatedObject {};

class playerCharacter: character {};

class spriteAnimationSet {
		/* 
		 * Total time the anim should take place for rendering.
		 * Either float secs or int msecs.
		 */
		float animationTime;
	};