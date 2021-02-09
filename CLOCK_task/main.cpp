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

    auto begin1 = std::chrono::steady_clock::now();
    sort(v_1);
    auto end1 = std::chrono::steady_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1);
    std::cout << "The first time: " << elapsed1.count() << " ms" << std::endl;

    auto begin2 = std::chrono::steady_clock::now();
    std::sort(v_2.begin(), v_2.end());
    auto end2 = std::chrono::steady_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);
    std::cout << "The second time: " << elapsed2.count() << " ms" << std::endl;

    system("pause");
    
    return 0;
}
