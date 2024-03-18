#ifndef BRICK_WALL_HPP
#define BRICK_WALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget {
	public:
		BrickWall();
		~BrickWall();

		ATarget* clone() const;
};

#endif