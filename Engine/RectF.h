#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float left, float right, float top, float bottom);
	RectF(const Vec2& top_left, const Vec2& bottom_right);
	RectF(const Vec2& top_left, float width, float height);
	bool IsOverlappingWith(const RectF& rect) const;
	bool IsContainedBy(const RectF& rect) const;
	bool Contains(const Vec2& point) const;
	static RectF FromCenter(const Vec2& center, float half_width, float half_height);
	RectF GetExpandedBy(float margin) const;
	Vec2 GetCenter() const;
public:
	float top;
	float bottom;
	float left;
	float right;

};