#include "../../ALL_H_FILES.h"

// =============================================================

// First implementation
// void nullifyRaw(std::vector<std::vector<int>> ** m, int raw)
// {
//     for (int j = 0; j < (**m)[0].size(); j++)
//     {
//         (**m).at(raw).at(j) = 0;
//     }
// }

// void nullifyColumn(std::vector<std::vector<int>> ** m, int column)
// {
//     for (int i = 0; i < (**m)[0].size(); i++)
//     {
//         (**m).at(i).at(column) = 0;
//     }
// }

// void setZeros(std::vector<std::vector<int>> * m)
// {
//     std::vector<bool> raw ((*m).size());
//     std::vector<bool> column ((*m)[0].size());

//     for (int i = 0; i < (*m).size(); i++)
//     {
//         for (int j = 0; j < (*m).size(); j++)
//         {
//             if ((*m).at(i).at(j) == 0)
//             {
//                 raw.at(i) = true;
//                 column.at(j) = true;
//             }
//         }
//     }

//     for (int i = 0; i < raw.size(); i++)
//     {
//         if (raw.at(i)) 
//         {
//             nullifyRaw(&m, i);  
//         }
//     }

//     for (int j = 0; j < column.size(); j++)
//     {
//         if (column.at(j))
//         {
//             nullifyColumn(&m, j); 
//         } 
//     }
// }

// =============================================================

// Second implementation
void nullifyRaw(std::vector<std::vector<int>> ** m, int raw)
{
    for (int j = 0; j < (**m)[0].size(); j++)
    {
        (**m).at(raw).at(j) = 0;
    }
}

void nullifyColumn(std::vector<std::vector<int>> ** m, int column)
{
    for (int i = 0; i < (**m)[0].size(); i++)
    {
        (**m).at(i).at(column) = 0;
    }
}

void setZeros(std::vector<std::vector<int>> * m)
{
    bool rawHasZero = false;
    bool colHasZero = false;

    for (int j = 0; j < m->at(0).size(); j++)
    {
        if (m->at(0).at(j) == 0) 
        {
            rawHasZero = true;
            break;
        }
    }
    for (int i = 0; i < m->size(); i++)
    {
        if (m->at(i).at(0) == 0) 
        {
            colHasZero = true;
            break;
        }
    }

    for (int i = 1; i < m->size(); i++)
    {
        for (int j = 0; j < m->at(0).size(); j++)
        {
            if (m->at(i).at(j) == 0)
            {
                m->at(i).at(0) = 0;
                m->at(0).at(j) = 0;
            }
        }
    }

    for (int i = 1; i < m->size(); i++)
    {
        if (m->at(i).at(0) == 0) 
            nullifyRaw(&m, i);
    }

    for (int j = 1; j < m->at(0).size(); j++)
    {
        if (m->at(0).at(j) == 0) 
            nullifyColumn(&m, j);
    }

    if (rawHasZero) nullifyRaw(&m, 0);
    if (colHasZero) nullifyColumn(&m, 0);
}

// =============================================================

int main()
{
    std::vector<std::vector<int>> matrix {{1,2,3,4},
                                          {2,3,0,5},
                                          {3,4,5,6},
                                          {4,5,6,7}};

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    setZeros(&matrix);
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
}
