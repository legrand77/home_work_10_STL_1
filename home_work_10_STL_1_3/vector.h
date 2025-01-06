#pragma once

class str_error : public std::exception // обработка исключений
{
public:
	str_error(const std::string& message) : message{ message }
	{}
	const char* what() const noexcept override
	{
		return message.c_str();     // получаем из std::string строку const char*
	}
private:
	std::string message;    // сообщение об ошибке
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
	vector(vector& other) // конструктор копирования
	{
		m_size = other.m_size; // копирование полей
		m_capacity = other.m_capacity;// копирование полей
		arr = new T[other.m_capacity]; // создание дин. массива такой же размерности

		for (int i = 0; i < other.m_capacity; i++)
		{
			arr[i] = other.arr[i]; // заполнение массива
		}
	}


	int at(int index)
	{
		try
		{
			if ((index < 0) || (index >= m_size)) throw str_error("Некорректность индекса получения элемента");
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


	vector& operator=(vector& other) // перегрузка оператора =
	{
		m_size = other.m_size; // копирование полей
		m_capacity = other.m_capacity;// копирование полей
		delete[] arr; // удаление исходного динамического массива
		arr = new T[m_capacity]; // создание дин. массива такой же размерности

		for (int i = 0; i < m_capacity; i++)
		{
			arr[i] = other.arr[i]; // заполнение массива
		}
		return *this;
	}
};
