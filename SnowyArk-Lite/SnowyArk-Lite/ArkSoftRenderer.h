#pragma once
#include <initializer_list>

namespace Snowy::ArkLite
{
namespace Math // 数学库
{
//---------------------------------------------------------------------
// 数学库：矢量定义
//---------------------------------------------------------------------

// 通用矢量：N 是矢量维度，T 为数据类型
template <size_t N, typename T>
struct Vector
{
    using ValueType = T;    // 类型别名
    T value[N];             // 元素数组

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
    consteval size_t GetDimension() const // 获取向量维度
    {
        return N;
    }
};

// 特化二维矢量
template <typename T>
struct Vector<2, T>
{
    using ValueType = T;       // 类型别名
    union /* Anonymous */
    {
		struct { T x, y; };    // 元素别名
		struct { T u, v; };    // 元素别名
		T value[2];            // 元素数组
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