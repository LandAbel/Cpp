#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>
namespace nik
{

	template<typename T> 
	class vector //class T is lehet 
	{
	public:
		class iterator
		{
		public:
			iterator(T* const current);
			bool operator==(const iterator& other) const;
			bool operator!=(const iterator& other) const;
			iterator& operator++();
			iterator operator++(int);
			T operator*() const;
			T& operator*();
		private:
			T* mCurrent;

		};
		vector() = default;
		vector(const size_t size);
		vector(const size_t size, const T& value);
		vector(const std::initializer_list<T>& list);
		vector(const vector& other);
		~vector();

		vector& operator=(const vector& other);

		T operator[](const size_t index)const;
		T& operator[](const size_t index);

		size_t size() const;

		iterator begin();
		iterator end();


		//friend std::ostream& operator<<(std::ostream& outputStream, const vector& v);


	private:
		T* mData= nullptr;
		size_t mCapacity=0;
		size_t mSize=0;
	};
	template<typename T>
	T& vector<T>::iterator::operator*() 
	{
		return *mCurrent;
	}
	template<typename T>
	T vector<T>::iterator::operator*() const
	{
		return mCurrent;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::iterator::operator++(int)
	{
		iterator temp(mCurrent);
		++mCurrent;
		return temp;
	}

	template<typename T>
	typename vector<T>::iterator& vector<T>::iterator::operator++()
	{
		++mCurrent;
		return *this;
	}

	template<typename T>
	bool vector<T>::iterator::operator!=(const iterator& other) const
	{
		return !(*this == other);
	}

	template<typename T>
	bool vector<T>::iterator::operator==(const iterator& other) const
	{
		return mCurrent == other.mCurrent;
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::end()
	{
		return iterator(mData+mSize);
	}

	template<typename T>
	typename vector<T>::iterator vector<T>::begin()
	{
		return iterator(mData);
	}

	template<typename T>
	vector<T>::iterator::iterator(T* const current):mCurrent(current){}

	template<typename T>
	T& vector<T>::operator[](const size_t index) 
	{
		return mData[index];

	}

	template<typename T>
	T vector<T>::operator[](const size_t index) const
	{
		return mData[index];

	}

	template<typename T>
	size_t vector<T>::size() const
	{
		return mSize;
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& other) {
		if (this != &other)
		{
			delete[] mData;
			mData = new T[other.mCapacity];
			mCapacity = other.mCapacity;
			mSize = other.mSize;
			std::copy(other.mData, other.mData + other.mSize, mData);
		}
		return *this;
	}

	template<typename T>
	vector<T>::vector(const vector& other)
		:mData(new T[other.mCapacity])
		,mCapacity(other.mCapacity)
		,mSize(other.mSize)
	{
		std::copy(other.mData, other.mData + other.mSize, mData);
	}

	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& list):vector(list.size())
	{
		std::copy(list.begin(), list.end(), mData);
	}

	template<typename T>
	vector<T>::vector(const size_t size, const T& value)
		: vector(size)
	{
		std::fill(mData, mData + mSize, value);
		//for (auto& current:mData)
		//{
		//	current = value;
		//}	//csúnya megoldás
	}

	template<typename T>
	vector<T>::vector(const size_t size)
		: mData(new T[size])
		, mCapacity(size)
		, mSize(size)
	{
	}

	template<typename T>
	vector<T>::~vector()
	{
		delete[] mData;
	}
	
	//template<typename T> std::ostream& operator<<(std::ostream& outputStream, const vector<T>& v)
	//{
	//	std::string separator = "";
	//	for (const auto& current : v.mData)
	//	{
	//		outputStream << separator << current;
	//		separator = ", ";
	//	}
	//}
}
