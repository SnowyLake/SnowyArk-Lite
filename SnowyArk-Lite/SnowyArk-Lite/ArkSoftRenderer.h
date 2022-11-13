#pragma once
#include <initializer_list>

namespace Snowy::ArkLite
{
namespace Math // ��ѧ��
{
//---------------------------------------------------------------------
// ��ѧ�⣺ʸ������
//---------------------------------------------------------------------

// ͨ��ʸ����N ��ʸ��ά�ȣ�T Ϊ��������
template <size_t N, typename T>
struct Vector
{
    using ValueType = T;    // ���ͱ���
    T value[N];             // Ԫ������

    Vector() 
    { 
        for (size_t i = 0; i < N; i++)
            value[i] = T();
    }
    Vector(const T* ptr)
    {
        for (size_t i = 0; i < N; i++)
            value[i] = ptr[i];
    }
    Vector(const Vector<N, T>& arg)
    {
        for (size_t i = 0; i < N; i++)
            value[i] = arg.value[i];
    }
    Vector(const std::initializer_list<T>& arg)
    {
        auto iter = arg.begin();
        for (size_t i = 0; i < N; i++)
            value[i] = *iter++;
    } 
    const T& operator[] (size_t i) const
    {
        assert(i < N);
        return value[i];
    }
    T& operator[] (size_t i)
    {
        assert(i < N);
        return value[i];
    }
    void LoadFromPointer(const T* ptr)
    {
        for (size_t i = 0; i < N; i++)
            value[i] = ptr[i];
    }
    void SaveToPointer(T* ptr)
    {
        for (size_t i = 0; i < N; i++)
            ptr[i] = value[i];
    }
    consteval size_t GetDimension() const // ��ȡ����ά��
    {
        return N;
    }
};

// �ػ���άʸ��
template <typename T>
struct Vector<2, T>
{
    using ValueType = T;       // ���ͱ���
    union /* Anonymous */
    {
		struct { T x, y; };    // Ԫ�ر���
		struct { T u, v; };    // Ԫ�ر���
		T value[2];            // Ԫ������
	};
    Vector() : x(T{}), y(T{}) {}
    Vector(T _x, T _y) : x(_x), y(_y) {}
    Vector(const Vector<2, T> &arg): x(arg.x), y(arg.y) {}
    Vector(const T* ptr) : x(ptr->x), y(ptr->x) {}
    const T& operator[] (size_t i) const { assert(i < 2); return value[i]; }
    T& operator[] (size_t i) { assert(i < 2); return value[i]; }
    void LoadFromPointer(const T* ptr) { for (size_t i = 0; i < 2; i++) value[i] = ptr[i]; }
    void SaveToPointer(T* ptr) { for (size_t i = 0; i < 2; i++) ptr[i] = value[i]; }

};

}





}

namespace ArkLite = Snowy::ArkLite; // rename