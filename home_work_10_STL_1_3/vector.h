#pragma once

class str_error : public std::exception // ��������� ����������
{
public:
	str_error(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override
	{
		return message.c_str();     // �������� �� std::string ������ const char*
	}
private:
	std::string message;    // ��������� �� ������
};


template <class T>
class vector
{
private:
	T* arr = nullptr;
	int m_size{};
	int m_capacity{};


public:
	vector() {}

	~vector()
	{
		if (nullptr != arr)
		{
			delete[] arr;
		}
	}
	vector(vector& other) // ����������� �����������
	{
		m_size = other.m_size; // ����������� �����
		m_capacity = other.m_capacity;// ����������� �����
		arr = new T[other.m_capacity]; // �������� ���. ������� ����� �� �����������

		for (int i = 0; i < other.m_capacity; i++)
		{
			arr[i] = other.arr[i]; // ���������� �������
		}
	}


	int at(int index)
	{
		try
		{
			if ((index < 0) || (index >= m_size)) throw str_error("�������������� ������� ��������� ��������");
		}
		catch (const std::exception& ex) { std::cout << ex.what() << std::endl; }

		return arr[index];
	}

	void push_back(T value)
	{
		if (m_capacity == 0 && m_size == 0)
		{
			m_capacity++;
			arr = new T[m_capacity];
			arr[m_size] = value;
			m_size++;
		}

		else if (m_size < m_capacity)
		{
			arr[m_size] = value;
			m_size++;
		}
		else if (m_capacity > 0 && m_size > 0 && m_size == m_capacity)
		{
			T* arr_new = new T[m_capacity * 2];
			for (int i = 0; i < m_size; i++)
			{
				arr_new[i] = arr[i];
			};
			delete[] arr;
			arr = arr_new;
			arr[m_size] = value; 
			m_size++;
			m_capacity *= 2;

		}

	}
	const int size()
	{
		return m_size;
	};

	const int capacity()
	{
		return m_capacity;
	};


	vector& operator=(vector& other) // ���������� ��������� =
	{
		m_size = other.m_size; // ����������� �����
		m_capacity = other.m_capacity;// ����������� �����
		delete[] arr; // �������� ��������� ������������� �������
		arr = new T[m_capacity]; // �������� ���. ������� ����� �� �����������

		for (int i = 0; i < m_capacity; i++)
		{
			arr[i] = other.arr[i]; // ���������� �������
		}
		return *this;
	}
};
