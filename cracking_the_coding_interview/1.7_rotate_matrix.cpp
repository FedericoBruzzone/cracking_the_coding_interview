#include "../ALL_H_FILES.h"

bool rotate(std::vector<std::vector<int>>& matrix)
{
    LOG(matrix.size());
    LOG(matrix[0].size());
    
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) return false;
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
    return true;
}

// bool rotate(std::vector<std::vector<int>> * matrix)
// {
//     //LOG(matrix.size());
//     //LOG(matrix[0].size());
//     if ((*matrix).size() == 0 || (*matrix).size() != matrix[0].size()) return false;
//     int length = (*matrix).size();

//     for (int layer = 0; layer < length / 2; layer++)
//     {
//         int first = layer;
//         int last = length - 1 - layer;

//         for (int i = first; i < last; i++)
//         {
//             int offset = i - first;

//             int top = (*matrix)[first][i];

//             // left -> top
//             (*matrix)[first][i] = (*matrix)[last - offset][first];

//             // bot -> left
//             (*matrix)[last - offset][first] = (*matrix)[last][last - offset];

//             // right -> bot
//             (*matrix)[last][last - offset] = (*matrix)[i][last];

//             // top -> right
//             (*matrix)[i][last] = top;

//         }
//     }
//     return true;
// }

int main()
{
    std::vector<std::vector<int>> matrix {{1,2,3,4},
                                          {2,3,4,5},
                                          {3,4,5,6},
                                          {4,5,6,7}};
    
    rotate(matrix);
    //rotate(&matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

        
    
}