/************************************
 * Выполнил: Чепуштанов Е.П.        *
 * Группа: ПИ-231                   *
 * Лаба 4, вариант 25               *
 * https://onlinegdb.com/7F-r3g_ok  *
*************************************/

#include <iostream>

using namespace std;

/*функция, проверяющая седловая точка или нет*/
int saddle_point(int n, int m, int V[1000][1000], int IndexN, int IndexM) {
  int IndexLineSaddle, IndexColumnSaddle, MinLine, MaxColumn;
  
  MinLine = V[IndexN][0];
  MaxColumn = V[0][IndexM];
  
  for (IndexColumnSaddle = 0; IndexColumnSaddle < m; ++IndexColumnSaddle) {
    if (V[IndexN][IndexColumnSaddle] < MinLine) {
      MinLine = V[IndexN][IndexColumnSaddle];
    }
  }
  for (IndexLineSaddle = 0; IndexLineSaddle < n; ++IndexLineSaddle) {
    if (V[IndexLineSaddle][IndexM] > MaxColumn) {
      MaxColumn = V[IndexLineSaddle][IndexM];
    }
  }
  
  return (V[IndexN][IndexM] == MinLine && V[IndexN][IndexM] == MaxColumn ? 1 : 0);
  }

int V[1000][1000];

int main() {
  int Line, Column;
  cout << "Введите кол-во строк: ";
  cin >> Line;
  cout << "Введите кол-во столбцов: ";
  cin >> Column;
  
  /*цикл ввода элементов массива*/
  for (int IndexLineV = 0; IndexLineV < Line; ++IndexLineV) {
    for (int IndexColumnV = 0; IndexColumnV < Column; ++IndexColumnV) {
      cout << "Введите " << IndexColumnV + 1 << " элемент " << IndexLineV + 1 << " строки: ";
      cin >> V[IndexLineV][IndexColumnV];
    }
  }
  /*цикл вывода исходной матрицы на экран*/
  cout << "Исходная матрица: " << endl;
  for (int IndexLineV = 0; IndexLineV < Line; ++IndexLineV) {
    for (int IndexColumnV = 0; IndexColumnV < Column; ++IndexColumnV) {
      cout << V[IndexLineV][IndexColumnV] << "\t";
    }
    cout << endl;
  }
  /*цикл обработки массива и нахождения седловой точки*/
  for (int IndexLineV1 = 0; IndexLineV1 < Line; ++IndexLineV1) {
    for (int IndexColumnV1 = 0; IndexColumnV1 < Column; ++IndexColumnV1){
      if ( saddle_point(Line, Column, V, IndexLineV1, IndexColumnV1) == 1 ) {
        cout << "Одна из седловых точек находится в " << IndexLineV1 + 1 << " строке, " << IndexColumnV1 + 1 << " столбце";
        exit(0);
      }
    }
  }
  
  return 0;
}
