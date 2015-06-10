/*
version0.1
*/

#include <math>

template <class A>
class Vector3
{
	public A x,y,z;
	
	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z){}
	Vector3(A nx, A ny, A nz) : x(nx), y(ny), z(nz){}
	
	Vector3 &operator =(const Vector3 &a)
	{
		x=a.x;
		y=a.y;
		z=a.z;
		return *this;
	}
	
	bool operator==(const Vector3 &a)const
	{
		return x==a.x && y==a.y && z==a.z;
	}
	
	bool operator!=(const Vector3 &a)const
	{
		return x!=a.x || y!=a.y || z!=a.z;
	}
	
	Vector3 operator-()const
	{
		return Vector3(-x,-y,-z);
	}
	
	Vector3 operator+(const Vector3 &a) const
	{
		return Vector3(x+a.x,y+a.y,z+a.z);
	}
	
	Vector3 operator-(const Vector3 &a)const
	{
		return Vector3(x-a.x,y-a.y,z-a.z);
	}
	
	Vector3 operator*(A a)const
	{
		return Vector3(x*a,y*a,z*a);
	}
	
	Vector3 operator/(A a)const
	{
		A temp = 1/a;
		return Vector3(x*temp,y*temp,z*temp);
	}
	
	Vector3 &operator+=(const Vector3 &a)
	{
		x+=a.x;
		y+=a.y;
		z+=a.z;
		return *this;
	}
	
	Vector3 &operator-=(const Vector3 &a)
	{
		x-=a.x;
		y-=a.y;
		z-=a.z;
		return *this;
	}
	
	Vector3 &operator*=(const A &a)
	{
		x*=a.x;
		y*=a.y;
		z*=a.z;
		return *this;
	}
	
	Vector3 &operator/=(const A &a)
	{
		A temp = 1/a;
		x*=temp;
		y*=temp;
		z*=temp;
		return *this;
	}
	
	//dot product
	A operator *(const Vector3 &a)const
	{
		return X*x+y*y+z*z;
	}
	
	void normalize()
	{
		A mag =x*x+y*y+z*z;
		if(mag>0)
		{
			A temp = 1/sqrt(mag);
			x*=temp;
			y*=temp;
			z*=temp;
		}
	}
	
	void zero()
	{
		x=y=z=0;
	}
};

template <class A>
inline A vectormag(const Vector3 &a)
{
	return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

//cross product
template <class A>
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b)
{
	return Vector3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

template <class A>
inline Vector3 operator*(A k, const Vector3 &v)
{
	return Vector3(k*v.x, k*v.y, k*v.z);
}

template <class A>
inline A distance(const Vector3 &a, const Vector3 &b)
{
	A dx=a.x-b.x;
	A dy=a.y-b.y;
	A dz=a.z-b.z;
	return sqrt(dx*dx+dy*dy+dz*dz);
}

extern const Vector3 kZeroVector;