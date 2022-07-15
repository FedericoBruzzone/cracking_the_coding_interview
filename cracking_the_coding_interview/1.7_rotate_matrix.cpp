#include "../ALL_H_FILES.h"

bool rotate(std::vector<std::vector<int>> matrix)
{
    if (matrix.size() == 0 || matrix.size() == 0 != matrix[0].size()) return false;

    int length = matrix.size();

    for (int layer = 0; layer < length / 2; layer++)
    {
        int first = layer;
        int last = length - 1 - layer;

        for (int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = matrix[first][i];

            // left -> top
            matrix[first][i] = matrix[last - offset][first];

            // bot -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            // right -> bot
            matrix[last][last - offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;

        }
    }
}