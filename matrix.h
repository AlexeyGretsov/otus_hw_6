#pragma once

#include <utility>
#include <vector>

namespace OtusHW {
/*
1. (+) Вектор для хранения реально существующих элементов
2. (+) Нормальный элемент m[10000][10000] = 42
3. Матрица предполагает возможность итерирования по std::tuple<size_t, size_t,
T>
4. (+) Удаление элемента через присваивание ему дефолтного элемента
5. (+) Функция size();
*/

template <typename T, T defVal> class Matrix {
  struct Item {
    /*
     * Первый параметр пары - индекс столбца
     */

    std::vector<std::pair<size_t, T>> values;

    T &operator[](size_t index) {
      for (auto &val : values) {
        if (val.first == index) {
          return val.second;
        }
      }

      std::pair<size_t, T> new_val{index, defVal};
      values.push_back(new_val);

      return values.back().second;
    }
  };

public:
  Item &operator[](size_t index) {
    for (auto &item : items) {
      if (item.first == index) {
        return item.second;
      }
    }

    std::pair<size_t, Item> new_item{index, Item{}};
    items.push_back(new_item);

    return items.back().second;
  }
  size_t size() {
    /*
     * Проверяем наличие объектов с дефлтными значениями. Если они присутствуют,
     * удаляем их
     */

    size_t count{0};
    for (auto &item : items) {
      auto &values = item.second.values;
      values.erase(std::remove_if(values.begin(), values.end(),
                                  [](std::pair<size_t, T> &v) {
                                    return v.second == defVal;
                                  }),
                   values.end());
      count += values.size();
    }
    items.erase(std::remove_if(items.begin(), items.end(),
                               [](std::pair<size_t, Item> &p) {
                                 return p.second.values.empty();
                               }),
                items.end());

    return count;
  }

private:
  /*
   * Первый параметр пары - индекс строки
   */
  std::vector<std::pair<size_t, Item>> items;
};
} // namespace OtusHW
