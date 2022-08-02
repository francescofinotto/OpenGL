#pragma once
namespace MyGL
{

    template <class T>
    class Buffer
    {
    public:
        Buffer(size_t count)
            : count(count), data(new T[count])
        {
        }

        ~Buffer()
        {
            delete[] data;
        };

        T &operator[](size_t index)
        {
            return data[index];
        }

        size_t size()
        {
            return size;
        }

    private:
        T *data;
        size_t count;
    };

} // namespace MyGL