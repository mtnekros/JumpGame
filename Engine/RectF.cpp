#pragma once
#include "RectF.h"

RectF::RectF(float left, float right, float top, float bottom)
	:
	top(top),
	left(left),
	bottom(bottom),
	right(right)
{
}

RectF::RectF(const Vec2& top_left, const Vec2& bottom_right)
	:
	RectF(top_left.x, bottom_right.x, top_left.y, bottom_right.y)
{
}

RectF::RectF(const Vec2& top_left, float width, float height)
	:
	RectF(top_left, Vec2(top_left.x + width, top_left.y + height))
{
}

bool RectF::IsOverlappingWith(const RectF& rect) const
{
	return
		left <= rect.right && right >= rect.left &&
		top <= rect.bottom && bottom >= rect.top;
}

bool RectF::IsContainedBy(const RectF & rect) const
{
	return top >= rect.top && bottom <= rect.bottom &&
		left >= rect.left && right <= rect.right;
}

RectF RectF::FromCenter(const Vec2 & center, float half_width, float half_height)
{
	const Vec2 half = { half_width, half_height };
	return RectF(center - half, center + half);
}

RectF RectF::GetExpandedBy(float margin) const
{
	return RectF(left - margin, right + margin, top - margin, bottom + margin);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2.0f, (top + bottom) / 2.0f);
}

