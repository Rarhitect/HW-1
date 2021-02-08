#include <algorithm>
#include <iostream>
#include <vector>

void sort(std::vector < int > & v)
{
    for (std::size_t i = 0; i < v.size() - 1; ++i)
    {
        for (std::size_t j = i + 1; j < v.size(); ++j)
        {
            if (v[i] > v[j])
            {
                std::swap(v[i], v[j]);
            }
        }
    }
}

int main()
{
    const auto size = 10000U;

    std::vector < int > v(size, 0);

    for (std::size_t i = 0; i < v.size(); ++i)
    {
        v[i] = v.size() - i;
    }

    auto v_1 = v;
    auto v_2 = v;
    
//start1
    sort(v_1);
//finish1
    
//start2
    std::sort(v_2.begin(), v_2.end());
//finish2
    
    system("pause");

    return EXIT_SUCCESS;
}
