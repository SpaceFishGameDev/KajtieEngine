#pragma once
template<class T>
class List
{
public:
	int Size = 0;
	T* store;
	void Add(T storeValue) {
		store = new T[Size + 1];
		store[Size] = storeValue;
		Size += 1;
	}
	T& operator[] (int i) {
		if (i <= Size) {
			return store[i];
		}
		return store[0];
	}
};

class v2d
{
public:
	float x;
	float y;
	v2d(float x_ , float y_) {
		x = x_;
		y = y_;
	}
	v2d() {
		x = 0;
		y = 0;
	}
	void operator+(v2d pos)
	{
		x = pos.x + x;
		x = pos.x + y; 
	}
};

class Polygon
{
public:
	List<v2d> points;
	v2d Position = v2d(0,0);
	Polygon(v2d Pos, List<v2d> points_)
	{
		int i = 0;
		while (i <= points_.Size) {
			points.Add(points_[i]);
			++i;
		}
		Position = Pos;
		i = 0;
	}
	void render()
	{
		int i = 0;
		glBegin(GL_POLYGON);
		while (i <= points.Size) {
			glVertex2f(points[i].x + Position.x, points[i].y + Position.y);

			++i;
		}
	}
};

class EngineObject {
public:
	v2d Position;
	Polygon shape;
};