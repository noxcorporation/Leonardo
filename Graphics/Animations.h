class AnimatedObject {};

class Character: AnimatedObject {};

class PlayerCharacter: Character {};

class SpriteAnimationSet {
		/* 
		 * Total time the anim should take place for rendering.
		 * Either float secs or int msecs.
		 **/
		float animationTime;
};