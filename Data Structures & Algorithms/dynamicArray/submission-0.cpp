// Obviously don't use std vector for this :p
class DynamicArray {
public:

    int *v;
    int size = 0;
    int cap = 0;

    DynamicArray(int capacity) {
        v = new int[capacity];
        cap = capacity;
    }

    int get(int i) {
        // Problem mentions that the index is in range
        return v[i];
    }

    void set(int i, int n) {
        // Problem mentions that the index is in range
        v[i] = n;
    }

    void pushback(int n) {
        // std::cout << "debug if working" << endl;
        if (size == cap)
        {
            resize();
        }

        v[size++] = n;
    }

    int popback() {
        int x = v[--size];

        return x;
    }

    void resize() {
        int *v_new = new int[cap * 2];
        for (int i = 0; i < cap; ++i)
        {
            v_new[i] = v[i];
        }

        int *v_old = v;
        v = v_new;

        delete[] v_old;

        cap *= 2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
