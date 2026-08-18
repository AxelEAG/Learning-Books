#include <cstddef>
#include <optional>
#include <string>

// Hash table:
//	Resizing container that holds key value pairs, where the key is hashed 
//	into an index.
// Reqs:
//	* size, capacity, and array[]
//	* resize()
//	* hash()
//	* get() or []
//	* push()
//  * delete
//  * probing?

// TODO: Probing strategies, hash()

struct KeyVal
{
	std::string key;
	int value;
};

class HashTable
{
public:
	HashTable() {}

	void push(std::string_view key, int value)
	{
		if (m_size >= 0.7 * m_capacity)
			resize();

		m_array[index(key)] = KeyVal{ std::string{key}, value };
		++m_size;
	}

	std::optional<KeyVal>& get(std::string_view key)
	{
		return m_array[index(key)];
	}

private:
	void resize()
	{
		int oldCapacity = m_capacity;
		m_capacity *= 2;
		auto* array = new std::optional<KeyVal>[m_capacity];

		for (std::size_t i{ 0 }; i < oldCapacity; i++)
		{
			auto pair = m_array[i];
			if (!pair) continue;
			array[index(pair->key)] = pair;
		}

		delete[] m_array;
		m_array = array;
	}

	std::size_t index(std::string_view key)
	{
		std::size_t newI = hash(key) % m_capacity;

		newI = linearProbe(newI, key);
		return newI;
	}

	std::size_t linearProbe(std::size_t i, std::string_view key)
	{
		while (m_array[i] && m_array[i]->key != key)
			i = (i + 1) % m_capacity;

		return i;
	}


	// TODO:
	int hash(std::string_view key)
	{
		return 1;
	}


	std::optional<KeyVal>* m_array{};
	int m_size{ 1 };
	int m_capacity{ 1 };

};
