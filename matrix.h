#pragma once

#include <vector>
#include <utility>

namespace OtusHW {
	/*
	1. (+) Вектор для хранения реально существующих элементов
	2. (+) Нормальный элемент m[10000][10000] = 42
	3. Матрица предполагает возможность итерирования по std::tuple<size_t, size_t, T> 
	4. Удаление элемента через присваивание ему дефолтного элемента
	5. Функция size();
	*/

	template <typename T, T defVal>
	class Matrix{
		class Item{
			std::vector<std::pair<size_t, T>> values;

			public:
				T& operator[](size_t index) {
					for (auto &val : values)
					{
						if (val.first == index)
						{
							return val.second;
						}
					}

					std::pair<size_t, T> new_val{index, defVal};
					values.push_back(new_val);

					return values.back().second;
				}
		};


		public:
			Item& operator[](size_t index) {
				for (auto &item : items)
				{
					if (item.first == index)
					{
						return item.second;
					}
				}

				std::pair<size_t, Item> new_item{index, Item{}};
				items.push_back(new_item);

				return items.back().second;
			}

		private:
			  std::vector<std::pair<size_t, Item>> items;
	};
}
