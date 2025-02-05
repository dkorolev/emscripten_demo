#include <string>
#include <vector>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

std::string wasmVersion() {
  return "1.1";
}

int demoAdd(int a, int b) {
  return 100+a+b;
}

int demoMul(int a, int b) {
  return 100+a*b;
}

using std::vector;
void gameOfLife(vector<vector<int>>& board) {
  constexpr size_t Z = 0;
  constexpr size_t P = +1;
  constexpr size_t N = size_t(-1);
  struct DIJ final { size_t di, dj; };
  static constexpr DIJ dij[] = {
    { P, Z },
    { P, P },
    { Z, P },
    { N, P },
    { N, Z },
    { N, N },
    { Z, N },
    { P, N },
  };
  for (size_t i = 0; i < board.size(); ++i) {
    for (size_t j = 0; j < board[i].size(); ++j) {
      if (board[i][j] & 1) {
        for (auto [di, dj] : dij) {
          if (i + di < board.size() && j + dj < board[i].size()) {
            board[i + di][j + dj] += 2;
          }
        }
      }
    }
  }
  for (size_t i = 0; i < board.size(); ++i) {
    for (size_t j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == 6) {
        // birth, no cell, three neighbors
        board[i][j] = 1;
      } else if (board[i][j] & 1) {
        // keep living
        board[i][j] = (board[i][j] >= 4 && board[i][j] < 8) ? 1 : 0;
      } else {
        // no life
        board[i][j] = 0;
      }
    }
  }
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("wasmVersion", &wasmVersion);
  function("demoAdd", &demoAdd);
  function("demoMul", &demoMul);
  register_vector<int>("VectorInt");
  register_vector<std::vector<int>>("VectorVectorInt");
  function("gameOfLife", &gameOfLife);
}
